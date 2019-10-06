//
// Created by devinchang on 2019/9/9.
//

#include "TCPServer.h"
#include "Acceptor.h"
#include "EventLoop.h"
#include "EventLoopThreadPool.h"
#include "Socket.h"
#include <stdio.h>
#include "Util.h"
#include "Log.h"




TCPServer::TCPServer(EventLoop *loop, const InetAddress &listenAddr) :
                    loop_(loop), name_(listenAddr.toHostPort()),
                    acceptor_(new Acceptor(loop, listenAddr)),
                    threadPoll_(new EventLoopThreadPool(loop)),
                    started_(false), nextConnId_(1){
    acceptor_->setNewConnectionCallback(std::bind(&TCPServer::newConnection, this,
            std::placeholders::_1, std::placeholders::_2));

}


TCPServer::~TCPServer() {}

void TCPServer::setThreadNum(int numThreads) {
    assert(0 <= numThreads);
    threadPoll_->setThreadNum(numThreads);
}

void TCPServer::start() {
    if(!started_)
        started_ = true;
    if(!acceptor_->listenning())
        loop_->runInLoop(std::bind(&Acceptor::listen, util::get_pointer(acceptor_)));
}



void TCPServer::newConnection(int sockfd, const InetAddress &peeraddr) {
    loop_->assertInLoopThread();
    // 9/16 new add
    EventLoop *ioloop = threadPoll_->getNextLoop();
    char buf[32];
    snprintf(buf, sizeof(buf), "#%d", nextConnId_);
    ++nextConnId_;
    std::string connname = name_ + buf;

    //printf("tcpserver::newconnection[%s");
    LOG_INFO << " Tcpserver::newConnection [" << name_ << "] -new Connection ["
              << connname << "] from " << peeraddr.toHostPort();

    InetAddress localaddr(sockets::getLocalAddr(sockfd));
    TCPConnectionPtr conn(new TCPConnection(ioloop, connname, sockfd, localaddr, peeraddr));
    connections_[connname] = conn;
    conn->setConnectionCallback(connectionCallback_);
    conn->setMessageCallback(messageCallback_);
    conn->setWriteCompleteCallback(writeCompleteCallback_);
    conn->setCloseCallback(std::bind(&TCPServer::removeConnection, this, std::placeholders::_1));
    //conn->connectestablished();
    ioloop->runInLoop(std::bind(&TCPConnection::connectEstablished, conn));
}

void TCPServer::removeConnection(const TCPConnectionPtr &conn) {
    //loop_->assertinloopthread();
    //cout << "tcpserver::removeconnection [" << name_ << "] -connection " << conn->name();
    //size_t n = connections_.erase(conn->name());
    //assert(n == 1);
    //loop_->queueinloop(std::bind(&tcpserver::connectdestroyed, conn));
    loop_->runInLoop(std::bind(&TCPServer::removeConnectionInLoop, this, conn));
}

void TCPServer::removeConnectionInLoop(const TCPConnectionPtr &conn) {
    loop_->assertInLoopThread();
    LOG_INFO << "TCPServer::removeConectioninLoop [" << name_ << "] - connection "
         << conn->name();
    size_t n = connections_.erase(conn->name());
    assert(n == 1); (void)n;
    EventLoop *ioLoop = conn->getLoop();
    ioLoop->queueInLoop(std::bind(&TCPConnection::connectDestroyed, conn));
}