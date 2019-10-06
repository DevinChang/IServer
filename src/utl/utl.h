//
// Created by devinchang on 2019/7/30.
//

#ifndef INC_315SERVER_UTL_H
#define INC_315SERVER_UTL_H

#include <iostream>
#include <string>
#include <map>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <getopt.h>
#include <cstdarg>
#include <sys/syscall.h>
#include <cassert>
#include <vector>
#include <set>

#define MAXLINE 1024



namespace Wrap {

    int Socket(int family, int type, int protocol);

    int Close(int fd);

    int Bind(int sockfd, const struct sockaddr *sa, socklen_t salen);

    int Listen(int sockfd, int backlog);

    ssize_t Write(int sockfd, const std::string &str);

    in_addr_t Inet_addr(const std::string &host);

    std::string Inet_ntop(int family, const void *addrptr, char *strptr, size_t len);
}

namespace Error{
    // 以后用可变参数实现
    //static void err_doit(int errnoflag, int level, const std::string &fmt){
    //    int errno_save = errno;
    //    char buf[MAXLINE + 1];

    //}
    //template <typename ... Args>
    //void err_ret(const std::string &fmt){

    //}
    void err_ret(const char *fmt, ...);
    void err_dump(const char *fmt, ...);
    void err_quit(const char *fmt, ...);
    void err_ret(const char *fmt, ...);
    void err_sys(const char *fmt, ...);

}


#endif //INC_315SERVER_UTL_H
