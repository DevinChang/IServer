cmake_minimum_required(VERSION 3.12)
project(TIMER)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")


add_executable(TIMER "../../utl/utl.h" ../../utl/utl.h "../../utl/Thread.h" ../../utl/Thread.cpp
        "../../utl/CurrentThread.h" ../../utl/CurrentThread.cpp "../../utl/EventLoop.h" ../../utl/EventLoop.cpp
        "../../utl/Channel.h" ../../utl/Channel.cpp "../../utl/Poller.h" ../../utl/Poller.cpp
        "../../utl/TimeStamp.h" ../../utl/TimeStamp.cpp "../../utl/Timer.h" ../../utl/Timer.cpp
        "../../utl/Timerld.h" ../../utl/Timerld.cpp "../../utl/TimerQueue.h" ../../utl/TimerQueue.cpp
        "../../utl/Date.h" ../../utl/Date.cpp testTimeQueue.cpp)


add_executable(testTimeQueue "../../utl/utl.h" ../../utl/utl.h "../../utl/Thread.h" ../../utl/Thread.cpp
        "../../utl/CurrentThread.h" ../../utl/CurrentThread.cpp "../../utl/EventLoop.h" ../../utl/EventLoop.cpp
        "../../utl/Channel.h" ../../utl/Channel.cpp "../../utl/Poller.h" ../../utl/Poller.cpp
        "../../utl/TimeStamp.h" ../../utl/TimeStamp.cpp "../../utl/Timer.h" ../../utl/Timer.cpp
        "../../utl/Timerld.h" ../../utl/Timerld.cpp "../../utl/TimerQueue.h" ../../utl/TimerQueue.cpp
        "../../utl/Date.h" ../../utl/Date.cpp "../../utl/Mutex.h" ../../utl/Mutex.cpp testTimeQueue2.cpp)
