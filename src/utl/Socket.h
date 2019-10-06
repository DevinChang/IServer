//
// Created by devinchang on 2019/9/2.
//

#ifndef INC_315SERVER_SOCKET_H
#define INC_315SERVER_SOCKET_H

#include <arpa/inet.h>
// 在主机和大小端字节序之间转换值
#include <endian.h>
#include <sys/socket.h>
#include <unistd.h>

class InetAddress;

struct tcp_info;

namespace sockets {


class Socket {
public:
    explicit Socket(int sockfd) : sockfd_(sockfd) {}

    ~Socket();

    int fd() const { return sockfd_; }

    void Bind(const InetAddress &localaddr);

    void Listen();

    int Accept(InetAddress *peeraddr);

    void setReuseAddr(bool on);

    void setTCPNoDelay(bool on);

    void shutdownWrite();

    // 10/6 new add
    bool getTCPInfo(struct tcp_info *) const;
    bool getTCPInfoString(char *buf, int len) const;

    void setKeepAlive(bool on);
private:
    const int sockfd_;
};

/* htobe nn：从主机字节序转换为big-endian
 * htole nn：从主机字节序转换为little-endian
 * be nn toh：从big-endian顺序转换为host字节序
 * le nn toh：从little-endian顺序转换为host字节序
 * */

inline uint64_t hostToNet64(uint64_t host64){
    return htobe64(host64);
}

inline uint32_t hostToNet32(uint32_t host32){
    return htonl(host32);
}

inline uint16_t hostToNet16(uint16_t host16){
    return htons(host16);
}

inline uint64_t netToHost64(uint64_t net64){
    return be64toh(net64);
}

inline uint32_t netToHost32(uint32_t net32){
    return ntohl(net32);
}


inline uint16_t netToHost16(uint16_t net16){
    return ntohs(net16);
}

int createNonblockingOrDie();

// 9/26 new add
int connect(int sockfd, const struct sockaddr_in &addr);

void bindOrDie(int sockfd, const struct sockaddr_in &addr);

void listenOrDie(int sockfd);

int accept(int sockfd, struct sockaddr_in *addr);

void close(int sockfd);

void toHostPort(char *buf, size_t size, const struct sockaddr_in &addr);

void fromHostPort(const char *ip, uint16_t port, struct sockaddr_in *addr);

struct sockaddr_in getLocalAddr(int sockfd);
struct sockaddr_in getPeerAddr(int sockfd);

int getSocketError(int sockfd);

bool isSelfConnect(int sockfd);

}


#endif //INC_315SERVER_SOCKET_H
