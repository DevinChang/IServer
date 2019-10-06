//
// Created by devinchang on 2019/10/3.
//
#include <utility>
#include <stdio.h>
#include <unistd.h>

#include "../../utl/EventLoop.h"
#include "../../utl/InetAddress.h"
#include "../../utl/TCPClient.h"


std::string message = "hello\n";

void onConnection(const TCPConnectionPtr &conn){
    if(conn->connected()){
        std::cout << "onConnection():new connection [" << conn->name().c_str()
                  << "] from " << conn->peerAddress().toHostPort().c_str();
        conn->send(message);
    }
    else{
        std::cout << "onConnection():connection [" << conn->name().c_str() << "] is down\n";
    }
}

void onMessage(const TCPConnectionPtr &conn, Buffer *buf, TimeStamp receiveTime){
    std::cout << "onMessage():received " << buf->readableBytes() << " bytes from connection ["
              << conn->name().c_str() << "] at " << receiveTime.toFormattedString().c_str() << "\n";
    std::cout << "onMessage(): [" << buf->retrieveAsString().c_str() << "]\n";
}






int main(){
    EventLoop loop;
    InetAddress serverAddr("localhost", 2019);
    TCPClient client(&loop, serverAddr);

    client.setConnectionCallback(onConnection);
    client.setMessageCallback(onMessage);
    client.enableRetry();
    client.connect();
    loop.loop();
}

