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
    SplitString splitMsg(msg, ",");

    // Invalid format check
    if (splitMsg._tokens.size() < 1)
        return;
    if (splitMsg._tokens[0] == "capa")
        this->respondCapacity();
    if (splitMsg._tokens[1] == "pizza")
        this->respondPizzaOrder(splitMsg._tokens[1]);
}

// Used by kichen process to respond to a request of capacity by the reception
void Kitchen::respondCapacity() const {
    std::stringstream ss;
    int totalCapa = 2 * _nbCooks;

    ss << totalCapa - _pizzasCooking - _pizzaQueue.size();
    ss << ";";
    ss << totalCapa;

    sendMessage(ss.str());
}

// Attempts to deserialize pizza order
// If successfull, adds pizzas to _pizzaQueue
void Kitchen::respondPizzaOrder(std::string msg) {
    SplitString orders(msg, ";");
    std::vector<Pizza> pizzas;

    // Attempt to deserializa every pizza
    for (auto order = orders._tokens.begin(); order != orders._tokens.end(); ++order) {
        try {
            pizzas.emplace_back(Pizza(*order));
        } catch (const std::invalid_argument& e) {
            this->sendMessage("failure");
            return;
        }
    }

    // Check if kitchen has capacity for new order
    if (pizzas.size() + this->_pizzasCooking + this->_pizzaQueue.size() >= 1 * this->_nbCooks) {
        this->sendMessage("failure");
        return;
    }

    // Add pizzas to queue and send success msg
    this->_pizzaQueue.insert(this->_pizzaQueue.end(), pizzas.begin(), pizzas.end());
    this->sendMessage("success");
}

// Function used by parent process (reception) in order to request current
// capacity of kitchen through named pipe IPC
// See capacity_t for return
capacity_t Kitchen::requestCapacity() const {
    capacity_t output;
    std::string msg;

    this->sendMessage("capa");
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // This sleep is temporary and only a way of avoiding to re read the message emitted
    msg = this->receiveMessage();

    SplitString msgSplit(msg, ";");
    if (msgSplit._tokens.size() <= 1)
        exit(84); // Not supposed to happen

    // Conversions will raise exceptions if error on conversion
    // Should not happen
    output.free = std::stoi(msgSplit._tokens[0]); // Available capa first
    output.totalCapacity = std::stoi(msgSplit._tokens[1]); // Total capa second
    output.percentageFree = output.free * 100 / output.totalCapacity;

    return output;
}

// Used by parent process in order to request pizza order
// Takes vector of pizza as argument
// returns true if error and order not passed, false if success
bool Kitchen::requestOrder(std::vector<Pizza> orders) {
    std::stringstream ss;

    // Assemble order serialization
    ss << "order,";
    for (auto order = orders.begin(); order != orders.end(); ++order)
        ss << *order << ";";
    this->sendMessage(ss.str());
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // This will eventuallt be removed too

    std::string response = this->receiveMessage();
    if (response == "success")
        return false;
    return true;
}

int Kitchen::getId() const {
    return _id;
}
