/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include <iostream>
#include "Kitchen.hpp"


Kitchen::Kitchen(int nbCooks, std::string ipcPath, int id) :
ProcessEncapsulation(ipcPath), _nbCooks(nbCooks), _id(id),  _ipcPath(ipcPath) {
    _ingredients = std::vector<size_t>(9, 5);
    this->_pizzasCooking = 0;
}

int Kitchen::processMain()
{
    Timer timeoutTimer(5);
    std::string newMessage;

    // Main kitchen loop
    while (!timeoutTimer.isExpired()) {
        // Handle communications
        newMessage << this->_ipc;
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
    if (splitMsg._tokens[0] == "order")
        this->respondPizzaOrder(splitMsg._tokens[1]);
}

// Used by kichen process to respond to a request of capacity by the reception
void Kitchen::respondCapacity() {
    std::stringstream ss;
    std::string msg;
    int totalCapa = 2 * _nbCooks;

    ss << totalCapa - _pizzasCooking - _pizzaQueue.size();
    ss << ";";
    ss << totalCapa;
    msg = ss.str();

    msg >> this->_ipc;
}

// Attempts to deserialize pizza order
// If successfull, adds pizzas to _pizzaQueue
void Kitchen::respondPizzaOrder(std::string msg) {
    SplitString orders(msg, ";");
    std::vector<Pizza> pizzas;

    AddLog("Received new pizza order request...");
    // Attempt to deserializa every pizza
    for (auto order = orders._tokens.begin(); order != orders._tokens.end(); ++order) {
        try {
            pizzas.emplace_back(Pizza(*order));
        } catch (const std::invalid_argument& e) {
            (std::string &)"failure" >> this->_ipc;
            return;
        }
    }

    // Check if kitchen has capacity for new order
    if (pizzas.size() + this->_pizzasCooking + this->_pizzaQueue.size() > 2 * (size_t)this->_nbCooks) {
        std::cout << "In this if : " << pizzas.size() + this->_pizzasCooking << std::endl;
        std::cout << "Capacity : " << 2 * this->_nbCooks << std::endl;
        (std::string &)"failure" >> this->_ipc;
        return;
    }

    // Add pizzas to queue and send success msg
    this->_pizzaQueue.insert(this->_pizzaQueue.end(), pizzas.begin(), pizzas.end());
    (std::string &)"success" >> this->_ipc;
    AddLog("Succesfully added pizzas to cook!");
}

// Function used by parent process (reception) in order to request current
// capacity of kitchen through named pipe IPC
// See capacity_t for return
capacity_t Kitchen::requestCapacity() {
    capacity_t output;
    std::string response;

    (std::string &) "capa" >> this->_ipc;
    response << this->_ipc;

    SplitString msgSplit(response, ";");
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
bool Kitchen::requestOrder(std::vector<Pizza> &orders) {
    std::stringstream ss;
    std::string ordersString;
    std::string response;

    // Assemble order serialization
    ss << "order,";
    for (auto order = orders.begin(); order != orders.end(); ++order)
        ss << *order << ";";
    ordersString = ss.str();
    ordersString >> this->_ipc;

    response << this->_ipc;
    if (response == "success")
        return false;
    return true;
}

int Kitchen::getId() const {
    return _id;
}

Kitchen::~Kitchen() {
    // Refactor this in ipc class eventually
    if (this->_pid)
        std::remove(this->_ipcPath.c_str());
}
