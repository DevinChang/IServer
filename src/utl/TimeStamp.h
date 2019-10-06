//
// Created by devinchang on 2019/8/21.
//

#ifndef INC_315SERVER_TIMESTAMP_H
#define INC_315SERVER_TIMESTAMP_H

#include <string>




class TimeStamp {
public:
    TimeStamp() : microSecondsSinceEpoch_(0){}

    explicit TimeStamp(int64_t microSecondsSinceEpoch) : microSecondsSinceEpoch_(microSecondsSinceEpoch){}

    void swap(TimeStamp &that){std::swap(microSecondsSinceEpoch_, that.microSecondsSinceEpoch_);}

    std::string toString() const;
    std::string toFormattedString() const;

    bool valid() const { return microSecondsSinceEpoch_ > 0;}

    // int64_t: 定宽整数类型,由跨平台导致的整数类型特别是int相关的类型在不同机器的平台上长度不同
    int64_t microSecondSinceEpoch() const { return microSecondsSinceEpoch_; }

    static TimeStamp invalid();

    // 表示1秒，1秒=1000000微妙
    static const int kMicroSecondsPerSecond = 1000 * 1000;

    static TimeStamp now();

private:
    // 微妙
    int64_t microSecondsSinceEpoch_;
};

inline bool operator<(TimeStamp lhs, TimeStamp rhs){
    return  lhs.microSecondSinceEpoch() < rhs.microSecondSinceEpoch();
}

inline bool operator==(TimeStamp lhs, TimeStamp rhs){
    return lhs.microSecondSinceEpoch() == rhs.microSecondSinceEpoch();
}

inline double timeDifference(TimeStamp high, TimeStamp low){
    int64_t diff = high.microSecondSinceEpoch() - low.microSecondSinceEpoch();
    // static_cast: 任何具有明确定义的类型转换,只要不包含底层const(const *p),都可以使用.
    // 当需要把较大的类型赋值给较小的类型时,static_cast非常有用.
    return static_cast<double>(diff) / TimeStamp::kMicroSecondsPerSecond;
}

inline TimeStamp addTime(TimeStamp timeStamp, double seconds){
    int64_t delta = static_cast<int64_t>(seconds * TimeStamp::kMicroSecondsPerSecond);
    return TimeStamp(timeStamp.microSecondSinceEpoch() + delta);
}
#endif //INC_315SERVER_TIMESTAMP_H
