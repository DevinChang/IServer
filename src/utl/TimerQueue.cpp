//
// Created by devinchang on 2019/8/25.
//

#include "TimerQueue.h"
#include "EventLoop.h"
#include "Timer.h"
#include "Timerld.h"

#include <sys/timerfd.h>

#include <stdint.h> // for uint64_t
#include <string.h>

#include "Log.h"

int createTimerfd(){
    // timerfd_create(int clockid, int flags) 生成一个定时器对象
    int timerfd = ::timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK | TFD_CLOEXEC);
    if(timerfd < 0)
        //printf("Failed in timerfd_create");
        LOG_SYSATAL << "Failed in timerfd_create";
    return timerfd;
}


/* struct timespec{
 *     time_t tv_sec;
 *     long tv_nsec;
 * }
 * struct itimerspec{
 *     struct timespec it_interval;  // Interval for periodic timer
 *     struct timespec it_value;     // Initial expiration
 * }
 * */

struct timespec howMuchTimeFromNow(TimeStamp when){
    int64_t microseconds = when.microSecondSinceEpoch() - TimeStamp::now().microSecondSinceEpoch();
    if(microseconds < 100)
        microseconds = 100;
    static timespec ts;
    ts.tv_sec = static_cast<time_t>(microseconds / TimeStamp::kMicroSecondsPerSecond);
    ts.tv_nsec = static_cast<long>((microseconds % TimeStamp::kMicroSecondsPerSecond) % 1000);
    return ts;
}

void readTimerfd(int timerfd, TimeStamp now){
    /* uint8_t  表示1字节
    /* uint16_t 表示2字节
    /* uint32_t 表示4字节
    /* uint64_t 表示8字节
     * */
    uint64_t howmany;
    ssize_t n = ::read(timerfd, &howmany, sizeof(howmany));
    //printf("")
    LOG_TRACE << "TimerQueue::handleRead() " << howmany << " at " << now.toString();
    if(n != sizeof(howmany))
        LOG_ERROR << "TimerQueue::handleRead() reads " << n << " bites instead of 8";
}

void resetTimerfd(int timerfd, TimeStamp expiration){
    struct itimerspec newValue;
    struct itimerspec oldValue;
    //bzero(&newValue, sizeof(newValue));
    //bzero(&oldValue, sizeof(oldValue));
    memset(&newValue, 0, sizeof(newValue));
    memset(&oldValue, 0, sizeof(oldValue));
    newValue.it_value = howMuchTimeFromNow(expiration);
    int ret = ::timerfd_settime(timerfd, 0, &newValue, &oldValue);
    if(ret)
        //printf("timerfd_settime()");
        LOG_SYSERR << "timerfd_settime()";
}

TimerQueue::TimerQueue(EventLoop *loop)
             : loop_(loop), timerfd_(createTimerfd()),
               timerfdChannel_(loop, timerfd_), timers_(){
    timerfdChannel_.setReadCallback(std::bind(&TimerQueue::handleRead, this));
    timerfdChannel_.enableReading();
}

TimerQueue::~TimerQueue() {
    //timerfdChannel_.disableAll();
    //timerfdChannel_.remove();
    ::close(timerfd_);
    for(const Entry &timer : timers_)
        delete timer.second;
}

// 8/31 modify: addTimer只负责转发
Timerld TimerQueue::addTimer(const std::function<void()> &cb, TimeStamp when, double interval) {
    //Timer *timer = new Timer(std::move(cb), when, interval);
    //loop_->runLoop(std::bind(&TimerQueue::addTimerInLoop, this, timer));
    //return Timerld(timer, timer->sequence());
    Timer *timer = new Timer(std::move(cb), when, interval);
    //loop_->assertInLoopThread();
    //bool earliestChanged = insert(timer);
    //if(earliestChanged){
    //    resetTimerfd(timerfd_, timer->expiration());
    //}

    // 8/30 new add
    loop_->runInLoop(std::bind(&TimerQueue::addTimerInLoop, this, timer));
    return Timerld(timer);
}

