//
// Created by devinchang on 2019/8/17.
//

#include "EventLoop.h"
#include <poll.h>
#include <cassert>
#include "Channel.h"
//#include "Poller.h"
#include "EPoller.h"
#include "TimerQueue.h"
#include <signal.h>
#include <sys/eventfd.h>
#include "Log.h"



__thread EventLoop *t_loopInThisThread = 0;
// poll等待超时的时间
const int kPollTimeMs = 10000;

static int createEventfd(){
    // int eventfd(unsigned int initval, int flags)
    // 用来触发事件通知
    int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
    if(evtfd < 0){
        // debug
        //printf("Failed in eventfd");
        LOG_SYSERR << "Failed in eventfd";
        abort();
    }
    return evtfd;
}

EventLoop::EventLoop(): looping_(false), threadid_(CurrentThread::tid()),
                      quit_(false), callingPendingFunctors_(false),
                      poller_(new EPoller(this)), timerQueue_(new TimerQueue(this)),
                      wakeupFd_(createEventfd()), wakeupChannel_(new Channel(this, wakeupFd_))
{
    LOG_TRACE << "EventLoop Created " << this << "in thread " << threadid_;
    if(t_loopInThisThread){
        // log
        LOG_FATAL << "Another EventLoop " << t_loopInThisThread << " exists in this thread " << threadid_;
    }
    else{
        t_loopInThisThread = this;
    }
    // 8/30 new add
    wakeupChannel_->setReadCallback(std::bind(&EventLoop::handleRead, this));
    wakeupChannel_->enableReading();
}

void EventLoop::handleRead() {
    uint64_t one = 1;
    ssize_t n = ::read(wakeupFd_, &one, sizeof(one));
    if(n != sizeof(one)){
        //printf("EventLoop::handleRead() reads %d bytes instead of 8", n);
        LOG_ERROR << "EventLoop::handleRead() reads " << n << " bytes instead of 8";
    }

}

EventLoop::~EventLoop(){
    assert(!looping_);
    // 8/30 new add
    ::close(wakeupFd_);

    t_loopInThisThread = nullptr;
}

void EventLoop::loop(){
    // 检查事件循环是否在IO线程中
    assert(!looping_);
    assertInLoopThread();
    looping_ = true;
    // 8/20 new add
    quit_ = false;

    while(!quit_){
        activeChannels_.clear();
        pollReturnTime_ = poller_->poll(kPollTimeMs, &activeChannels_);
        for(auto it = activeChannels_.begin(); it != activeChannels_.end(); ++it){
            (*it)->handleEvent(pollReturnTime_);
        }
        doPendingFunctors();
    }

    LOG_TRACE << "EventLoop " << this << " stop looping";

    // 等待五秒
    //::poll(NULL, 0, 5*1000);
    looping_ = false;
}






void EventLoop::abortNotInLoopThread(){
    // do some work
    LOG_FATAL << "EventLoop:abortNotInLoopThread-EventLoop " << this
              << " was created in threadId_ =  " << threadid_ << ", current thread Id = "
              << CurrentThread::tid();
}


void EventLoop::quit() {
    quit_ = true;
    if(!isInLoopThread()){
        wakeup();
    }
}

void EventLoop::runInLoop(const std::function<void()> &cb) {
    if(isInLoopThread()){
        cb();
    }
    else{
        queueInLoop(cb);
    }
}

void EventLoop::queueInLoop(const std::function<void()> &cb) {
    {
        MutexLockGuard lock(mutex_);
        pendingFunctors_.push_back(cb);
    }
    if(!isInLoopThread() || callingPendingFunctors_)
        wakeup();
}



void EventLoop::updateChannel(Channel *channel) {
    assert(channel->ownerLoop() == this);
    assertInLoopThread();
    poller_->updateChannel(channel);
}

Timerld EventLoop::runAt(const TimeStamp &time, const std::function<void()> &cb) {
    return timerQueue_->addTimer(cb, time, 0.0);
}

Timerld EventLoop::runAfter(double delay, const std::function<void()> &cb) {
    TimeStamp time(addTime(TimeStamp::now(), delay));
    return runAt(time, cb);
}

Timerld EventLoop::runEvery(double interval, const std::function<void()> &cb) {
    TimeStamp time(addTime(TimeStamp::now(), interval));
    return timerQueue_->addTimer(cb, time, interval);
}

void EventLoop::wakeup() {
    uint64_t one = 1;
    ssize_t n = ::read(wakeupFd_, &one, sizeof(one));
    if(n != sizeof(one))
        //printf("EventLoop::handleRead() reads %d bytes instead of 8", n);
        LOG_ERROR << "EventLoop:wakeup() writes " << n << " bytes instead of 8";

}

void EventLoop::doPendingFunctors() {
    std::vector<Functor> functors;
    callingPendingFunctors_ = true;
    {
        MutexLockGuard lock(mutex_);
        functors.swap(pendingFunctors_);
    }
    for(size_t i = 0; i < functors.size(); ++i){
        functors[i]();
    }
    callingPendingFunctors_ = false;
}

void EventLoop::removeChannel(Channel *channel) {
    assert(channel->ownerLoop() == this);
    assertInLoopThread();
    poller_->removeChannel(channel);
}

void EventLoop::cancel(Timerld timerld) {
    return timerQueue_->cancel(timerld);
}