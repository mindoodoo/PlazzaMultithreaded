cmake_minimum_required(VERSION 3.22)
project(Plazza)

set(CMAKE_CXX_STANDARD 17)

include_directories(Pizza)
include_directories(Reception)
include_directories(Log)
include_directories(Kitchen)
include_directories(.)

add_executable(plazza
        Kitchen/Kitchen.cpp
        Kitchen/Ipc.cpp
        Kitchen/ProcessEncapsulation.cpp
        Kitchen/SplitString.cpp
        Kitchen/Timer.cpp
        Kitchen/MutexEncapsulation.cpp
        Kitchen/ThreadEncapsulation.hpp
        Kitchen/ThreadPool.cpp
        LogEngine/Log.cpp
        Pizza/Pizza.cpp
        Reception/Reception.cpp
        plazza.cpp)
