//
// Created by devinchang on 2019/10/4.
//

#include "echoServer.h"
#include "../../utl/EventLoop.h"
#include <unistd.h>
#include "../../utl/Log.h"


int main(){
    LOG_INFO << "pid = " << getpid();
    EventLoop loop;
    InetAddress listenAddr(2019);
    echoServer server(&loop, listenAddr);
    server.start();
    loop.loop();
}

