//
// Created by devinchang on 2019/8/31.
//

#include "../../utl/EventLoop.h"
#include <stdio.h>
#include "../../utl/Thread.h"


EventLoop *g_loop;

void threadFunc(){
    g_loop->loop();
}

int main(){
    EventLoop loop;
    g_loop = &loop;
    Thread t(threadFunc);
    t.start();
    t.join();
}
