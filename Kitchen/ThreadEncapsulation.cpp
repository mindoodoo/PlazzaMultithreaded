/*
** EPITECH PROJECT, 2022
** ThreadEncapsulation
** File description:
** .
*/

#include "ThreadEncapsulation.hpp"

template <class... args>
ThreadEncapsulation<args...>::ThreadEncapsulation(std::function<void(args...)> f, args... argv)
{
    this->_function = f;
    this->_arguments = std::make_tuple(argv...);

    this->_thread = std::thread([this]
                                {
        std::apply(this->_function, this->_arguments);
        this->_isRunning = false; });
    std::cout << "YEYE" << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(1));
}

template <class... args>
void ThreadEncapsulation<args...>::join()
{
    this->_thread.join();
}

template <class... args>
void ThreadEncapsulation<args...>::detach()
{
    this->_thread.detach();
}

template <class... args>
bool ThreadEncapsulation<args...>::isRunning() const
{
    return _isRunning;
}

template <class... args>
ThreadEncapsulation<args...>::~ThreadEncapsulation()
{
    std::cout << "YO" << std::endl;
}
