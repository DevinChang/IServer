//
//
// Created by devinchang on 2019/9/26.
//

#include "../../utl/TCPServer.h"
#include "../../utl/EventLoop.h"
#include "../../utl/InetAddress.h"
#include <stdio.h>
#include <iostream>
using namespace std;

std::string message;
std::string message1;
std::string message2;


void onConnection(const TCPConnectionPtr &conn){
    if(conn->connected()){
        cout << "onConnection:tid = " << CurrentThread::tid()
             << " new connection [" << conn->name().c_str() <<
             "] from " << conn->peerAddress().toHostPort().c_str() << endl;
        conn->send(message);
    }
    else{
        cout << "onConnection(): tid = " << CurrentThread::tid()
             << " connection [" << conn->name().c_str() << "] is down" << endl;
    }

}

void onWriteComplete(const TCPConnectionPtr& conn){
    conn->send(message);
}

void onMessage(const TCPConnectionPtr &conn, Buffer *buf, TimeStamp receiveTime){
    cout << "onMessage():tid = " << CurrentThread::tid() << " received "
         << buf->readableBytes() << " bytes from connection [" << conn->name().c_str()
         << "] at " << receiveTime.toFormattedString().c_str() << endl;
    buf->retrieveAll();
}

int main(int argc, char *argv[]){
    cout << "main(): pid = " << getpid() << endl;
    std::string line;
    for(int i = 33; i < 127; i++){
        line.push_back(char(i));
    }
    line += line;

    for(size_t i = 0; i < 127 - 33; i++){
        message += line.substr(i, 72) + '\n';
    }

    InetAddress listenAddr(9981);
    EventLoop loop;

    TCPServer server(&loop, listenAddr);
    server.setConnectionCallback(onConnection);
    server.setMessageCallback(onMessage);
    server.setWriteCompleteCallback(onWriteComplete);
    if(argc > 1){
        server.setThreadNum(atoi(argv[1]));
    }

    server.start();
    loop.loop();

}


