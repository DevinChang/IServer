//
// Created by devinchang on 2019/7/30.
//

#include "server.h"
#include <string.h>

namespace server{
    Server::Server(const std::string &host, const int port, const int &listen) {
        servfd = Wrap::Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        struct sockaddr_in servaddr;
        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sinport = htons(port);

        Wrap::Bind(listen, (SA*)&servaddr, sizeof(servaddr));
        Wrap::Listen(listen, LISTENQ);

    }

    int Server::getScokfd() {
        return _servfd;
    }

    int Server::getClient() {
        struct sockaddr_in cliaddr;
        socklen_t client_addr_size = sizeof(cliaddr);
        int cliscoket = accept(_servfd, (struct sockaddr*)&cliaddr, &client_addr_size);
        _clifd.push_back(clisocket);

        char buff[1024];
        std::string host = Wrap::Inet_ntop(AF_INET, &cliaddr, sin_addr, buff, sizeof(buff));
        // port;
    }
}
