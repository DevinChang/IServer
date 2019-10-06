cmake_minimum_required(VERSION 3.12)
project(EchoServer)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")




add_executable(echoServer "../../utl/utl.h" ../../utl/utl.h "../../utl/Thread.h" ../../utl/Thread.cpp
        "../../utl/CurrentThread.h" ../../utl/CurrentThread.cpp "../../utl/EventLoop.h" ../../utl/EventLoop.cpp
        "../../utl/Channel.h" ../../utl/Channel.cpp "../../utl/EPoller.h" ../../utl/EPoller.cpp
        "../../utl/TimeStamp.h" ../../utl/TimeStamp.cpp "../../utl/Timer.h" ../../utl/Timer.cpp
        "../../utl/Timerld.h" ../../utl/Timerld.cpp "../../utl/TimerQueue.h" ../../utl/TimerQueue.cpp
        "../../utl/Date.h" ../../utl/Date.cpp "../../utl/Mutex.h" ../../utl/Mutex.cpp
        "../../utl/Buffer.h" ../../utl/Buffer.cpp "../../utl/InetAddress.h" ../../utl/InetAddress.cpp
        "../../utl/TCPConnection.h" ../../utl/TCPConnection.cpp "../../utl/TCPServer.h" ../../utl/TCPServer.cpp
        "../../utl/Acceptor.h" ../../utl/Acceptor.cpp "../../utl/Connector.h" ../../utl/Connector.cpp
        "../../utl/Condition.h" ../../utl/Condition.cpp "../../utl/AtomicIntegerT.h"
        "../../utl/EventLoopThread.h" ../../utl/EventLoopThread.cpp
        "../../utl/EventLoopThreadPool.h" ../../utl/EventLoopThreadPool.cpp "../../utl/Util.h" ../../utl/Util.cpp
        "../../utl/Socket.h" ../../utl/Socket.cpp "../../utl/Log.h" ../../utl/Log.cpp
        "echoServer.h" echoServer.cpp mainServer.cpp)