//
// Created by devinchang on 2019/8/17.
//

#include "../../utl/EventLoop.h"
#include <unistd.h>

void threadFunc(){
    printf("threadFunc(): pid = %d, tid = %d\n", getpid(), CurrentThread::tid());
    EventLoop loop;
    loop.loop();
}

int main(int argc, char **argv){
    printf("main(): pid = %d, tid = %d\n", getpid(), CurrentThread::tid());

    EventLoop loop;
    Thread thread();
    loop.loop();
    pthread_exit(NULL);
}

