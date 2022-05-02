cmake_minimum_required(VERSION 3.22)
project(Bootstrap)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Bootstrap
        main.cpp src/Counter.cpp src/ScopedLock.cpp include/ScopedLock.hpp src/ThreadEncaps.cpp include/ThreadEncaps.hpp)
