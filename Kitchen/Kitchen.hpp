/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** Kitchen
*/

#pragma once

#include <vector>
#include <chrono>
#include <thread>
#include <sstream>
#include "ProcessEncapsulation.hpp"
#include "Pizza.hpp"
#include "Timer.hpp"

typedef struct {
    int totalCapacity;
    int free;
    float percentageFree;
} capacity_t;

enum INGREDIENTS {
    DOE,
    TOMATO,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    EGGPLANT,
    GOAT_CHEESE,
    CHIEF_LOVE
};

class Kitchen : public ProcessEncapsulation {
    public:
        Kitchen(int nbCooks, std::string &ipcPath);

        // Main kitchen functions
        int processMain() override;
        void handleMessages(std::string msg);

        // IPC functions
        capacity_t requestCapacity() const;

private:
    int _nbCooks;
    int _pizzasCooking;

    std::vector<Pizza> _pizzaQueue;
    std::vector<size_t> _ingredients;
};
