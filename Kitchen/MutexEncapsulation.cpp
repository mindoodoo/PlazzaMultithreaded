/*
** EPITECH PROJECT, 2021
** MutexEncapsulation
** File description:
** .
*/

#include "MutexEncapsulation.hpp"

std::unique_lock<std::mutex> MutexEncapsulation::acquireLock()
{
    std::unique_lock<std::mutex> lock(this->_lock);

    return lock;
}
