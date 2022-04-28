/*
** EPITECH PROJECT, 2022
** Counter.cpp
** File description:
** .
*/

#include "Counter.hpp"

Counter::Counter(int counter):counter(counter)
{
    pthread_mutex_init(&this->mutexLock, NULL);
}

void Counter::lock()
{
    pthread_mutex_lock(&this->mutexLock);
}

void Counter::unlock()
{
    pthread_mutex_unlock(&this->mutexLock);
}

bool Counter::trylock()
{
    if (pthread_mutex_trylock(&this->mutexLock))
        return false;
    else
        return true;
}

void Counter::incrementCounter()
{
    ScopedLock sl = ScopedLock(this->mutexLock);

    this->counter++;
}

int Counter::getCounter() const {
    return counter;
}
