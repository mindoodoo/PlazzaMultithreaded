/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../Pizza/Pizza.hpp"
#include "../LogEngine/Log.hpp"
#include "../Kitchen/Kitchen.hpp"
#include <string>

class Reception
{
public:
    Reception(float multipTimeCook, size_t nbrCooksPerKitchen, size_t TimeRefill);
    ~Reception();
    void parsing();
    void stockPizzaInVec(std::vector<std::string> &sortinput);
    void displayMenu();
    void stockCSVMenuInVec();
    PizzaSize convertSizeEnum(const std::string &str);
    PizzaType convertTypeEnum(const std::string &str);
    int checkErrorInput(std::vector<std::string> &sortinput);
    void StockInputInVec(std::string input, std::vector<std::string> &sortinput);
    void splitOrderInKitchen();

private:
    float _multipTimeCook;
    size_t _nbrCooksPerKitchen;
    size_t _TimeRefill;
    std::vector<Pizza> _orders;
    std::vector<std::vector<std::string>> _CSVcontents;
};

#endif /* !RECEPTION_HPP_ */
