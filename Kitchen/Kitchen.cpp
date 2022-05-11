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

capacity_t Kitchen::requestCapacity() const {
    capacity_t output;
    std::string msg;
    int sepIndex;

    this->sendMessage("capa");
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // This sleep is temporary and only a way of avoiding to re read the message emitted
    msg = this->receiveMessage();

    sepIndex = msg.find(";");
    if (sepIndex == std::string::npos)
        exit(84); // Not supposed to happen

    // Conversions will raise exceptions if error on conversion
    // Should not happen
    output.free = std::stoi(msg.substr(0, sepIndex)); // Available capa first
    output.totalCapacity = std::stoi(msg.substr(sepIndex + 1, std::string::npos)); // Total capa second
    output.percentageFree = output.free * 100 / output.totalCapacity;

    return output;
}
