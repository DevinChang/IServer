//
// Created by devinchang on 2019/10/3.
//

#ifndef CONNECTION_TCPCLIENT_H
#define CONNECTION_TCPCLIENT_H

#include "Mutex.h"
#include "TCPConnection.h"
#include <memory>

class Connector;
typedef std::shared_ptr<Connector> ConnectorPtr;

class TCPClient {
public:
    typedef std::function<void(const TCPConnectionPtr&)> ConnectionCallback;
    typedef std::function<void(const TCPConnectionPtr&, Buffer *buf, TimeStamp)> MessageCallback;
    typedef std::function<void(const TCPConnectionPtr&)> CloseCallback;
    typedef std::function<void(const TCPConnectionPtr&)> WriteCompleteCallback;
public:
    TCPClient(EventLoop *loop, const InetAddress &serverAddr);
    ~TCPClient();

    void connect();
    void disConnect();
    void stop();

    TCPConnectionPtr connection() const{
        MutexLockGuard lock(mutex_);
        return connection_;
    }

    bool retry() const;
    void enableRetry() { retry_ = true; }

    void setConnectionCallback(const ConnectionCallback &cb) { connectionCallback_ = cb; }
    void setMessageCallback(const MessageCallback &cb) { messageCallback_ = cb; }

private:
    void newConnection(int sockfd);

    void removeConnection(const TCPConnectionPtr &conn);

    EventLoop *loop_;
    ConnectorPtr connector_;
    ConnectionCallback connectionCallback_;
    MessageCallback messageCallback_;
    WriteCompleteCallback writeCompleteCallback_;
    bool retry_;
    bool connect_;
    int nextConnId_;
    mutable MutexLock mutex_;
    TCPConnectionPtr connection_;
};


#endif //CONNECTION_TCPCLIENT_H
