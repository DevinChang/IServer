//
// Created by devinchang on 2019/9/2.
//

#include "Socket.h"

#include "InetAddress.h"
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include "Log.h"


namespace sockets{
    typedef struct sockaddr SA;

    // 为什么多加一步这个转换?
    const SA* sockaddr_cast(const struct sockaddr_in *addr){
        return static_cast<const SA*>(static_cast<const void*>(addr));
    }

    SA* sockaddr_cast(struct sockaddr_in *addr){
        return static_cast<SA*>(static_cast<void *>(addr));
    }

    void setNonBlockAndCloseOnExec(int sockfd){
        /* F_GETFD:取得与文件描述符fd联合的close-on-exec标志
         * F_GETFL:取得fd的文件状态标志
         * */
        int flags = ::fcntl(sockfd, F_GETFL, 0);
        flags |= O_NONBLOCK;
        int ret = ::fcntl(sockfd, F_SETFL, flags);
        // close-on-exec
        flags = ::fcntl(sockfd, F_GETFD, 0);
        flags |= FD_CLOEXEC;
        ret = ::fcntl(sockfd, F_SETFD, flags);

    }

    int createNonblockingOrDie(){
        // 创建非阻塞的socket
        //int sockfd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        int sockfd = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
        if(sockfd < 0){
            //printf("sockets:createNonblockingOrDie");
            LOG_SYSATAL << "sockets::createNonblockingOrDie";
        }
        //setNonBlockAndCloseOnExec(sockfd);
        return sockfd;
    }

    void bindOrDie(int sockfd, const struct sockaddr_in &addr){
        int ret = ::bind(sockfd, sockaddr_cast(&addr), sizeof(addr));
        if(ret < 0){
            //printf("sockets::bindOrDie");
            LOG_SYSATAL << "sockets::bindOrDie";
        }
    }

    void listenOrDie(int sockfd){
        int ret = ::listen(sockfd, SOMAXCONN);
        if(ret < 0){
            //printf("sockets::listenOrDie");
            LOG_SYSATAL << "sockets::listenOrDie";
        }
    }

    // ipv4的套接字结构为struct sockaddr_in
    // 通用的套接字结构为struct sockaddr;
    int accept(int sockfd, struct sockaddr_in *addr){
        socklen_t addrlen = sizeof(addr);
#if VALGRIND
        int connfd = ::accept(sockfd, sockaddr_cast(addr), &addrlen);
        setNonBlockAndCloseOnExec(connfd);
#else
        int connfd = ::accept4(sockfd, sockaddr_cast(addr), &addrlen, SOCK_NONBLOCK | SOCK_CLOEXEC);
#endif
        if (connfd < 0){
            int saveErrno = errno;
            //printf("Socket::accept");
            LOG_SYSERR << "Socket::accept";
            switch(saveErrno){
                case EAGAIN:
                case ECONNABORTED:
                case EINTR:
                case EPROTO:
                case EPERM:
                case EMFILE:
                    errno = saveErrno;
                    break;
                case EBADF:
                case EOPNOTSUPP:
                    //printf("unexpected error of accept");
                    LOG_FATAL << "unexpected error of accept";
                    break;
                default:
                    //printf("unknown error of accept");
                    LOG_FATAL << "unknown error of accept";
                    break;
            }
        }
        return connfd;
    }


    void close(int sockfd){
        if(::close(sockfd) < 0){
            //printf("sockets::close");
            LOG_SYSERR << "sockets::close";
        }
    }

    void toHostPort(char *buf, size_t size, const struct sockaddr_in &addr){
        char host[INET_ADDRSTRLEN] = "INVALID";
        ::inet_ntop(AF_INET, &addr.sin_addr, host, sizeof(host));
        uint16_t port = netToHost16(addr.sin_port);
        snprintf(buf, size, "%s:%u", host, port);
    }

    void fromHostPort(const char *ip, uint16_t port, struct sockaddr_in *addr){
        addr->sin_family = AF_INET;
        addr->sin_port = hostToNet16(port);
        if(::inet_pton(AF_INET, ip, &addr->sin_addr) <= 0){
            //printf("sockets::fromHostPort");
            LOG_SYSERR << "sockets::fromHostPort";
        }
    }

    Socket::~Socket() {
        close(sockfd_);
    }

