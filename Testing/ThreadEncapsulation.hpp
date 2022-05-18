/*
** EPITECH PROJECT, 2022
** ThreadEncapsulation
** File description:
** .
*/

#pragma once

#include <thread>
#include <tuple>
#include <functional>

template<class ...args>
class ThreadEncapsulation {
public:
    ThreadEncapsulation(std::function<void(args...)> f, args... argv);
    void join();
    void detach();

    bool isRunning() const;

    const std::thread::id &getId() const;

private:
    std::function<void(args...)> _function;
    std::tuple<args...> _arguments;
    bool _isRunning = true;
    std::thread _thread;
    std::thread::id _id;
};

#include "ThreadEncapsulation.cpp"
