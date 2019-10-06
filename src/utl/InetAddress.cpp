//
// Created by devinchang on 2019/9/2.
//

#include "InetAddress.h"

#include <string.h>
#include <netinet/in.h>
#include "Socket.h"

static const in_addr_t kInaddrAny = INADDR_ANY;


InetAddress::InetAddress(uint16_t port) {
    memset(&addr_, 0, sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_addr.s_addr = sockets::hostToNet32(kInaddrAny);
    addr_.sin_port = sockets::hostToNet16(port);
}

InetAddress::InetAddress(const std::string &ip, uint16_t port) {
    memset(&addr_, 0, sizeof(addr_));
    sockets::fromHostPort(ip.c_str(), port, &addr_);
}

std::string InetAddress::toHostPort() const {
    char buf[32];
    sockets::toHostPort(buf, sizeof(buf), addr_);
    return buf;
}
