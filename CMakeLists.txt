cmake_minimum_required(VERSION 3.22)
project(Plazza)

set(CMAKE_CXX_STANDARD 14)

include_directories(Pizza)
include_directories(Reception)

add_executable(Plazza
        Pizza/Pizza.cpp
        Pizza/Pizza.hpp
        Reception/reception.cpp
        Reception/reception.hpp
        plazza.cpp Kitchen/Kitchen.cpp Kitchen/Kitchen.hpp Kitchen/ProcessEncapsulation.cpp Kitchen/ProcessEncapsulation.hpp)
