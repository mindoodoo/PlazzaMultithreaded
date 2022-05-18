/*
** EPITECH PROJECT, 2022
** ThreadEncapsulation
** File description:
** .
*/

#include "ThreadEncapsulation.hpp"

template<class ...args>
ThreadEncapsulation<args...>::ThreadEncapsulation(std::function<void(args...)> f, args... argv) {
    this->_function = f;
    this->_arguments = std::make_tuple(argv...);

    this->_thread = std::thread([this] {
        std::apply(this->_function, this->_arguments);
        this->_isRunning = false;
    });

    this->_id = this->_thread.get_id();
}

template<class ...args>
void ThreadEncapsulation<args...>::join() {
    this->_thread.join();
}

template<class ...args>
void ThreadEncapsulation<args...>::detach() {
    this->_thread.detach();
}

template<class ...args>
const std::thread::id &ThreadEncapsulation<args...>::getId() const {
    return _id;
}

template<class ...args>
bool ThreadEncapsulation<args...>::isRunning() const {
    return _isRunning;
}
