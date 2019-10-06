//
// Created by devinchang on 2019/8/21.
//

#include "TimeStamp.h"

#include <sys/time.h>
#include <stdio.h>
// 提供了各种位宽的整数类型输入输出时的转换宏标志
#include <inttypes.h>



// c++11支持的静态断言: 进行编译时断言检查
// static_assert声明可以出现在命名空间和块作用域中,也可以在类中
static_assert(sizeof(TimeStamp) == sizeof(int64_t), "TimeStamp is name size as int64_t");


std::string TimeStamp::toString() const{
    char buf[32] = {0};
    int64_t seconds = microSecondsSinceEpoch_ / kMicroSecondsPerSecond;
    int64_t microseconds = microSecondsSinceEpoch_ % kMicroSecondsPerSecond;
    // PRId64是跨平台的一种方法,int64_t表示64位整数,在32位系统中是long long int,在64位系统是long int
    // 所以在不同平台打印int64_t的方法不同:
    // printf("%ld", value) // 64 bit
    // printf("%lld", value) // 32 bit
    // 为了解决跨平台的问题,使用PRId64可以有效的解决.不过,使用该宏时,需要在编译的时候加
    // __STDC_FORMAT_MACROS宏
    snprintf(buf, sizeof(buf)-1, "%"PRId64".%06"PRId64"", seconds, microseconds);
    return buf;
}



std::string TimeStamp::toFormattedString() const {
    char buf[64] = {0};
    time_t seconds = static_cast<time_t>(microSecondsSinceEpoch_ / kMicroSecondsPerSecond);
    int microseconds = static_cast<int>(microSecondsSinceEpoch_ % kMicroSecondsPerSecond);
    // tm结构在time.h定义
    struct tm tm_time;
    /* struct tm *gmtime(const time_t *timep);
     * struct tm *gmtime_r(const time_t *timep, struct tm *result);
     * struct tm *localtime(const time_t *timep);
     * struct tm *localtime_r(const time_t *timep, struct tm *result);
     */
    // gmtime()将日历事件timep转换为UTC时间,gmtime_r功能相同,但可以将结果存储到用户提供的结构体中,localtime_r同理
    // localtime() 将日历时间timep转换为用户指定的时区的时间
    gmtime_r(&seconds, &tm_time);
    snprintf(buf, sizeof(buf), "%4d%02d%02d %02d:%02d:%02d.%06d",
            tm_time.tm_year+1900, tm_time.tm_mon+1, tm_time.tm_mday,
            tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec, microseconds);
    return buf;
}

TimeStamp TimeStamp::now() {
    /* struct timeval{
     *     __time_t tv_sec; //seconds 为Epoch到创建struct timeval时的描述
     *     __suseconds_t tv_usec; // microseconds
     * }
     * */
    struct timeval tv;
    // int gettimeofday(struct timeval *tv, struct timezone *tz) 获取当前时间,保存到timeval
    gettimeofday(&tv, NULL);
    int64_t seconds = tv.tv_sec;
    return TimeStamp(seconds * kMicroSecondsPerSecond + tv.tv_usec);
}

TimeStamp TimeStamp::invalid() {
    return TimeStamp();
}
