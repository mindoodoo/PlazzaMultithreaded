/*
** EPITECH PROJECT, 2022
** Counter.hpp
** File description:
** .
*/

#pragma once

#include "include.h"

class Counter: public IMutex {
public:
    Counter(int counter);
    ~Counter() override = default;


    void lock() override;
    void unlock() override;
    bool trylock() override;

    void incrementCounter();

    int getCounter() const;

private:
    int counter;
};
