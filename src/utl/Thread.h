//
// Created by devinchang on 2019/7/30.
//

#ifndef INC_315SERVER_THREAD_H
#define INC_315SERVER_THREAD_H

//#include <thread.h>
#include <thread>
#include <memory>
#include <functional>

namespace Detail{
    pid_t gettid();
}

class Thread{
public:
    typedef std::function<void()> ThreadFunc;
    explicit Thread(ThreadFunc func, const std::string &name = std::string());
    ~Thread();
public:
    void start();
    int join();
    bool started() const {return started_;}
    pid_t tid() const { return tid_; }
    const std::string &name() const{ return name_; }


private:
    bool joined_;
    bool started_;
    pid_t tid_;
    pthread_t pthreadid_;
    std::string name_;
    ThreadFunc func_;
};


#endif //INC_315SERVER_THREAD_H
