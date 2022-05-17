/*
** EPITECH PROJECT, 2021
** MutexEncapsulation
** File description:
** .
*/

#pragma once

#include <mutex>

class MutexEcapsulation {
public:
    std::unique_lock<std::mutex> acquireLock();

private:
    std::mutex _lock;
};
