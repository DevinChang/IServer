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
        if(!message1.empty())
            conn->send(message1);
        if(!message2.empty())
            conn->send(message2);
        conn->shutdown();
    }
    else{
        cout << "onConnection(): tid = " << CurrentThread::tid()
             << " connection [" << conn->name().c_str() << "] is down" << endl;
    }

}


void onMessage(const TCPConnectionPtr &conn, Buffer *buf, TimeStamp receiveTime){
    cout << "onMessage():tid = " << CurrentThread::tid() << " received "
         << buf->readableBytes() << " bytes from connection [" << conn->name().c_str()
         << "] at " << receiveTime.toFormattedString().c_str() << endl;
    buf->retrieveAll();
}

int main(int argc, char *argv[]){
    cout << "main(): pid = " << getpid() << endl;
    int len1 = atoi(argv[1]);
    int len2 = atoi(argv[2]);
    message1.resize(len1);
    message2.resize(len2);
    std::fill(message1.begin(), message1.end(), 'A');
    std::fill(message2.begin(), message2.end(), 'B');

    InetAddress listenAddr(9981);
    EventLoop loop;

    TCPServer server(&loop, listenAddr);
    server.setConnectionCallback(onConnection);
    server.setMessageCallback(onMessage);

    if(argc > 3){
        server.setThreadNum(atoi(argv[3]));
    }

    server.start();

    loop.loop();
}
