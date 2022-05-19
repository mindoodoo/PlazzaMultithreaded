/*
** EPITECH PROJECT, 2021
** MutexEncapsulation
** File description:
** .
*/

#pragma once

#include <mutex>

class MutexEncapsulation
{
public:
    std::unique_lock<std::mutex> acquireLock();

private:
    std::mutex _lock;
};
