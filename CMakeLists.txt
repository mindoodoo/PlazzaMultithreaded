cmake_minimum_required(VERSION 3.22)
project(Plazza)

set(CMAKE_CXX_STANDARD 14)

include_directories(Pizza)
include_directories(Reception)

add_executable(Plazza
        Pizza/Pizza.cpp
        Reception/Reception.cpp
        Kitchen/Kitchen.cpp
        Kitchen/ProcessEncapsulation.cpp
        Kitchen/Timer.cpp
        LogEngine/Log.cpp
        plazza.cpp
        Kitchen/SplitString.cpp Kitchen/SplitString.hpp)
