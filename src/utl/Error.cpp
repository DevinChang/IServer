//
// Created by devinchang on 2019/7/30.
//

#include "Error.h"
#include <syslog.h>

namespace Error{
int deamon_proc;

static err_doit(int, int, const char *, va_list);

void err_ret(const char *fmt, ...){
    va_list ap;

    va_start(ap, fmt);
    err_doit(1, LOG_INFO, fmt, ap);
    va_end(ap);
}
void err_sys(const char *fmt, ...){
    va_list ap;

    va_start(ap, fmt);
    err_doit(1, LOG_ERR, fmt, ap);
    va_end(ap);
    exit(1);
}

void err_dump(const char *fmt, ...){
    va_list ap;

    va_start(ap, fmt);
    err_doit(1, LOG_ERR, fmt, ap);
    va_end(ap);
    abort();
    exit(1)
}

void err_msg(const char *fmt, ...){
    va_list ap;

    va_start(ap, fmt);
    err_doit(0, LOG_INFO, fmt, ap);
    va_end(ap);
}

void err_quit(const char *fmt, ...){
    va_list ap;

    va_start(ap, fmt);
    err_doit(0, LOG_ERR, fmt, ap);
    va_end(ap);
    exit(1);
}

static void err_doit(int errnoflag, int level, const char *fmt, va_list ap){
    int errnosave = errno;
    char buf[MAXLINE + 1];
#ifdef HAVE_VSNPRINTF
    vsnprintf(buf, MAXLINE, fmt, ap);
#else
    vsprintf(buf, fmt, ap);
#endif
    int n = strlen(buf);
    if(errnoflag)
        snprintf(buf + n, MAXLINE - n, ": %s", strerror(errno_save));
    strcat(buf, "\n");
    if(deamon_proc)
        syslog(level, buf);
    else{
        fflush(stdout);
        fputs(buf, stderr);
        fflush(stderr);
    }
    return;
}

}
