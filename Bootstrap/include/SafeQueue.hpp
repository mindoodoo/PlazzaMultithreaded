/*
** EPITECH PROJECT, 2022
** SafeQueue.hpp
** File description:
** .
*/

#pragma once

#include "include.h"

class SafeQueue: public ISafeQueue{
public:
    SafeQueue() = default;

    void push(int value) override;
    bool tryPop(int &value) override;

private:
    std::mutex _lock;
    std::deque<int> _queue;
};
