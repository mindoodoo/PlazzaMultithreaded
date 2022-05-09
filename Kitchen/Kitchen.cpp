/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include <iostream>
#include "Kitchen.hpp"

int Kitchen::processMain()
{
    std::cout << this->receiveMessage();
}

Kitchen::Kitchen(int nbCooks, std::string &ipcPath) : ProcessEncapsulation(ipcPath), _nbCooks(nbCooks) { }
