//
// Created by devinchang on 2019/8/25.
//

#ifndef INC_315SERVER_TIMERQUEUE_H
#define INC_315SERVER_TIMERQUEUE_H

#include "utl.h"

#include "TimeStamp.h"
#include "Mutex.h"
#include "Channel.h"


class EventLoop;
class Timer;
class Timerld;

// TimerQueue表示定时器的处理流程的封装
class TimerQueue {
public:
    typedef std::function<void()> TimerCallback;

    TimerQueue(EventLoop *loop);
    ~TimerQueue();

    Timerld addTimer(const TimerCallback &cb, TimeStamp when, double interval);

    // 9/16 new add
    void cancel(Timerld timerld);
private:
    typedef std::pair<TimeStamp, Timer*> Entry;
    typedef std::set<Entry> TimerList;
    // new add
    typedef std::pair<Timer*, int64_t> ActiveTimer;
    typedef std::set<ActiveTimer> ActiveTimerSet;

    // 当timerfd触发时调用
    void handleRead();
    //
    std::vector<Entry> getExpired(TimeStamp now);
    void reset(const std::vector<Entry> &expired, TimeStamp now);

    bool insert(Timer *timer);

    // 8/31 new add
    void addTimerInLoop(Timer *timer);

    // 9/16 new add
    void cancelInLoop(Timerld timerld);

    EventLoop *loop_;
    const int timerfd_;
    Channel timerfdChannel_;
    TimerList timers_;

    // 9/26 new add
    bool callingExpiredTimers_;
    ActiveTimerSet activeTimers_;
    ActiveTimerSet cancelingTimers_;
};


#endif //INC_315SERVER_TIMERQUEUE_H
