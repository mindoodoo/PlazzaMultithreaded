/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include <iostream>
#include "Kitchen.hpp"

Kitchen::Kitchen(std::string ipcPath, const size_t nbCooks, const size_t id, const size_t refillTime) : ProcessEncapsulation(ipcPath), _nbCooks(nbCooks), _id(id), _refillTime(refillTime)
{
    _ingredients = std::vector<size_t>(9, 5);
    this->_pizzasCooking = 0;
}

int Kitchen::processMain()
{
    Timer timeoutTimer(10);
    std::string newMessage;
    std::cout << "In process main" << std::endl;

    // Lambda function used to launch member function in msg handling thread
    std::function launchThread = [](Kitchen *ptr) {
        ptr->handleMessages();
    };
    // Launch handle message thread
    ThreadEncapsulation<Kitchen*> ipcHandlingThread(launchThread, this);

    // Main kitchen loop
    while (!timeoutTimer.isExpired());

    return 0;
}

// Handles new incoming IPC messages for child process (actual kitchen)
// Used in main loop in processMain()
void Kitchen::handleMessages()
{
    std::string msg;
    msg << (*this->_ipc);
    SplitString splitMsg(msg, ",");

    // std::cout << "Handling msg : " << msg << std::endl;
    // Invalid format check
    if (splitMsg._tokens.size() < 1)
        return;
    if (splitMsg._tokens[0] == "capa")
        this->respondCapacity();
    if (splitMsg._tokens[0] == "order")
        this->respondPizzaOrder(splitMsg._tokens[1]);
}

// Used by kichen process to respond to a request of capacity by the reception
void Kitchen::respondCapacity()
{
    std::stringstream ss;
    std::string msg;
    int totalCapa = 2 * _nbCooks;

    // std::cout << "In respond capacity" << std::endl;

    ss << totalCapa - _pizzasCooking - _pizzaQueue.size();
    ss << ";";
    ss << totalCapa;
    msg = ss.str();

    msg >> *(this->_ipc);
    
    // std::cout << "After sending response" << std::endl;
}

// Attempts to deserialize pizza order
// If successfull, adds pizzas to _pizzaQueue
void Kitchen::respondPizzaOrder(std::string msg)
{
    SplitString orders(msg, ";");
    std::vector<Pizza> pizzas;
    std::string failure = "failure";
    std::string success = "success";

    AddLog("Received new pizza order request...");
    // Attempt to deserializa every pizza
    for (auto order = orders._tokens.begin(); order != orders._tokens.end(); ++order)
    {
        try
        {
            pizzas.emplace_back(Pizza(*order));
        }
        catch (const std::invalid_argument &e)
        {
            failure >> *(this->_ipc);
            return;
        }
    }

    // Check if kitchen has capacity for new order
    if (pizzas.size() + this->_pizzasCooking + this->_pizzaQueue.size() > 2 * (size_t)this->_nbCooks)
    {
        failure >> *(this->_ipc);
        return;
    }

    // Add pizzas to queue and send success msg
    this->_pizzaQueue.insert(this->_pizzaQueue.end(), pizzas.begin(), pizzas.end());
    success >> *(this->_ipc);
    AddLog("Succesfully added pizzas to cook!");
}

// Function used by parent process (reception) in order to request current
// capacity of kitchen through named pipe IPC
// See capacity_t for return
capacity_t Kitchen::requestCapacity()
{
    capacity_t output;
    std::string response;
    std::string msg = "capa";

    msg >> *(this->_ipc);
    response << *(this->_ipc);

    SplitString msgSplit(response, ";");
    if (msgSplit._tokens.size() <= 1)
        exit(84); // Not supposed to happen

    // Conversions will raise exceptions if error on conversion
    // Should not happen
    output.free = std::stoi(msgSplit._tokens[0]);          // Available capa first
    output.totalCapacity = std::stoi(msgSplit._tokens[1]); // Total capa second
    output.percentageFree = output.free * 100 / output.totalCapacity;

    return output;
}

// Used by parent process in order to request pizza order
// Takes vector of pizza as argument
// returns true if error and order not passed, false if success
bool Kitchen::requestOrder(std::vector<Pizza> &orders)
{
    std::stringstream ss;
    std::string ordersString;
    std::string response;

    // Assemble order serialization
    ss << "order,";
    for (auto order = orders.begin(); order != orders.end(); ++order)
        ss << *order << ";";
    ordersString = ss.str();
    ordersString >> *(this->_ipc);

    response << *(this->_ipc);
    if (response == "success")
        return false;
    return true;
}

size_t Kitchen::getId() const
{
    return _id;
}
