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
#include <ostream>
#include "ProcessEncapsulation.hpp"
#include "../Pizza/Pizza.hpp"
#include "Timer.hpp"
#include "SplitString.hpp"
#include "../LogEngine/Log.hpp"

typedef struct
{
    int totalCapacity;
    int free;
    float percentageFree;
} capacity_t;

enum INGREDIENTS
{
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

class Kitchen : public ProcessEncapsulation
{
public:
    Kitchen(std::string ipcPath, size_t nbCooks, size_t id, size_t refillTime);
    ~Kitchen() = default;

    // Main kitchen functions
    int processMain() override;
    void handleMessages(std::string msg);

    // IPC functions
    capacity_t requestCapacity();
    bool requestOrder(std::vector<Pizza> &orders);
    void respondCapacity();
    void respondPizzaOrder(std::string msg);

    size_t getId() const;

private:
    const size_t _nbCooks;
    const size_t _id;
    const size_t _refillTime;
    int _pizzasCooking;

    std::vector<Pizza> _pizzaQueue;
    std::vector<size_t> _ingredients;
};
