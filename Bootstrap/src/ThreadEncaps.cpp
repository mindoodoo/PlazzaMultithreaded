/*
** EPITECH PROJECT, 2022
** ThreadEncaps.cpp
** File description:
** .
*/

#include "ThreadEncaps.hpp"

ThreadEncaps::ThreadEncaps(void *(*start_routine)(void *), void *arg)
{
    pthread_attr_init(&this->threadAttributes);
    pthread_create(&this->thread, &this->threadAttributes, start_routine, arg);
}

ThreadEncaps::~ThreadEncaps()
{
    pthread_attr_destroy(&this->threadAttributes);
    pthread_cancel(this->thread);
}

void ThreadEncaps::join(void **retval)
{
    pthread_join(this->thread, retval);
}
