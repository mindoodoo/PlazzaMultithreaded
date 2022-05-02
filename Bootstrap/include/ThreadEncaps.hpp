/*
** EPITECH PROJECT, 2022
** ThreadEncaps.hpp
** File description:
** .
*/

#pragma once

#include "include.h"

class ThreadEncaps {
public:
    ThreadEncaps(void *(*start_routine)(void *), void *arg);

    virtual ~ThreadEncaps();

    void join(void **retval);

private :
    pthread_attr_t threadAttributes;
    pthread_t thread;
};
