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
#include <string>

class Reception {
    public:
        Reception();
        ~Reception();
        void parsing();
        void checkArg(std::vector<std::string> &sortinput);
        void displayMenu();
        void stockCSV();
    private:
        std::vector<Pizza> _orders;
        std::vector<std::vector<std::string>> _CSVcontents;
};

#endif /* !RECEPTION_HPP_ */
