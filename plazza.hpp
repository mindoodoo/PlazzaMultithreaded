/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include "Reception/Reception.hpp"

class Plazza
{
public:
    Plazza() = default;
    ~Plazza() = default;
    int checkArg(int argc, char **argv);
    float getMultiplier();
    size_t getnbrCooks();
    size_t getTimeRefill();

private:
    float _multipTimeCook;
    size_t _nbrCooksPerKitchen;
    size_t _TimeRefill;
};

#endif
