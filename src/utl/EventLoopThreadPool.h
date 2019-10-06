//
// Created by devinchang on 2019/9/16.
//

#ifndef INC_315SERVER_EVENTLOOPTHREADPOOL_H
#define INC_315SERVER_EVENTLOOPTHREADPOOL_H

#include <vector>
#include <functional>
#include <memory>
#include "Condition.h"
#include "Mutex.h"
#include "Thread.h"

class EventLoop;
class EventLoopThread;

class EventLoopThreadPool {
public:
    EventLoopThreadPool(EventLoop *baseLoop);
    ~EventLoopThreadPool();
    void setThreadNum(int numThreads) { numThreads_ = numThreads; }
    void start();
    EventLoop *getNextLoop();
private:
    EventLoop *baseLoop_;
    bool started_;
    int numThreads_;
    int next_;
    std::vector<std::unique_ptr<EventLoopThread>> threads_;
    std::vector<EventLoop*> loops_;
};


#endif //INC_315SERVER_EVENTLOOPTHREADPOOL_H