    void Socket::Bind(const InetAddress &localaddr) {
        bindOrDie(sockfd_, localaddr.getSockAddrInet());
    }

    void Socket::Listen() {
        listenOrDie(sockfd_);
    }

    int Socket::Accept(InetAddress *peeraddr) {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        int connfd = accept(sockfd_, &addr);
        if(connfd < 0){
            peeraddr->setSockAddrInet(addr);
        }
        return connfd;
    }

    void Socket::setReuseAddr(bool on) {
        int optval = on ? 1 : 0;
        ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    }

    void Socket::setTCPNoDelay(bool on) {
        int optval = on ? 1 : 0;
        ::setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval));
    }

    void Socket::shutdownWrite() {
        if(::shutdown(sockfd_, SHUT_WR) < 0){
            LOG_SYSERR << "sockets::shutdownWrite";
        }
    }

    struct sockaddr_in getLocalAddr(int sockfd){
        struct sockaddr_in localaddr;
        memset(&localaddr, 0, sizeof(localaddr));
        socklen_t addrlen = sizeof(localaddr);
        if(::getsockname(sockfd, sockaddr_cast(&localaddr), &addrlen) < 0){
            LOG_SYSERR << "sockets::getLocalAddr";
        }
        return localaddr;
    }

    struct sockaddr_in getPeerAddr(int sockfd){
        struct sockaddr_in peeraddr;
        memset(&peeraddr, 0, sizeof(peeraddr));
        socklen_t addrlen = sizeof(peeraddr);
        if(::getpeername(sockfd, sockaddr_cast(&peeraddr), &addrlen) < 0){
            //printf("sockets::getPeerAddr");
            LOG_SYSERR << "sockets::getPeerAddr";
        }
        return peeraddr;
    }

    int getSocketError(int sockfd){
        int optval;
        socklen_t optlen = sizeof(optval);
        if(::getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &optval, &optlen) < 0)
            return errno;
        else
            return optval;
    }

    int connect(int sockfd, const struct sockaddr_in &addr){
        return ::connect(sockfd, sockaddr_cast(&addr), sizeof(addr));
    }

    bool isSelfConnect(int sockfd){
        struct sockaddr_in localaddr = getLocalAddr(sockfd);
        struct sockaddr_in peeraddr = getPeerAddr(sockfd);
        return localaddr.sin_port == peeraddr.sin_port &&
               localaddr.sin_addr.s_addr == peeraddr.sin_addr.s_addr;
    }

    bool Socket::getTCPInfo(struct tcp_info *tcpi) const {
        socklen_t len = sizeof(*tcpi);
        memset(tcpi, 0, len);
        return ::getsockopt(sockfd_, SOL_TCP, TCP_INFO, tcpi, &len) == 0;
    }

    bool Socket::getTCPInfoString(char *buf, int len) const {
        struct tcp_info tcpi;
        bool ok = getTCPInfo(&tcpi);
        if(ok){
            snprintf(buf, len, "unrecovered=%u "
                               "rto=%u ato=%u snd_mss=%u rcv_mss=%u "
                               "lost=%u retrans=%u rtt=%u rttvar=%u "
                               "sshthresh=%u cwnd=%u total_retrans=%u",
                     tcpi.tcpi_retransmits,  // Number of unrecovered [RTO] timeouts
                     tcpi.tcpi_rto,          // Retransmit timeout in usec
                     tcpi.tcpi_ato,          // Predicted tick of soft clock in usec
                     tcpi.tcpi_snd_mss,
                     tcpi.tcpi_rcv_mss,
                     tcpi.tcpi_lost,         // Lost packets
                     tcpi.tcpi_retrans,      // Retransmitted packets out
                     tcpi.tcpi_rtt,          // Smoothed round trip time in usec
                     tcpi.tcpi_rttvar,       // Medium deviation
                     tcpi.tcpi_snd_ssthresh,
                     tcpi.tcpi_snd_cwnd,
                     tcpi.tcpi_total_retrans);  // Total retransmits for entire connection
        }
        return ok;
    }

    void Socket::setKeepAlive(bool on) {
        int optval = on ? 1 : 0;
        ::setsockopt(sockfd_, SOL_SOCKET, SO_KEEPALIVE, &optval, static_cast<socklen_t >(sizeof(optval)));
    }
}
