//
// Created by devinchang on 2019/9/9.
//

#include "TCPConnection.h"
#include "Channel.h"
#include "Socket.h"
#include "EventLoop.h"
#include <error.h>
#include <stdio.h>
#include "Util.h"
#include "Log.h"

TCPConnection::TCPConnection(EventLoop *loop, const std::string &name, int sockfd,
                             const InetAddress &localAddr,
                             const InetAddress &peerAddr) :
                             loop_(loop), name_(name), state_(kConnecting),
                             reading_(true),
                             socket_(new sockets::Socket(sockfd)),
                             channel_(new Channel(loop, sockfd)),
                             localAddr_(localAddr), peerAddr_(peerAddr),
                             highWaterMark_(64 * 1024 * 1024){
    channel_->setReadCallback(std::bind(&TCPConnection::handleRead, this, std::placeholders::_1));
    channel_->setWriteCallback(std::bind(&TCPConnection::handleWrite, this));
    channel_->setCloseCallback(std::bind(&TCPConnection::handleClose, this));
    channel_->setErrorCallback(std::bind(&TCPConnection::handleError, this));
    LOG_DEBUG << " TCPConnection::ctor[" << name_ << "] at " << this
              << " fd = " << sockfd;

}

TCPConnection::~TCPConnection() {
    LOG_DEBUG << " TCPConnection::dtor[" << name_ << "] at "
         << this << " fd = " << channel_->fd();
}

void TCPConnection::connectEstablished() {
    loop_->assertInLoopThread();
    assert(state_ == kConnecting);
    setState(kConnected);
    channel_->enableReading();
    connectionCallback_(shared_from_this());

}

//void TCPConnection::handleRead() {
//    char buf[65536];
//    ssize_t n = ::read(channel_->fd(), buf, sizeof(buf));
//    // 运用shared_fron_this这中C++11新特性,可以用shared_from_this()返回一个新的
//    // shared_ptr<TCPConnection>对象,
//    // 新特性的使用场合：当类A被shared_ptr管理,且在类A的成员函数里需要把当前类对象作为参数传给
//    // 其他函数时,就需要传递一个指向自身的shared_ptr.
//    //messageCallback_(shared_from_this(), buf, n);
//    if(n > 0){
//        messageCallback_(shared_from_this(), buf, n);
//    }
//    else if(n == 0){
//        handleClose();
//    }
//    else{
//        handleError();
//    }
//}

void TCPConnection::handleRead(TimeStamp receiveTime) {
    int savedErrno = 0;
    ssize_t n = inputBuffer_.readFd(channel_->fd(), &savedErrno);
    if(n > 0){
        messageCallback_(shared_from_this(), &inputBuffer_, receiveTime);
    }
    else if(n == 0){
        handleClose();
    }
    else{
        errno = savedErrno;
        LOG_SYSERR << "TCPConnection::handleRead";
        handleError();
    }
}

void TCPConnection::handleClose() {
    loop_->assertInLoopThread();
    LOG_TRACE << " TCPConnection::handleClose state = " << state_;
    assert(state_ == kConnected);
    channel_->disableAll();
    closeCallback_(shared_from_this());
}

void TCPConnection::handleError() {
    int err = sockets::getSocketError(channel_->fd());
    LOG_ERROR << " TCPConnection::handleError [" << name_ << "] - SO_ERROR = "
         << err << util::strerror_tl(err);
}


void TCPConnection::connectDestroyed() {
    loop_->assertInLoopThread();
    assert(state_ == kConnected || state_ == kDisconnecting);
    setState(kDisConnected);
    channel_->disableAll();
    connectionCallback_(shared_from_this());
    loop_->removeChannel(util::get_pointer(channel_));
}

void TCPConnection::shutdown() {
    if(state_ == kConnected){
        setState(kDisconnecting);
        loop_->runInLoop(std::bind(&TCPConnection::shutdownInLoop, this));
    }
}

void TCPConnection::shutdownInLoop() {
    loop_->assertInLoopThread();
    if(!channel_->isWriting()){
        socket_->shutdownWrite();
    }
}

//void TCPConnection::send(const std::string &message) {
//    if(state_ == kConnected){
//        if(loop_->isInLoopThread()){
//            // TODO: 可用移动语义来避免内存拷贝的开销
//            sendInLoop(message);
//        }
//        else{
//            //loop_->runInLoop(std::bind(&TCPConnection::sendInLoop, this, message));
//            loop_->runInLoop(std::bind(&TCPConnection::sendInLoop, this, message));
//        }
//    }
//}

void TCPConnection::send(const void *message, size_t len) {
    send(strpiece::StringPiece(static_cast<const char *>(message), len));
}

void TCPConnection::send(const strpiece::StringPiece &message){
    if(state_ == kConnected){
        if(loop_->isInLoopThread()){
            sendInLoop(message);
        }
        else{
            void (TCPConnection::*fp)(const strpiece::StringPiece &message) = &TCPConnection::sendInLoop;
            loop_->runInLoop(std::bind(fp, this, message.as_string()));
        }
    }
}

