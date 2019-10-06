//
// Created by devinchang on 2019/8/20.
//

#include "Poller.h"
#include "Channel.h"
#include <poll.h>
//#include <assert.h>
#include <cassert>
#include "Util.h"
#include "Log.h"


Poller::Poller(EventLoop *loop): ownerLoop_(loop) {}


Poller::~Poller(){}


TimeStamp Poller::poll(int timeoutMs, ChannelList *activeChannels){
    int numEvents = ::poll(&*pollfds_.begin(), pollfds_.size(), timeoutMs);
    TimeStamp now(TimeStamp::now());
    if(numEvents > 0){
        // debug
        //printf("%d events happened", numEvents);
        LOG_TRACE << numEvents << " events happended";
        fillActiveChannels(numEvents, activeChannels);
    }
    else if(numEvents == 0){
        //printf("nothing happened");
        LOG_TRACE << " nothing happended";
    }
    else{
        // 返回-1表示poll出错
        //printf("Poller::poll error");
        LOG_SYSERR << "Poller::poll()";
    }
    return now;
}

/*         struct pollfd{
 *             int fd;
 *             short events;
 *             short revents;
 *         }
 *         测试的条件由events指定,
 *         revents返回描述符的状态
 * */
void Poller::fillActiveChannels(int numEvents, ChannelList *activeChannels) const{
    for(auto pfd = pollfds_.cbegin(); pfd != pollfds_.cend() && numEvents > 0; ++pfd){
        if(pfd->revents > 0){
            --numEvents;
            auto ch = channels_.find(pfd->fd);
            assert(ch != channels_.end());
            Channel *channel = ch->second;
            assert(channel->fd() == pfd->fd);
            channel->set_revents(pfd->revents);
            activeChannels->push_back(channel);
        }
    }
}


void Poller::updateChannel(Channel *channel) {
    assertInLoopThread();
    //printf("fd = %d events = %d", channel->fd(), channel->events());
    LOG_TRACE << "fd = " << channel->fd() << " events= " << channel->events();
    if(channel->index() < 0){
        // 新加事件到pollfds_
        assert(channels_.find(channel->fd()) == channels_.end());
        struct pollfd pfd;
        pfd.fd = channel->fd();
        pfd.events = static_cast<short>(channel->events());
        pfd.revents = 0;
        pollfds_.push_back(pfd);
        int idx = static_cast<int>(pollfds_.size())-1;
        channel->set_index(idx);
        channels_[pfd.fd] = channel;
    }
    else{
        // 已经存在需要更新channel
        assert(channels_.find(channel->fd()) != channels_.end());
        assert(channels_[channel->fd()] == channel);
        int idx = channel->index();
        assert(0 <= idx && idx < static_cast<int>(pollfds_.size()));
        struct pollfd &pfd = pollfds_[idx];
        // 9/10 modify
        //assert(pfd.fd == channel->fd() || pfd.fd == -1);
        assert(pfd.fd == channel->fd() || pfd.fd == -channel->fd()-1);
        pfd.events = static_cast<short>(channel->events());
        pfd.revents = 0;
        if(channel->isNoneEvent()){
            // 9/10 modify
            //pfd.fd = -1;
            pfd.fd = channel->fd()-1;
        }
    }
}


void Poller::removeChannel(Channel *channel) {
    assertInLoopThread();
    LOG_TRACE << "fd = " << channel->fd();
    assert(channels_.find(channel->fd()) != channels_.end());
    assert(channels_[channel->fd()] == channel);
    assert(channel->isNoneEvent());
    int idx = channel->index();
    assert(0 <= idx && idx < static_cast<int>(pollfds_.size()));
    const struct pollfd &pfd = pollfds_[idx];(void)pfd;
    assert(pfd.fd == -channel->fd() - 1 && pfd.events == channel->events());
    size_t n = channels_.erase(channel->fd());
    assert(n == 1); (void)n;
    if(util::implicit_cast<size_t>(idx) == pollfds_.size() - 1){
        pollfds_.pop_back();
    }
    else{
        int channelAtEnd = pollfds_.back().fd;
        // iter_swap交换两个两个迭代器,查阅资料发现与swap并无太大区别
        //swap(pollfds_.begin() + idx, pollfds_.end()-1);
        iter_swap(pollfds_.begin() + idx, pollfds_.end()-1);
        if(channelAtEnd < 0){
            channelAtEnd = -channelAtEnd - 1;
        }
        channels_[channelAtEnd]->set_index(idx);
        pollfds_.pop_back();
    }
}
