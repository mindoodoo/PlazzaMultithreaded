/*
** EPITECH PROJECT, 2022
** Counter.hpp
** File description:
** .
*/

#pragma once

#include <pthread.h>

class ScopedLock {
public:
    ScopedLock(const pthread_mutex_t &lock);
    virtual ~ScopedLock();

private:
    pthread_mutex_t _lock;
};
