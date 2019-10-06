//
// Created by devinchang on 2019/8/20.
//

#ifndef INC_315SERVER_POLLER_H
#define INC_315SERVER_POLLER_H

#include <vector>
#include <map>
//#include "Channel.h"
#include "EventLoop.h"
#include "TimeStamp.h"

struct pollfd;

class Channel;

// Poller是IO多路复用的封装,不负责事件分发
// Poller支持poll和epoll两种模式
// Poller是EventLopp的间接成员
class Poller {
public:
    typedef std::vector<Channel*> ChannelList;

    Poller(EventLoop *loop);
    ~Poller();

    TimeStamp poll(int timoutMs, ChannelList *activeChannels);

    // 负责维护和更新pollfd数组
    void updateChannel(Channel *channel);
    //
    void assertInLoopThread(){}
    //
    void removeChannel(Channel *channel);
private:
    // 找出活动的pollfd,并把其对应的Channel填入activeChannel
    void fillActiveChannels(int numEvents, ChannelList* activeChannels) const;

    typedef std::vector<struct pollfd> PollFdList;
    typedef std::map<int, Channel*> ChannelMap;

    // IO线程调用的EventLoop
    EventLoop* ownerLoop_;
    // 缓存pollfd数组
    PollFdList pollfds_;
    ChannelMap channels_;

    //

};


#endif //INC_315SERVER_POLLER_H