void TCPConnection::send(Buffer *message) {
    if(state_ == kConnected){
        if(loop_->isInLoopThread()){
            sendInLoop(message->peek(), message->readableBytes());
            message->retrieveAll();
        }
        else{
            void (TCPConnection::*fp)(const strpiece::StringPiece &message) = &TCPConnection::sendInLoop;
            loop_->runInLoop(std::bind(fp, this, message->retrieveAllAsString()));
        }
    }
}

void TCPConnection::sendInLoop(const strpiece::StringPiece &message) {
    sendInLoop(message.data(), message.size());
}

void TCPConnection::sendInLoop(const void *message, size_t len) {
    loop_->assertInLoopThread();
    ssize_t nwrote = 0;
    size_t remaining = len;
    bool faultError = false;
    if(state_ == kDisConnected){
        LOG_WARN << "disconnected, give up writing";
        return;
    }
    // 如果输出队列里没有数据,则直接写
    if(!channel_->isWriting() && outputBuffer_.readableBytes() == 0){
        nwrote = ::write(channel_->fd(), message, len);
        if(nwrote >= 0){
            remaining = len - nwrote;
            if(remaining == 0 && writeCompleteCallback_){
                loop_->queueInLoop(std::bind(writeCompleteCallback_, shared_from_this()));
            }
            //if(util::implicit_cast<size_t>(nwrote) < message.size()){
            //    std::cout << "write more data";
            //}
            //else if(writeCompleteCallback_){
            //    loop_->queueInLoop(std::bind(writeCompleteCallback_, shared_from_this()));
            //}
            else{
                nwrote = 0;
                if(errno != EWOULDBLOCK){
                    LOG_SYSERR << "TCPConnection::sendInLoop";
                    if(errno == EPIPE || errno == ECONNRESET){
                        faultError = true;
                    }
                }
            }
        }
    }
    // 如果只发送了部分数据,则把剩余数据放入outputBuffer_
    assert(nwrote >= 0);
    if(!faultError && remaining > 0){
        size_t oldLen = outputBuffer_.readableBytes();
        if(oldLen + remaining >= highWaterMark_ & oldLen < highWaterMark_ && highWaterMarkCallback_){
            loop_->queueInLoop(std::bind(highWaterMarkCallback_, shared_from_this(), oldLen + remaining));
        }
        outputBuffer_.append(static_cast<const char *>(message) + nwrote, remaining);
        if(!channel_->isWriting()){
            channel_->enableWriting();
        }
    }
}

//void TCPConnection::sendInLoop(const std::string &message) {
//    loop_->assertInLoopThread();
//    ssize_t nwrote = 0;
//    // 如果输出队列里没有数据,则直接写
//    if(!channel_->isWriting() && outputBuffer_.readableBytes() == 0){
//        nwrote = ::write(channel_->fd(), message.data(), message.size());
//        if(nwrote >= 0){
//            if(util::implicit_cast<size_t>(nwrote) < message.size()){
//                std::cout << "write more data";
//            }
//            else if(writeCompleteCallback_){
//                loop_->queueInLoop(std::bind(writeCompleteCallback_, shared_from_this()));
//            }
//            else{
//                nwrote = 0;
//                if(errno != EWOULDBLOCK){
//                    LOG_SYSERR << "TCPConnection::sendInLoop";
//                }
//            }
//        }
//    }
//    // 如果只发送了部分数据,则把剩余数据放入outputBuffer_
//    assert(nwrote >= 0);
//    if(util::implicit_cast<size_t>(nwrote) < message.size()){
//        outputBuffer_.append(message.data() + nwrote, message.size() - nwrote);
//        if(!channel_->isWriting()){
//            channel_->enableWriting();
//        }
//    }
//}

// 当socket可写时,Channel会调用此函数
void TCPConnection::handleWrite() {
    loop_->assertInLoopThread();
    if(channel_->isWriting()){
        ssize_t n = ::write(channel_->fd(), outputBuffer_.peek(), outputBuffer_.readableBytes());
        if(n > 0){
            outputBuffer_.retrieve(n);
            // 一旦数据发送完毕,立刻停止观察writable事件,避免busy loop
            if(outputBuffer_.readableBytes() == 0){
                channel_->disableWriting();
                if(writeCompleteCallback_){
                    loop_->queueInLoop(std::bind(writeCompleteCallback_, shared_from_this()));
                }
                if(state_ == kDisconnecting){
                    shutdownInLoop();
                }
            }
            else{
                LOG_SYSERR << " TCPConnection::handleWrite";
            }
        }
        else{
            LOG_TRACE << " writing more data";
        }
    }
    else{
        LOG_TRACE << " Connection is down, no more writing";
    }

}

bool TCPConnection::getTCPInfo(struct tcp_info *tcpi) const {
    return socket_->getTCPInfo(tcpi);
}

std::string TCPConnection::getTCPInfoString() const {
    char buf[1024];
    buf[0] = '\0';
    socket_->getTCPInfoString(buf, sizeof(buf));
    return buf;
}