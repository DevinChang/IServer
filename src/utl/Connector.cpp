//
// Created by devinchang on 2019/9/16.
//

#include "Connector.h"
#include "Channel.h"
#include "Socket.h"
#include "EventLoop.h"
#include <errno.h>
#include <cassert>
#include "Util.h"
#include "Log.h"



const int Connector::kMaxRetryDelayMs;

Connector::Connector(EventLoop *loop, const InetAddress &serverAddr)
         : loop_(loop), serverAddr_(serverAddr),
           connect_(false), state_(kDisConnected), retryDelayMs_(kInitRetryDelayMs){
    // debug
    //std::cout << "ctor[" << this << "]";
    LOG_DEBUG << "ctor[" << this << "]";
}

Connector::~Connector() {
    // debug:
    //std::cout << "dtor[" << this << "]";
    LOG_DEBUG << "dtor[" << this << "]";
    loop_->cancel(timerld_);
    assert(!channel_);
}

void Connector::start(){
    connect_ = true;
    loop_->runInLoop(std::bind(&Connector::startInLoop, this));
}

void Connector::startInLoop() {
    loop_->assertInLoopThread();
    assert(state_ == kDisConnected);
    if(connect_){
        connect();
    }
    else{
        // debug
        //printf("do not connect!\n");
        LOG_DEBUG << "do not connect";
    }
}

void Connector::connect() {
    int sockfd = sockets::createNonblockingOrDie();
    int ret =sockets::connect(sockfd, serverAddr_.getSockAddrInet());
    int savedErrno = (ret == 0) ? 0 : errno;
    switch (savedErrno){
        case 0:
        case EINPROGRESS:
        case EINTR:
        case EISCONN:
            connecting(sockfd);
            break;
        case EAGAIN:
        case EADDRINUSE:
        case EADDRNOTAVAIL:
        case ECONNREFUSED:
        case ENETUNREACH:
            retry(sockfd);
            break;
        case EACCES:
        case EPERM:
        case EAFNOSUPPORT:
        case EALREADY:
        case EBADF:
        case EFAULT:
        case ENOTSOCK:
            // debug
            //std::cout << "connect error in Connector::startInLoop " << savedErrno;
            LOG_SYSERR << "connect error in Connector::startInLoop " << savedErrno;
            sockets::close(sockfd);
            break;
        default:
            // debug
            //std::cout << "Unexpected error in Connector::startInLoop " << savedErrno;
            LOG_SYSERR << "Unexpected error in Connector::startInLoop " << savedErrno;
            sockets::close(sockfd);
            break;
    }
}

void Connector::restart() {
    loop_->assertInLoopThread();
    setState(kDisConnected);
    retryDelayMs_ = kInitRetryDelayMs;
    connect_ = true;
    startInLoop();
}

void Connector::stop(){
    connect_ = false;
    loop_->cancel(timerld_);
}

void Connector::connecting(int sockfd) {
    setState(kConnecting);
    assert(!channel_);
    channel_.reset(new Channel(loop_, sockfd));
    channel_->setWriteCallback(std::bind(&Connector::handleWrite, this));
    channel_->setErrorCallback(std::bind(&Connector::handleError, this));

    channel_->enableWriting();
}


int Connector::removeAndResetChannel() {
    channel_->disableAll();
    loop_->removeChannel(util::get_pointer(channel_));
    int sockfd = channel_->fd();
    loop_->queueInLoop(std::bind(&Connector::resetChannel, this));
    return sockfd;
}

void Connector::resetChannel() {
    channel_.reset();
}

void Connector::handleWrite() {
    // debug
    //std::cout << "Connector::handleWrite " << state_;
    LOG_TRACE <<  "Connector::handleWrite " << state_;
    if(state_ == kConnecting){
        int sockfd = removeAndResetChannel();
        int err = sockets::getSocketError(sockfd);
        if(err){
            // debug
            //std::cout << "Connector::handleWrite-SO-ERROR = " << err << util::strerror_tl(err);
            LOG_WARN << "Connector::handleWrite-SO-ERROR = " << err << util::strerror_tl(err);
            retry(sockfd);
        }
        else if(sockets::isSelfConnect(sockfd)){
            // debug
            //std::cout << "Connector:handleWrite-Self connect";
            LOG_WARN << "Connector:handleWrite-Self connect";
            retry(sockfd);
        }
        else{
            setState(kConnected);
            if(connect_){
                newConnectionCallback_(sockfd);
            }
            else{
                sockets::close(sockfd);
            }
        }
    }
    else{
        assert(state_ == kDisConnected);
    }
}


void Connector::handleError() {
    // debug
    //std::cout << "Connector::handleError";
    LOG_ERROR << "Connector::handleError";
    assert(state_ == kConnecting);
    int sockfd = removeAndResetChannel();
    int err = sockets::getSocketError(sockfd);
    // debug
    //std::cout << "SO_ERROR = " << err << " " << util::strerror_tl(err);
    LOG_TRACE << "SO_ERROR = " << err << " " << util::strerror_tl(err);
    retry(sockfd);
}

void Connector::retry(int sockfd){
    sockets::close(sockfd);
    setState(kDisConnected);
    if(connect_){
        LOG_INFO << "Connector::retry-Retry connecting to "
             << serverAddr_.toHostPort() << "in "
             << retryDelayMs_ << " milliseconds. ";
        timerld_ = loop_->runAfter(retryDelayMs_ / 1000.0, std::bind(&Connector::startInLoop, this));
        retryDelayMs_ = std::min(retryDelayMs_ * 2, kMaxRetryDelayMs);
    }
    else{
        LOG_DEBUG << "do not connect";
    }
}

