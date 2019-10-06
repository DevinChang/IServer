cmake_minimum_required(VERSION 3.12)
project(EVENTLOOPTEST)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")


add_executable(EVENTLOOPTEST "../../utl/utl.h" ../../utl/utl.h "../../utl/Thread.h" ../../utl/Thread.cpp
        "../../utl/CurrentThread.h" ../../utl/CurrentThread.cpp "../../utl/EventLoop.h" ../../utl/EventLoop.cpp testEventLoop.cpp)

