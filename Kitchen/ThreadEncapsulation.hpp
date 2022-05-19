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
#include <iostream>

template <class... args>
class ThreadEncapsulation
{
public:
    ThreadEncapsulation(std::function<void(args...)> f, args... argv) {
        this->_function = f;
        this->_arguments = std::make_tuple(argv...);

        this->_thread = std::thread([this] {
            std::apply(this->_function, this->_arguments);
            this->_isRunning = false;
        });
    };

    void join() {
        this->_thread.join();
    };

    void detach() {
        this->_thread.detach();
    };

    bool isRunning() const {
        return _isRunning;
    };

private:
    std::function<void(args...)> _function;
    std::tuple<args...> _arguments;
    bool _isRunning = true;
    std::thread _thread;
};
