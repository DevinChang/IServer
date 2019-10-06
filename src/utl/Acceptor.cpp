//
// Created by devinchang on 2019/9/2.
//

#include "Acceptor.h"
#include "EventLoop.h"
#include "InetAddress.h"


Acceptor::Acceptor(EventLoop *loop, const InetAddress &listenAddr) : loop_(loop),
                  acceptSocket_(sockets::createNonblockingOrDie()),
                  acceptChannel_(loop, acceptSocket_.fd()), listenning_(false){
    acceptSocket_.setReuseAddr(true);
    acceptSocket_.Bind(listenAddr);
    acceptChannel_.setReadCallback(std::bind(&Acceptor::handleRead, this));
}


void Acceptor::listen() {
    loop_->assertInLoopThread();
    listenning_ = true;
    acceptSocket_.Listen();
    acceptChannel_.enableReading();
}

void Acceptor::handleRead() {
    loop_->assertInLoopThread();
    InetAddress peerAddr(0);
    int connfd = acceptSocket_.Accept(&peerAddr);
    if(connfd >= 0){
        if(newConnectionCallback_){
            newConnectionCallback_(connfd, peerAddr);
        }
        else{
            sockets::close(connfd);
        }
    }
}
