/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** Pizza
*/

#include "Pizza.hpp"

Pizza::Pizza(enum PizzaType type, enum PizzaSize size): _type(type), _size(size) 
{
    std::cout << "Pizza type: " << _type << std::endl;
    std::cout << "Pizza size: " << _size << std::endl;
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

std::string Pizza::serialize() const {
    std::stringstream ss;

    ss << this->_type << ";";
    ss << this->_size;
    return ss.str();
}

Pizza::Pizza(std::string serialization) {
    int sepIndex;

    sepIndex = serialization.find(";");
    // if (sepIndex == std::string::npos)
        // exit(84); // Not supposed to happen
    this->_type = PizzaType(std::stoi(serialization.substr(0, sepIndex)));
    this->_size = PizzaSize(std::stoi(serialization.substr(sepIndex + 1, std::string::npos)));
}
