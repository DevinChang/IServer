//
// Created by devinchang on 2019/8/19.
//

#include "Channel.h"
#include <sys/poll.h>
#include <cassert>
#include <iostream>
#include "TimeStamp.h"
#include "EventLoop.h"
#include <poll.h>

const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = POLLIN | POLLPRI;
const int Channel::kWriteEvent = POLLOUT;

Channel::Channel(EventLoop *loop, int fdArg)
               : loop_(loop), fd_(fdArg), events_(0), revents_(0), index_(-1){}

Channel::~Channel() {
    assert(!eventHandling_);
}

void Channel::update(){
    loop_->updateChannel(this);
}

void Channel::handleEvent(TimeStamp recieveTime){
    eventHandling_ = true;
    // POLLNVAL: 描述符不是一个打开的文件,只能用于revents的返回
    if(revents_ & POLLNVAL)
        printf("Channel::handelEvent() POLLNVAL");

    if((revents_ & POLLHUP) && !(revents_ & POLLIN)){
        std::cout << "Channel::handle_event() POLLHUP";
        if(closeCallback_)
            closeCallback_();
    }
    // POLLERR: 发生错误,只能用于revents的返回
    if(revents_ & (POLLERR | POLLNVAL)){
        if(errorCallback_)
            errorCallback_();
    }
    // POLLIN ,POLLPRI : 普通或优先级数据可读
    // POLLHUP : 发生挂起
    if(revents_ & (POLLIN | POLLPRI | POLLHUP)){
        if(readCallback_)
            readCallback_(recieveTime);
    }
    // POLLOUT : 普通数据可写
    if(revents_ & POLLOUT){
        if(writeCallback_)
            writeCallback_();
    }
    eventHandling_ = false;

}
