//
// Created by devinchang on 2019/9/9.
//

#ifndef INC_315SERVER_TCPSERVER_H
#define INC_315SERVER_TCPSERVER_H

#include "InetAddress.h"
#include <memory>
#include <functional>
#include <map>
#include <string>
#include "TCPConnection.h"


class EventLoop;
class Acceptor;
class EventLoopThreadPool;

// 用于管理accept获得的TCPconnection
class TCPServer {
public:
    typedef std::function<void(const TCPConnectionPtr&)> ConnectionCallback;
    typedef std::function<void(const TCPConnectionPtr&, Buffer *buf, TimeStamp)> MessageCallback;
    //typedef std::function<void(const TCPConnectionPtr&, const char *data, ssize_t lel)> MessageCallback;
    typedef std::function<void(const TCPConnectionPtr&)> WriteCompleteCallback;

    TCPServer(EventLoop *loop, const InetAddress &listenAddr);
    ~TCPServer();

    // 如果其不在监听,则启动该服务器
    void start();

    // 设置连接回调函数
    void setConnectionCallback(const ConnectionCallback &cb) { connectionCallback_ = cb; }

    // 设置消息回调函数
    void setMessageCallback(const MessageCallback &cb) { messageCallback_ = cb; }

    void setWriteCompleteCallback(const WriteCompleteCallback &cb) { writeCompleteCallback_ = cb; }

    // 设置线程的数量用来处理输入
    // 参数:
    // 0 - 表示所有IO都在loop的线程里,没有线程会被创建
    // 1 - 表示所有IO在别的线程里
    // N - 表示有着N个线程的线程池
    void setThreadNum(int numThreads);
private:
    void newConnection(int sockfd, const InetAddress &peerAddr);

    // 9/16 new add
    void removeConnection(const TCPConnectionPtr &conn);

    void removeConnectionInLoop(const TCPConnectionPtr &conn);

    typedef std::map<std::string, TCPConnectionPtr> ConnectionMap;

    EventLoop *loop_;
    const std::string name_;
    std::unique_ptr<Acceptor> acceptor_;
    // 9/16 new add
    // 10/3 modify: unique_ptr -> shared_ptr
    std::shared_ptr<EventLoopThreadPool> threadPoll_;
    ConnectionCallback connectionCallback_;
    MessageCallback messageCallback_;
    WriteCompleteCallback writeCompleteCallback_;
    bool started_;
    int nextConnId_;
    ConnectionMap connections_;
};


#endif //INC_315SERVER_TCPSERVER_H
