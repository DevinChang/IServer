//
// Created by devinchang on 2019/8/22.
//

#include <sys/timerfd.h>
#include "../../utl/EventLoop.h"
#include "../../utl/Channel.h"
#include <unistd.h>

EventLoop *g_loop;

void timeout(){
    printf("Timeout!\n");

}



