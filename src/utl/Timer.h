//
// Created by devinchang on 2019/8/23.
//

#ifndef INC_315SERVER_TIME_H
#define INC_315SERVER_TIME_H

#include "TimeStamp.h"
#include <functional>
#include <memory>
#include "Acceptor.h"
#include "AtomicIntegerT.h"



// Timer是定时器的封装,用于表示时间事件
class Timer {
public:
    typedef std::function<void()> TimerCallback;

    Timer(const TimerCallback &cb, TimeStamp when, double interval):
         callback_(cb), expiration_(when), interval_(interval), repeat_(interval>0.0),
         sequence_(s_numCreated_.incrementAndGet()) {}

    void run() const {
        callback_();
    }

    TimeStamp expiration() const { return expiration_; }

    void restart(TimeStamp now);
    bool repeat() const { return repeat_; }
    // new add
    int64_t sequence() const { return sequence_; }
private:
    const TimerCallback callback_;
    TimeStamp expiration_;
    const double interval_;
    const bool repeat_;
    // 9/16 new add
    const int64_t sequence_;
    static AtomicInt64 s_numCreated_;
};

inline void Timer::restart(TimeStamp now) {
    if(repeat_){
        expiration_ = addTime(now, interval_);
    }
    else{
        expiration_ = TimeStamp::invalid();
    }
}

#endif //INC_315SERVER_TIME_H
