/*
** EPITECH PROJECT, 2022
** SafeQueue.cpp
** File description:
** .
*/

#include "SafeQueue.hpp"

void SafeQueue::push(int value)
{
    std::unique_lock<std::mutex> safeLock(this->_lock);

    this->_queue.push_front(value);
}

bool SafeQueue::tryPop(int &value)
{
    std::unique_lock<std::mutex> safeLock(this->_lock);

    if (this->_queue.empty())
        return false;

    value = this->_queue.back();
    this->_queue.pop_back();
    return true;
}
