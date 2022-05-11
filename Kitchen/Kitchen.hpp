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
#include "ProcessEncapsulation.hpp"
#include "Pizza.hpp"

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

        int processMain() override;

        // Ipc functions
        capacity_t requestCapacity() const;

private:
    int _nbCooks;
    int _pizzasCooking;

    std::vector<Pizza> _pizzaQueue;
    std::vector<size_t> _ingredients;
};