// 8/30 new add : addTimerInLoop完成修改定时器的工作
void TimerQueue::addTimerInLoop(Timer *timer){
    loop_->assertInLoopThread();
    bool earliestChanged = insert(timer);
    if(earliestChanged){
        resetTimerfd(timerfd_, timer->expiration());
    }
}

void TimerQueue::handleRead() {
    loop_->assertInLoopThread();
    TimeStamp now(TimeStamp::now());
    readTimerfd(timerfd_, now);

    std::vector<Entry> expired = getExpired(now);

    // 9/26 new add
    callingExpiredTimers_ = true;
    cancelingTimers_.clear();

    for(auto it = expired.begin(); it != expired.end(); ++it){
        it->second->run();
    }

    // 9/26 new add
    callingExpiredTimers_ = false;
    reset(expired, now);
}

// 函数会从timers_中移除已到期的Timer,并通过vector返回
std::vector<TimerQueue::Entry> TimerQueue::getExpired(TimeStamp now) {
    std::vector<Entry> expired;
    // UINTPTR_MAX UINT16_MAX
    Entry sentry = std::make_pair(now, reinterpret_cast<Timer*>(UINTPTR_MAX));
    // 选取第一个未到期的Timer迭代器
    auto it = timers_.lower_bound(sentry);
    assert(it == timers_.end() || now < it->first);
    std::copy(timers_.begin(), it, back_inserter(expired));
    timers_.erase(timers_.begin(), it);
    return expired;
}


void TimerQueue::reset(const std::vector <Entry> &expired, TimeStamp now) {
    TimeStamp nextExpire;
    for(auto it = expired.begin(); it != expired.end(); ++it){
        // 9/26 new add
        ActiveTimer timer(it->second, it->second->sequence());
        //if(it->second->repeat()){
        if(it->second->repeat() && cancelingTimers_.find(timer) == cancelingTimers_.end()){
            it->second->restart(now);
            insert(it->second);
        }
        else{
            delete it->second;
        }
    }
    if(!timers_.empty()){
        nextExpire = timers_.begin()->second->expiration();
    }
    if(nextExpire.valid()){
        resetTimerfd(timerfd_, nextExpire);
    }
}


bool TimerQueue::insert(Timer *timer) {
    loop_->assertInLoopThread();
    assert(timers_.size() == activeTimers_.size());
    bool earliestChanged = false;
    TimeStamp when = timer->expiration();
    auto it = timers_.begin();
    if(it == timers_.end() || when < it->first)
        earliestChanged = true;
    {
        std::pair<TimerList::iterator, bool> result = timers_.insert(std::make_pair(when, timer));
        assert(result.second);
        (void) result;
    }
    {
        std::pair<ActiveTimerSet::iterator, bool> result = activeTimers_.insert(ActiveTimer(timer, timer->sequence()));
        assert(result.second); (void)result;
    }
    assert(timers_.size() == activeTimers_.size());
    return earliestChanged;
}


void TimerQueue::cancel(Timerld timerld) {
    loop_->runInLoop(std::bind(&TimerQueue::cancelInLoop, this, timerld));
}

//void TimerQueue::cancelInLoop(Timerld timerld){
//    loop_->assertInLoopThread();
//    assert(timers_.size() == activeTimers_.size());
//    ActiveTimer timer(timerld.timer_, timerld.sequence_);
//}



void TimerQueue::cancelInLoop(Timerld timerld) {
    loop_->assertInLoopThread();
    assert(timers_.size() == activeTimers_.size());
    ActiveTimer timer(timerld.timer_, timerld.sequence_);
    ActiveTimerSet::iterator it = activeTimers_.find(timer);
    if(it != activeTimers_.end()){
        size_t n = timers_.erase(Entry(it->first->expiration(), it->first));
        assert(n == 1); (void)n;
        delete  it->first;
        activeTimers_.erase(it);
    }
    else if(callingExpiredTimers_){
        cancelingTimers_.insert(timer);
    }
    assert(timers_.size() == activeTimers_.size());
}


