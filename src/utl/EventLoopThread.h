//
// Created by devinchang on 2019/8/31.
//

#ifndef INC_315SERVER_EVENTLOOPTHREAD_H
#define INC_315SERVER_EVENTLOOPTHREAD_H

#include "Mutex.h"
#include "Thread.h"
#include "Condition.h"


class EventLoop;


class EventLoopThread {
public:
    EventLoopThread();
    ~EventLoopThread();

    EventLoop *startLoop();
private:
    void threadFunc();
    EventLoop *loop_;
    bool exiting_;
    Thread thread_;
    MutexLock mutex_;
    // condition
    Condition cond_;
};


#endif //INC_315SERVER_EVENTLOOPTHREAD_H
