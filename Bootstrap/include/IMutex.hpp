/*
** EPITECH PROJECT, 2022
** IMutex.hpp
** File description:
** .
*/

#pragma once

class IMutex {
public:
    virtual ~IMutex() = default;

        virtual void lock() = 0;
        virtual void unlock() = 0;
        virtual bool trylock() = 0;

protected:
    pthread_mutex_t mutexLock;
};
