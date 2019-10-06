//
// Created by devinchang on 2019/10/4.
//

#ifndef CONNECTION_ECHO_H
#define CONNECTION_ECHO_H

#include "../../utl/TCPServer.h"




class echoServer {
public:
    echoServer(EventLoop *loop, InetAddress &listenAddr);

    void start();
private:
    void onConnection(const TCPConnectionPtr &conn);
    void onMessage(const TCPConnectionPtr &conn, Buffer *buf, TimeStamp time);

    TCPServer server_;
};


#endif //CONNECTION_ECHO_H
