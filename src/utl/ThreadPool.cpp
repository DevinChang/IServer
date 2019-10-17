//
// Created by devinchang on 2019/10/8.
//

#include "ThreadPool.h"
#include <assert.h>
#include <stdio.h>


ThreadPool::ThreadPool(const std::string &name)
           : mutex_(),
             cond_(mutex_),
             notEmpty_(mutex_),
             notFull_(mutex_),
             name_(name),
             maxQueueSize_(0),
             running_(false){}

ThreadPool::~ThreadPool() {
    if(running_){
        stop();
    }

}


void ThreadPool::start(int numThreads) {
    assert(threads_.empty());
    running_ = true;
    threads_.reserve(numThreads);
    for(int i = 0; i < numThreads; i++){
        char id[32];
        snprintf(id, sizeof(id), "%d", i);
        threads_.emplace_back(new Thread(std::bind(&ThreadPool::runInThread, this), name_+id));
        threads_[i]->start();
    }
    if(numThreads == 0 && threadInitCallback_){
        threadInitCallback_();
    }
}

size_t ThreadPool::queueSize() const {
    MutexLockGuard lock(mutex_);
    return queue_.size();
}


void ThreadPool::stop() {
    //running_ = false;
    //cond_.notifyAll();
    //std::for_each(threads_.begin(), threads_.end(), std::bind(Thread::join, std::placeholders::_1));
    {
        MutexLockGuard lock(mutex_);
        running_ = false;
        notEmpty_.notifyAll();
    }
    for(auto &thr : threads_){
        thr->join();
    }
}


void ThreadPool::run(Task task){
    if(threads_.empty()){
        task();
    }
    else{
        MutexLockGuard lock(mutex_);
        queue_.push_back(task);
        notEmpty_.notify();
    }
}


ThreadPool::Task ThreadPool::take() {
    MutexLockGuard lock(mutex_);
    while(queue_.empty() && running_){
        notEmpty_.wait();
    }
    Task task;
    if(!queue_.empty()){
        task = queue_.front();
        queue_.pop_front();
        if(maxQueueSize_ > 0){
            notFull_.notify();
        }
    }
    return task;
}

bool ThreadPool::isFull() const {
    mutex_.assertLocked();
    return maxQueueSize_ > 0 && queue_.size() >= maxQueueSize_;
}

void ThreadPool::runInThread() {
    try{
        if(threadInitCallback_){
            threadInitCallback_();
        }
        while(running_){
            Task task(take());
            if(task){
                task();
            }
        }
    }
    catch (const ex::Exception &ex){
        fprintf(stderr, "exception caught in ThreadPool %s\n", name_.c_str());
        fprintf(stderr, "reason: %s\n", ex.what());
        fprintf(stderr, "stack trace: %s\n", ex.stackTrace());
        abort();
    }
    catch (const std::exception &ex){
        fprintf(stderr, "exception caught in ThreadPool %s\n", name_.c_str());
        fprintf(stderr, "reason : %s\n", ex.what());
        abort();
    }
    catch (...){
        fprintf(stderr, "unknown exception caught in ThreadPool %s\n", name_.c_str());
        abort();
    }

}
