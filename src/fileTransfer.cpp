//
// Created by devinchang on 2019/9/10.
//

#include "utl/Log.h"
#include "utl/EventLoop.h"
#include "utl/TCPServer.h"

#include <stdio.h>
#include <unistd.h>
#include <memory>
#include <boost/any.hpp>


const int kBufSize = 64 * 1024;
const char *g_file = NULL;
typedef std::shared_ptr<FILE> FilePtr;

void onHighWaterMark(const TCPConnectionPtr &conn, size_t len){
    LOG_INFO << "HighWaterMark " << len;
}

void onConnection(const TCPConnectionPtr &conn){
    LOG_INFO << "FileServer-" << conn->peerAddress().toHostPort() << "->"
             << conn->localAddress().toHostPort() << " is "
             << (conn->connected() ? "UP" : "DOWN");
    if(conn->connected()){
        LOG_INFO << "FileServer-Sending file " << g_file
                 << " to " << conn->peerAddress().toHostPort();
        conn->setHighWaterMarkCallback(onHighWaterMark, kBufSize+1);

        FILE *fp = ::fopen(g_file, "rb");
        if(fp){
            FilePtr ctx(fp, ::fclose);
            conn->setContext(ctx);
            char buf[kBufSize];
            size_t nread = ::fread(buf, 1, sizeof(buf), fp);
            conn->send(buf, static_cast<int>(nread));
        }
        else{
            conn->shutdown();
            LOG_INFO << "FileServer-no such file";
        }
    }
}

void onWriteComplete(const TCPConnectionPtr &conn){
    const FilePtr &fp = boost::any_cast<const FilePtr&>(conn->getContext());
    //const FilePtr &fp = (const FilePtr&)(conn->getContext());

    char buf[kBufSize];
    size_t nread = ::fread(buf, 1, sizeof(buf), util::get_pointer(fp));
    if(nread > 0){
        conn->send(buf, static_cast<int>(nread));
    }
    else{
        conn->shutdown();
        LOG_INFO << "FileServer-done";
    }
}

int main(int argc, char *argv[]){
    LOG_INFO << "pid = " << getpid();
    if(argc > 1){
        g_file = argv[1];

        EventLoop loop;
        InetAddress listenAddr(2021);
        TCPServer server(&loop, listenAddr);
        server.setConnectionCallback(onConnection);
        server.setWriteCompleteCallback(onWriteComplete);
        server.start();
        loop.loop();
    }
    // debug
    else{
        //fprintf(stderr, "Usage: %s file_for_downloading\n", argv[0]);
        g_file = "/home/devinchang/Documents/mathModel.py";

        EventLoop loop;
        InetAddress listenAddr(2021);
        TCPServer server(&loop, listenAddr);
        server.setConnectionCallback(onConnection);
        server.setWriteCompleteCallback(onWriteComplete);
        server.start();
        loop.loop();
    }
}


