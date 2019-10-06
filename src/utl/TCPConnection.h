//
// Created by devinchang on 2019/9/9.
//

#ifndef INC_315SERVER_TCPCONNECTION_H
#define INC_315SERVER_TCPCONNECTION_H

#include <memory>
#include <string>
#include "InetAddress.h"
#include "Buffer.h"
#include "Socket.h"
#include "Util.h"
//#include "Any.h"

// new add boost
#include <boost/any.hpp>

class Channel;
class EventLoop;
//class Socket;
class TimeStamp;

class TCPConnection;

typedef std::shared_ptr<TCPConnection> TCPConnectionPtr;

// 表示一次TCP连接, 它是不可再生的
class TCPConnection : public std::enable_shared_from_this<TCPConnection> {
public:
    typedef std::function<void(const TCPConnectionPtr&)> ConnectionCallback;
    typedef std::function<void(const TCPConnectionPtr&, Buffer *buf, TimeStamp)> MessageCallback;
    typedef std::function<void(const TCPConnectionPtr&)> CloseCallback;
    typedef std::function<void(const TCPConnectionPtr&)> WriteCompleteCallback;
    typedef std::function<void(const TCPConnectionPtr&, size_t)> HighWaterMarkCallback;

    TCPConnection(EventLoop *loop, const std::string &name, int sockfd,
            const InetAddress &localAddr,
            const InetAddress &peerAddr);
    ~TCPConnection();

    EventLoop *getLoop() const { return loop_; }
    const std::string &name() const { return name_; }
    const InetAddress &localAddress() { return localAddr_; }
    const InetAddress &peerAddress() { return peerAddr_; }
    bool connected() const { return state_ == kConnected; }

    void setConnectionCallback(const ConnectionCallback &cb){ connectionCallback_ = cb; }
    void setMessageCallback(const MessageCallback &cb) { messageCallback_ = cb; }
    void setWriteCompleteCallback(const WriteCompleteCallback &cb) { writeCompleteCallback_ = cb; }
    void setCloseCallback(const CloseCallback &cb) { closeCallback_ = cb; }
    // 10/3 new add
    void setHighWaterMarkCallback(const HighWaterMarkCallback &cb, size_t hightWaterMark) { highWaterMarkCallback_ = cb; highWaterMark_ = hightWaterMark; }

    void connectEstablished();

    void connectDestroyed();

    // 9/12 add
    //void send(const std::string &message);
    void send(const void *message, size_t len);
    void send(const strpiece::StringPiece &message);
    void send(Buffer *message);
    void send(Buffer &&message);
    void send(std::string &&message);

    void shutdown();
    // 9/15 add tcpdelay
    void setTCPNodelay(bool on){ socket_->setTCPNoDelay(on); }

    // 10/3 new add
    Buffer *inputBuffer(){ return &inputBuffer_; }
    Buffer *outputBuffer() { return &outputBuffer_; }

    bool getTCPInfo(struct tcp_info*) const;
    std::string getTCPInfoString() const;
    void forceClose();
    void forceCloseWithDelay(double seconds);
    void startRead();
    void stopRead();

    bool isReading() const { return reading_; }
    void setContext(const boost::any &context){ context_ = context; }
    const boost::any &getContext() const { return context_; }
    boost::any *getMutableContext() { return &context_; }
private:
    enum StateE {kConnecting, kConnected, kDisconnecting, kDisConnected, };

    void setState(StateE s){ state_ = s; }
    void handleRead(TimeStamp receiveTime);
    void handleWrite();
    void handleClose();
    void handleError();

    // 9/12 add
    void sendInLoop(const std::string &message);
    void sendInLoop(const void *message, size_t len);
    void sendInLoop(const strpiece::StringPiece &message);

    void shutdownInLoop();

    void forceCloseInLoop();
    const char *stateToString() const;
    void startReadInLoop();
    void stopReadInLoop();

    EventLoop *loop_;
    std::string name_;
    StateE state_;
    std::unique_ptr<sockets::Socket> socket_;
    std::unique_ptr<Channel> channel_;
    InetAddress localAddr_;
    InetAddress peerAddr_;

    ConnectionCallback connectionCallback_;
    MessageCallback messageCallback_;
    CloseCallback closeCallback_;
    // 9/15 new add: writeCompleteCallback
    WriteCompleteCallback writeCompleteCallback_;
    HighWaterMarkCallback highWaterMarkCallback_;
    Buffer inputBuffer_;
    Buffer outputBuffer_;

    // 10/3 new add
    boost::any context_;
    size_t highWaterMark_;
    bool reading_;
};

//typedef shared_ptr<TCPConnection> TCPConnectionPtr;


#endif //INC_315SERVER_TCPCONNECTION_H
