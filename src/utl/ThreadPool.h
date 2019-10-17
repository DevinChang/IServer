//
// Created by devinchang on 2019/10/8.
//

#ifndef ISERVER_THREADPOOL_H
#define ISERVER_THREADPOOL_H

#include "Thread.h"
#include "Mutex.h"
#include "Condition.h"
#include "Util.h"
#include <vector>
#include <deque>
//#include <functional>



class ThreadPool {
public:
    typedef std::function<void()> Task;

    ThreadPool(const std::string &name = std::string("ThreadPool"));
    ~ThreadPool();

    void start(int numThreads);
    void stop();
    void run(Task f);

    // 必须要start()方法之前调用
    void setMaxQueueSize(int maxSize){ maxQueueSize_ = maxSize; }
    void setThreadInitCallback(const Task &cb){ threadInitCallback_ = cb; }

    const std::string &name() const { return name_; }

    size_t queueSize() const;
private:
    bool isFull() const;
    void runInThread();
    Task take();

    std::string name_;
    Task threadInitCallback_;
    std::vector<std::unique_ptr<Thread>> threads_;
    std::deque<Task> queue_;
    size_t maxQueueSize_;
    bool running_;
    mutable MutexLock mutex_;
    Condition cond_;
    Condition notEmpty_;
    Condition notFull_;
};


#endif //ISERVER_THREADPOOL_H
