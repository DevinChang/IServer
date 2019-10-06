//
// Created by devinchang on 2019/10/3.
//

#include "TCPClient.h"
#include "Connector.h"
#include "EventLoop.h"
#include "Socket.h"
#include <stdio.h>
#include "Util.h"
#include "Log.h"

void removeConnection(EventLoop *loop, const TCPConnectionPtr &conn){
    loop->queueInLoop(std::bind(&TCPConnection::connectDestroyed, conn));
}

void removeConnector(const ConnectorPtr &connector){

}
TCPClient::TCPClient(EventLoop *loop, const InetAddress &serverAddr) :
           loop_(loop),
           connector_(new Connector(loop, serverAddr)),
           retry_(false),
           connect_(true),
           nextConnId_(1)
{
    connector_->setNewConnectionCallback(std::bind(&TCPClient::newConnection, this, std::placeholders::_1));
    LOG_INFO << "TCPClient::TCPClient[" << this << "]-connector " << util::get_pointer(connector_);
}

TCPClient::~TCPClient() {
    LOG_INFO << "TCPClient::~TCPClient[" << this << "]-connector" << util::get_pointer(connector_);
    TCPConnectionPtr conn;
    {
        MutexLockGuard lock(mutex_);
        conn = connection_;
    }
    if(conn){
        CloseCallback cb = std::bind(&::removeConnection, loop_, std::placeholders::_1);
        loop_->runInLoop(std::bind(&TCPConnection::setCloseCallback, conn, cb));
    }
    else{
        connector_->stop();
        loop_->runAfter(1, std::bind(&::removeConnector, connector_));
    }
}


void TCPClient::connect() {
    LOG_INFO << "TCPClient::connect[" << this << "]-connecting to "
              << connector_->serverAddress().toHostPort();
    connect_ = true;
    connector_->start();
}


void TCPClient::disConnect() {
    connect_ = false;
    {
        MutexLockGuard lock(mutex_);
        if(connection_){
            connection_->shutdown();
        }
    }
}


void TCPClient::stop() {
    connect_ = false;
    connector_->stop();
}


void TCPClient::newConnection(int sockfd) {
    loop_->assertInLoopThread();
    InetAddress peerAddr(sockets::getPeerAddr(sockfd));
    char buf[32];
    snprintf(buf, sizeof(buf), ":%s#%d", peerAddr.toHostPort().c_str(), nextConnId_);
    ++nextConnId_;
    std::string connName = buf;

    InetAddress localAddr(sockets::getLocalAddr(sockfd));
    TCPConnectionPtr conn(new TCPConnection(loop_, connName, sockfd, localAddr, peerAddr));

    conn->setConnectionCallback(connectionCallback_);
    conn->setMessageCallback(messageCallback_);
    conn->setWriteCompleteCallback(writeCompleteCallback_);
    conn->setCloseCallback(std::bind(&TCPClient::removeConnection, this, std::placeholders::_1));

    {
        MutexLockGuard lock(mutex_);
        connection_ = conn;
    }
    conn->connectEstablished();
}

void TCPClient::removeConnection(const TCPConnectionPtr &conn) {
    loop_->assertInLoopThread();
    assert(loop_ == conn->getLoop());

    {
        MutexLockGuard lock(mutex_);
        assert(connection_ == conn);
        connection_.reset();
    }

    loop_->queueInLoop(std::bind(&TCPConnection::connectDestroyed, conn));
    if(retry_ && connect_){
        LOG_INFO << "TCPClient::connect[" << this << "]-Reconnecting to "
                  << connector_->serverAddress().toHostPort();
        connector_->restart();
    }
}

