/*
** EPITECH PROJECT, 2022
** Counter.hpp
** File description:
** .
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(const pthread_mutex_t &lock) : _lock(lock)
{
    pthread_mutex_lock(&this->_lock);
}

ScopedLock::~ScopedLock()
{
    pthread_mutex_unlock(&this->_lock);
}
