/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** Pizza
*/

#include "Pizza.hpp"

Pizza::Pizza(enum PizzaType pizzaType): _pizzaType(pizzaType)
{
}

Pizza::~Pizza()
{
}

enum PizzaType Pizza::getPizzaType() const {
    return _pizzaType;
}

enum State Pizza::getState() const {
    return _state;
}

void Pizza::setState(enum State state) {
    _state = state;
}
