/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#pragma once

#include "ProcessEncapsulation.hpp"

class Kitchen: public ProcessEncapsulation {
public:
    Kitchen(int nbCooks, std::string &ipcPath);

    int processMain() override;

private:
    int _nbCooks;
};
