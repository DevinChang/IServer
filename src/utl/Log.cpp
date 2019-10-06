//
// Created by devinchang on 2019/10/4.
//

#include "Log.h"

#include "CurrentThread.h"
#include "Thread.h"
#include <errno.h>
#include <stdio.h>
#include <sstream>


__thread char t_time[32];
__thread time_t t_lastSecond;


Log::LogLevel initLogLevel(){
    if(::getenv("LOG_TRACE"))
        return Log::TRACE;
    else
        return Log::DEBUG;
}

Log::LogLevel g_logLevel = initLogLevel();

const char *LogLevelNmae[Log::NUM_LOG_LEVELS] = {
        "TRACE ",
        "DEBUG ",
        "INFO  ",
        "WARN  ",
        "ERROR ",
        "FATAL ",
};

void defaultOutput(const char *msg, int len){
    size_t n = fwrite(msg, 1, len, stdout);
    (void)n;
}

void defaultFlush(){
    fflush(stdout);
}

Log::OutputFunc g_output = defaultOutput;
Log::FlushFunc g_flush =defaultFlush;

Log::Impl::Impl(Log::LogLevel level, int savedErrno, const char *file, int line)
             : time_(TimeStamp::now()),
               stream_(),
               level_(level),
               line_(line),
               fullname_(file),
               basename_(NULL)
{
    const char *path_seq_pos = strrchr(fullname_, '/');
    basename_ = (path_seq_pos != NULL) ? path_seq_pos + 1 : fullname_;

    formatTime();
    log::Fmt tid("%5d", CurrentThread::tid());
    assert(tid.length() == 5);
    stream_ << " CurrentThread tid = " << log::T(tid.data(), 5);
    stream_ << " " << log::T(LogLevelNmae[level], 6);

    if(savedErrno != 0){
        stream_ << util::strerror_tl(savedErrno) << "(errno=" << savedErrno << ")";
    }
}

void Log::Impl::formatTime() {
    int64_t microSecondsSinceEpoch = time_.microSecondSinceEpoch();
    time_t seconds = static_cast<time_t >(microSecondsSinceEpoch / TimeStamp::kMicroSecondsPerSecond);
    int microseconds = static_cast<int>(microSecondsSinceEpoch % TimeStamp::kMicroSecondsPerSecond);
    if(seconds != t_lastSecond){
        t_lastSecond = seconds;
        struct tm tm_time;
        ::gmtime_r(&seconds, &tm_time);

        int len = snprintf(t_time, sizeof(t_time), "%4d%02d%02d %02d:%02d:%02d",
                         tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
                         tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);
        assert(len == 17); (void)len;
    }
    log::Fmt us(".%06dZ", microseconds);
    assert(us.length() == 8);
    stream_ << log::T(t_time, 17) << log::T(us.data(), 8);
}

void Log::Impl::finish() {
    stream_ << "-" << basename_ << ":" << line_ << "\n";
}

Log::Log(const char *file, int line) : impl_(INFO, 0, file, line){}

Log::Log(const char *file, int line, Log::LogLevel level): impl_(level, 0, file, line) {}

Log::Log(const char *file, int line, Log::LogLevel level, const char *func): impl_(level, 0, file, line)
{ impl_.stream_ << func << ""; }

Log::Log(const char *file, int line, bool toAbort): impl_(toAbort ? FATAL : ERROR, errno, file, line) {}


Log::~Log() {
    impl_.finish();
    const log::LogStream::Buffer &buf(stream().buffer());
    g_output(buf.data(), buf.length());
    if(impl_.level_ == FATAL){
        g_flush();
        abort();
    }
}

Log::LogLevel Log::logLevel() {
    return g_logLevel;
}

void Log::setLogLevel(Log::LogLevel level) {
    g_logLevel = level;
}

void Log::setOutput(Log::OutputFunc out) {
    g_output = out;
}

void Log::setFlush(Log::FlushFunc flush) {
    g_flush = flush;
}


