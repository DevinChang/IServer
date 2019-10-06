//
// Created by devinchang on 2019/10/6.
//

#ifndef FILETRANSFER_EPOLLER_H
#define FILETRANSFER_EPOLLER_H

#include <map>
#include <vector>

#include "TimeStamp.h"
#include "EventLoop.h"

struct epoll_event;
class Channel;

class EPoller {
public:
    typedef std::vector<Channel*> ChannelList;
public:
    EPoller(EventLoop *loop);
    ~EPoller();

    TimeStamp poll(int timeoutMs, ChannelList *activeChannels);
    void updateChannel(Channel *channel);
    void removeChannel(Channel *channel);
    void assertInLoopThread() { ownerLoop_->assertInLoopThread(); }
private:
    typedef std::vector<struct epoll_event> EventList;
    typedef std::map<int, Channel*> ChannelMap;

    static const int kInitEventListSize = 16;

    void fillActiveChannels(int numEvents, ChannelList *activeChannels) const;
    void update(int opt, Channel *channel);

    EventLoop *ownerLoop_;
    int epollfd_;
    EventList events_;
    ChannelMap channels_;
};


#endif //FILETRANSFER_EPOLLER_H
