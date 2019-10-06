//
// Created by devinchang on 2019/10/4.
//

#include "echoServer.h"
#include "../../utl/TimeStamp.h"
#include <iostream>
#include "../../utl/Log.h"


using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;


echoServer::echoServer(EventLoop *loop, InetAddress &listenAddr)
           : server_(loop, listenAddr)
{
    server_.setConnectionCallback(std::bind(&echoServer::onConnection, this, _1));
    server_.setMessageCallback(std::bind(&echoServer::onMessage, this, _1, _2, _3));
}

void echoServer::start() {
    server_.start();
}


void echoServer::onConnection(const TCPConnectionPtr &conn) {
    LOG_INFO << "echoServer-" << conn->peerAddress().toHostPort() << "->"
         << conn->localAddress().toHostPort() << "is" << (conn->connected() ? "UP" : "DOWN");
}


void echoServer::onMessage(const TCPConnectionPtr &conn, Buffer *buf, TimeStamp time) {
    std::string msg(buf->retrieveAllAsString());
    LOG_INFO << conn->name() << " echo " << msg.size() << " bytes "
              << "data received at " << time.toString() << " msg: " << msg.data();
    conn->send(msg);
}
