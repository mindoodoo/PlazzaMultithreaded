/*
** EPITECH PROJECT, 2021
** MutexEncapsulation
** File description:
** .
*/

#include "MutexEcapsulation.hpp"

std::unique_lock<std::mutex> MutexEcapsulation::acquireLock() {
    std::unique_lock<std::mutex> lock(this->_lock);

    return lock;
}
