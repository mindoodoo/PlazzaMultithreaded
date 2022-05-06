/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** Pizza
*/

#include "Pizza.hpp"

Pizza::Pizza(enum PizzaType type, enum PizzaSize size): _type(type), _size(size)
{
}

Pizza::~Pizza()
{
}

enum PizzaType Pizza::getType() const {
    return _type;
}

enum PizzaSize Pizza::getSize() const {
    return _size;
}

enum State Pizza::getState() const {
    return _state;
}

void Pizza::setState(enum State state) {
    _state = state;
}
