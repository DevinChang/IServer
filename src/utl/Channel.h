//
// Created by devinchang on 2019/8/19.
//

#ifndef INC_315SERVER_CHANNEL_H
#define INC_315SERVER_CHANNEL_H

#include <functional>

class EventLoop;
class TimeStamp;


/* 每个Channel对象只属于一个IO线程, 且自始至终只负责一个descriptor(socket, eventfd,
 * timerfd, signalfd, etc),但是并不拥有此descriptor,也不会在析构的时候关闭.
 * */
class Channel {
public:
    typedef std::function<void()> EventCallback;
    typedef std::function<void(TimeStamp)> ReadEventCallback;

    Channel(EventLoop *loop, int fd);
    ~Channel();

    // 处理事件
    // 9/10 modify
    void handleEvent(TimeStamp recieveTime);
    void setReadCallback(const ReadEventCallback & cb){ readCallback_ = cb; }
    //
    void setWriteCallback(const EventCallback & cb){ writeCallback_ = cb; }
    void setErrorCallback(const EventCallback & cb){ errorCallback_ = cb; }
    void setCloseCallback(const EventCallback & cb){ closeCallback_ = cb; }

    int fd() const { return fd_;}

    int events() const { return events_; }

    void set_revents(int revt) { revents_ = revt;}

    bool isNoneEvent() const { return events_ == kNoneEvent; }

    void enableReading() { events_ |= kReadEvent; update(); }
    // level trigger
    void enableWriting() { events_ |= kWriteEvent; update(); }
    void disableWriting() { events_ &= ~kWriteEvent; update(); }

    void disableAll() { events_ = kNoneEvent; update(); }
    bool isWriting() const { return events_ & kWriteEvent; }

    // 用于Poller
    int index(){ return index_; }
    void set_index(int idx){ index_ = idx; }

    EventLoop *ownerLoop(){ return loop_; }
private:
    //
    void update();

    static const int kNoneEvent;
    static const int kReadEvent;
    static const int kWriteEvent;

    EventLoop *loop_;
    const int fd_;
    // Channel关心的IO事件,由用户设置
    int events_;
    // 目前活动的事件,由EventLoop或者Poller设置
    int revents_;
    // 用于Poller
    int index_;

    bool eventHandling_;

    // 用于读,写,错误的回调
    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback errorCallback_;
    EventCallback closeCallback_;
};


#endif //INC_315SERVER_CHANNEL_H
