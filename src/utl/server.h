//
// Created by devinchang on 2019/7/30.
//

#ifndef INC_315SERVER_SERVER_H
#define INC_315SERVER_SERVER_H

#include "utl.h"
#include <vector>

namespace server{
    class Server{
    public:
        Server(const std::string &host, const int port, const int &listen = 8);
        int getScokfd();
        int getClient();
        ~Server(){ Close(servfd)}
    private:
        int _servfd;
        // client连接有好多个,故用vector来存储
        std::vector<int> _clifd;
    };

    // confuse!
    class Protocal{
    public:
        int makeConnection();
        int loseConnection();

        int connectionMade();
        int connectionLoss();
    private:
        int clifd;
        int servfd;
        std::string host;
        int port;
    };
}

#endif //INC_315SERVER_SERVER_H
