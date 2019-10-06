//
// Created by devinchang on 2019/7/30.
//

#include "Thread.h"
#include "utl.h"
#include "CurrentThread.h"
#include "Log.h"

Thread::Thread(std::function<void()> func, const std::string &name)
        : started_(false), joined_(false), pthreadid_(0), tid_(0),
          func_(std::move(func)), name_(name){}


Thread::~Thread(){
    if(started_ && joined_){
        pthread_detach(pthreadid_);
    }
}


namespace Detail{
    pid_t gettid(){
        return static_cast<pid_t>(::syscall(SYS_gettid));
    }
}


void *startThread(void *obj){
    // do some work

    return nullptr;
}

void Thread::start(){
    assert(!started_);
    started_ = true;

    // 成功返回0,失败则返回错误代码
    if(pthread_create(&pthreadid_, nullptr, &startThread, nullptr)){
        // 失败的情况
        started_ = false;
    }
    else{
        // 成功的情况
        assert(tid_ > 0);
    }
}

int Thread::join(){
    assert(started_);
    assert(!joined_);
    joined_ = true;
    return pthread_join(pthreadid_, nullptr);
}


void CurrentThread::cacheTid(){
    if(t_cachedTid == 0){
        t_cachedTid = Detail::gettid();
        t_tidStringLength = snprintf(t_tidString, sizeof(t_tidString), "%5d", t_cachedTid);
    }
}


