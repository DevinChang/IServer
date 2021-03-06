//
// Created by devinchang on 2019/10/6.
//

#include "EPoller.h"
#include "Channel.h"
#include "Log.h"
#include <cassert>
#include <errno.h>
#include <poll.h>
#include <sys/epoll.h>

static_assert(EPOLLIN == POLLIN);
static_assert(EPOLLPRI == POLLPRI);
static_assert(EPOLLOUT == POLLOUT);
static_assert(EPOLLRDHUP == POLLRDHUP);
static_assert(EPOLLERR == POLLERR);
static_assert(EPOLLHUP == POLLHUP);


const int kNew = -1;
const int kAdded = 1;
const int kDeleted = 2;


EPoller::EPoller(EventLoop *loop) :
          ownerLoop_(loop),
          epollfd_(::epoll_create(EPOLL_CLOEXEC)),
          events_(kInitEventListSize){
    if(epollfd_ < 0){
        LOG_SYSATAL << "EPoller::EPoller";
    }
}


EPoller::~EPoller() {
    ::close(epollfd_);
}

TimeStamp EPoller::poll(int timeoutMs, EPoller::ChannelList *activeChannels) {
    int numEvents = ::epoll_wait(epollfd_, &*events_.begin(), static_cast<int>(events_.size()),timeoutMs);
    TimeStamp now(TimeStamp::now());
    if(numEvents > 0){
        LOG_TRACE << numEvents << " events happened";
        fillActiveChannels(numEvents, activeChannels);
        if(util::implicit_cast<size_t>(numEvents) == events_.size()){
            events_.resize(events_.size() * 2);
        }

    }
    else if(numEvents == 0){
        LOG_TRACE << " nothing happened";
    }
    else{
        LOG_ERROR << "EPoller::poll()";
    }
    return now;
}

void EPoller::fillActiveChannels(int numEvents, EPoller::ChannelList *activeChannels) const {
    assert(util::implicit_cast<size_t>(numEvents) <= events_.size());
    for(int i = 0; i < numEvents; i++){
        Channel *channel = static_cast<Channel*>(events_[i].data.ptr);
#ifndef NDEBUG
        int fd = channel->fd();
        auto it = channels_.find(fd);
        assert(it != channels_.end());
        assert(it->second == channel);
#endif
        channel->set_revents(events_[i].events);
        activeChannels->push_back(channel);
    }
}

void EPoller::updateChannel(Channel *channel) {
    assertInLoopThread();
    LOG_TRACE << "fd = " << channel->fd() << " events= " << channel->events();
    const int index = channel->index();
    if(index == kNew || index == kDeleted){
        int fd = channel->fd();
        if(index == kNew){
            assert(channels_.find(fd) == channels_.end());
            channels_[fd] = channel;
        }
        else{
            assert(channels_.find(fd) != channels_.end());
            assert(channels_[fd] == channel);
        }
        channel->set_index(kAdded);
        update(EPOLL_CTL_ADD, channel);
    }
    else{
        int fd = channel->fd(); (void)fd;
        assert(channels_.find(fd) != channels_.end());
        assert(channels_[fd] == channel);
        assert(index == kAdded);
        if(channel->isNoneEvent()){
            update(EPOLL_CTL_DEL, channel);
            channel->set_index(kDeleted);
        }
        else{
            update(EPOLL_CTL_MOD, channel);
        }
    }
}


void EPoller::removeChannel(Channel *channel) {
    assertInLoopThread();
    int fd = channel->fd();
    LOG_TRACE << "fd = " << fd;
    assert(channels_.find(fd) != channels_.end());
    assert(channels_[fd] == channel);
    assert(channel->isNoneEvent());
    int index = channel->index();
    assert(index == kAdded || index == kDeleted);
    size_t n = channels_.erase(fd); (void)n;
    assert(n == 1);

    if(index == kAdded){
        update(EPOLL_CTL_DEL, channel);
    }
    channel->set_index(kNew);
}


void EPoller::update(int opt, Channel *channel) {
    struct epoll_event event;
    memset(&event, 0, sizeof(event));
    event.events = channel->events();
    event.data.ptr = channel;
    int fd = channel->fd();
    if(::epoll_ctl(epollfd_, opt, fd, &event) < 0){
        if(opt == EPOLL_CTL_DEL){
            LOG_SYSERR << "epoll_ctl op = " << opt << " fd = " << fd;
        }
        else{
            LOG_SYSATAL << "epoll_ctl op = " << opt << " fd = " << fd;
        }
    }
}
