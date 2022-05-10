/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include <iostream>
#include "Kitchen.hpp"


Kitchen::Kitchen(int nbCooks, std::string &ipcPath) :
    ProcessEncapsulation(ipcPath), _nbCooks(nbCooks) {
        _ingredients = std::vector<size_t>(9, 5);
    }

int Kitchen::processMain()
{
    std::cout << this->receiveMessage();
    return 0;
}
