/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** Pizza
*/

#include "Pizza.hpp"

Pizza::Pizza(enum PizzaType type, enum PizzaSize size) : _type(type), _size(size)
{
}

Pizza::~Pizza()
{
}

enum PizzaType Pizza::getType() const
{
    return _type;
}

enum PizzaSize Pizza::getSize() const
{
    return _size;
}

std::string Pizza::serialize() const
{
    std::stringstream ss;

    ss << this->_type << "-";
    ss << this->_size;
    return ss.str();
}

Pizza::Pizza(std::string serialization)
{
    SplitString parsedStr(serialization, "-");

    // This check should eventually be replaced by custom exception
    if (parsedStr._tokens.size() != 2)
        throw std::invalid_argument("Pizza serialization failed...");

    this->_type = PizzaType(std::stoi(parsedStr._tokens[0]));
    this->_size = PizzaSize(std::stoi(parsedStr._tokens[1]));
}

std::ostream &operator<<(std::ostream &os, const Pizza &pizza)
{
    os << pizza.serialize();

    return os;
}
