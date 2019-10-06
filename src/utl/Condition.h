//
// Created by devinchang on 2019/9/16.
//

#ifndef INC_315SERVER_CONDITION_H
#define INC_315SERVER_CONDITION_H

#include "Mutex.h"
#include <pthread.h>
#include <errno.h>


class Condition {
public:
    explicit Condition(MutexLock &mutex) : mutex_(mutex){
        pthread_cond_init(&pcond_, NULL);
    }

    ~Condition(){
        pthread_cond_destroy(&pcond_);
    }

    void wait(){
        pthread_cond_wait(&pcond_, mutex_.getPthreadMutex());
    }

    void notify(){
        pthread_cond_signal(&pcond_);
    }

    void notifyAll(){
        pthread_cond_broadcast(&pcond_);
    }

    bool waitForSeconds(int seconds){
        struct timespec abstime;
        clock_gettime(CLOCK_REALTIME, &abstime);
        return ETIMEDOUT == pthread_cond_timedwait(&pcond_, mutex_.getPthreadMutex(), &abstime);
    }
private:
    MutexLock &mutex_;
    pthread_cond_t pcond_;
};


#endif //INC_315SERVER_CONDITION_H
