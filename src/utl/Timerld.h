//
// Created by devinchang on 2019/8/25.
//

#ifndef INC_315SERVER_TIMERLD_H
#define INC_315SERVER_TIMERLD_H

#include "stdint.h" // 包含了int64_t
#include "stdio.h"


class Timer;

// Timerld表示一个定时器的整体,有定时器和序列号
class Timerld {
public:
    Timerld(Timer *timer = NULL, int64_t seq = 0) : timer_(timer), sequence_(seq){}

    friend class TimerQueue;
private:
    //Timer *value_;
    Timer *timer_;
    int64_t sequence_;
};


#endif //INC_315SERVER_TIMERLD_H
