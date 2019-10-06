//
// Created by devinchang on 2019/9/2.
//

#ifndef INC_315SERVER_INETADDRESS_H
#define INC_315SERVER_INETADDRESS_H

#include <netinet/in.h>
#include <string>

class InetAddress {
public:
    explicit InetAddress(uint16_t port);

    InetAddress(const std::string &ip, uint16_t port);

    InetAddress(const struct sockaddr_in &addr) : addr_(addr){}

    std::string toHostPort() const;

    const struct sockaddr_in &getSockAddrInet() const{ return addr_; }

    void setSockAddrInet(const struct sockaddr_in &addr) { addr_ = addr; }

private:
    struct sockaddr_in addr_;

};


#endif //INC_315SERVER_INETADDRESS_H
