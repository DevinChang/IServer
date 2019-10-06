//
// Created by devinchang on 2019/7/30.
//

#ifndef INC_315SERVER_CURRENTTHREAD_H
#define INC_315SERVER_CURRENTTHREAD_H


namespace CurrentThread {
    extern __thread int t_cachedTid;
    extern __thread char t_tidString[32];
    extern __thread int t_tidStringLength;
    extern __thread const char* t_threadName;

    void cacheTid();

    inline int tid(){
        if(__builtin_expect(t_cachedTid == 0, 0)){
            cacheTid();
        }
        return t_cachedTid;
    }

};


#endif //INC_315SERVER_CURRENTTHREAD_H
