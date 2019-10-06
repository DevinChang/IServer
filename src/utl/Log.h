//
// Created by devinchang on 2019/10/4.
//

#ifndef ECHOSERVER_LOG_H
#define ECHOSERVER_LOG_H



#include "Util.h"
#include "TimeStamp.h"


class Log{
public:
    enum LogLevel{
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        NUM_LOG_LEVELS
    };

    Log(const char *file, int line);
    Log(const char *file, int line, LogLevel level);
    Log(const char *file, int line, LogLevel level, const char *func);
    Log(const char *file, int line, bool toAbort);

    ~Log();

    log::LogStream &stream() { return impl_.stream_; }

    static LogLevel logLevel();
    static void setLogLevel(LogLevel level);

    typedef void (*OutputFunc)(const char *msg, int len);
    typedef void (*FlushFunc)();

    static void setOutput(OutputFunc);
    static void setFlush(FlushFunc);
private:
    class Impl {
    public:
        typedef Log::LogLevel LogLevel;

        Impl(LogLevel level, int old_errno, const char *file, int line);

        void formatTime();

        void finish();

        TimeStamp time_;
        log::LogStream stream_;
        LogLevel level_;
        int line_;
        const char *fullname_;
        const char *basename_;
    };
    Impl impl_;
};

#define LOG_TRACE if(Log::logLevel() <= Log::TRACE) \
    Log(__FILE__, __LINE__, Log::TRACE, __func__).stream()
#define LOG_DEBUG if(Log::logLevel() <= Log::DEBUG) \
    Log(__FILE__, __LINE__, Log::DEBUG, __func__).stream()
#define LOG_INFO if(Log::logLevel() <= Log::INFO) \
    Log(__FILE__, __LINE__).stream()

#define LOG_WARN Log(__FILE__, __LINE__, Log::WARN).stream()
#define LOG_ERROR Log(__FILE__, __LINE__, Log::ERROR).stream()
#define LOG_FATAL Log(__FILE__, __LINE__, Log::FATAL).stream()
#define LOG_SYSERR Log(__FILE__, __LINE__, false).stream()
#define LOG_SYSATAL Log(__FILE__, __LINE__, true).stream()


const char *strerror_tl(int savedErrno);

#define CHECK_NOTNULL(val) CheckNotNull(__FILE__, __LINE__, "'" #val "' Must be non NULL", (val))

template <typename T>
T *CheckNotNull(const char *file, int line, const char *names, T *ptr){
    if(ptr == NULL){
        Log(file, line, Log::FATAL).stream() << names;
    }
    return ptr;
}


#endif //ECHOSERVER_LOG_H
