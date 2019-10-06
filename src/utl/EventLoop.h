//
// Created by devinchang on 2019/8/17.
//

#ifndef INC_315SERVER_EVENTLOOP_H
#define INC_315SERVER_EVENTLOOP_H

#include "Thread.h"
#include "CurrentThread.h"
// 8/27 new add
#include "TimeStamp.h"
#include "Timerld.h"

#include <memory>
#include "utl.h"
#include "Mutex.h"

// 前向声明
class Channel;
// 10/6 modify: Poller->EPoller
class EPoller;
class TimerQueue;

class EventLoop {
public:
    typedef std::function<void()> TimerCallback;
    typedef std::function<void()> Functor;
    EventLoop();
    ~EventLoop();
public:
    // 事件循环必须在IO线程执行
    void loop();
    // 判断是否在事件循环线程
    bool isInLoopThread() const { return threadid_ == CurrentThread::tid(); }
    //
    void assertInLoopThread(){
        if(!isInLoopThread())
            abortNotInLoopThread();
    }

    // 8/20 new add quit
    void updateChannel(Channel *channel);
    void quit();
    // 9/8 new add
    void removeChannel(Channel *channel);

    // 8/27 new add
    TimeStamp pollReturnTime() const { return pollReturnTime_;}

    Timerld runAt(const TimeStamp &time, const TimerCallback &cb);

    Timerld runAfter(double delay, const TimerCallback &cb);

    Timerld runEvery(double interval, const TimerCallback &cb);

    // 8/28 new add
    // runInLoop是使EventLoop在其IO线程内执行某个用户任务回调,若是在当前线程调用则会同步,若是在其他线程
    // 调用,cb会加入到队列中
    void runInLoop(const Functor &cb);
    // 将cb放入到队列,必要时唤醒IO线程
    void queueInLoop(const Functor &cb);
    //
    void wakeup();

    // 9/16 new add
    void cancel(Timerld timerld);
private:
    void abortNotInLoopThread();
    // 8/28 new add
    // wake up
    void handleRead();
    // 在临界区内一次调用Functors
    void doPendingFunctors();

    // 具有原子性
    bool callingPendingFunctors_;
    // 8/20 new add
    typedef std::vector<Channel*> ChannelList;
    // 用于结束EventLopp的loop调用,具有原子性
    bool quit_;
    // 用unique_ptr来表示poller是一个智能指针,表示其对象具有独占权
    std::unique_ptr<EPoller> poller_;
    ChannelList activeChannels_;

    // 表示是否处于事件循环,具有原子性
    bool looping_;
    const pid_t threadid_;
    int wakeupFd_;
    std::unique_ptr<Channel> wakeupChannel_;
    MutexLock mutex_;
    std::vector<Functor> pendingFunctors_;
    // 8/27 new add
    TimeStamp pollReturnTime_;
    std::unique_ptr<TimerQueue>timerQueue_;
};


#endif //INC_315SERVER_EVENTLOOP_H
