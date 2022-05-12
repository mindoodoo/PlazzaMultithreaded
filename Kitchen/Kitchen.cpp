/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include <iostream>
#include "Kitchen.hpp"


Kitchen::Kitchen(int nbCooks, std::string &ipcPath, int id) :
    ProcessEncapsulation(ipcPath), _nbCooks(nbCooks), _id(id) {
        _ingredients = std::vector<size_t>(9, 5);
    }

int Kitchen::processMain()
{
    Timer timeoutTimer(5);
    std::string newMessage;

    // Main kitchen loop
    std::cout << "Kithcen process started" << std::endl;
    while (!timeoutTimer.isExpired()) {
        // Handle communications
        newMessage = this->receiveMessage();
        this->handleMessages(newMessage);
    }
    return 0;
}

// Handles new incoming IPC messages for child process (actual kitchen)
// Used in main loop in processMain()
void Kitchen::handleMessages(std::string msg) {
    if (msg == "capa") {
        std::stringstream ss;
        int totalCapa = 2 * this->_nbCooks;

        ss << totalCapa - this->_pizzasCooking - this->_pizzaQueue.size();
        ss << ";";
        ss << totalCapa;

        this->sendMessage(ss.str());
    }
}

// Function used by parent process (reception) in order to request current
// capacity of kitchen through named pipe IPC
// See capacity_t for return
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

int Kitchen::getId() const {
    return _id;
}
