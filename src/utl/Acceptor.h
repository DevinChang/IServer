//
// Created by devinchang on 2019/9/2.
//

#ifndef INC_315SERVER_ACCEPTOR_H
#define INC_315SERVER_ACCEPTOR_H

#include <functional>
#include "Socket.h"
#include "Channel.h"

class InetAddress;
class EventLoop;

// 用于accept新TCP连接
class Acceptor {
public:
    typedef std::function<void (int sockfd, const InetAddress&)> NewConnectionCallback;

    Acceptor(EventLoop *loop, const InetAddress& listenAddr);

    void setNewConnectionCallback(const NewConnectionCallback &cb) { newConnectionCallback_ = cb; }

    bool listenning() const { return listenning_; }

    void listen();
private:
    void handleRead();
    EventLoop *loop_;
    sockets::Socket acceptSocket_;
    Channel acceptChannel_;
    NewConnectionCallback newConnectionCallback_;
    bool listenning_;
};


#endif //INC_315SERVER_ACCEPTOR_H
