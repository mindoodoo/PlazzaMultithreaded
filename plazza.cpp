/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include "plazza.hpp"

void printHelper()
{
    std::ifstream f("helper.txt");
    if (f.is_open())
        std::cout << f.rdbuf();
}

int Plazza::checkArg(int argc, char **argv)
{
    if (argc != 4)
        return 84;
    try
    {
        for (int x = 1; x < argc; x++)
        {
            std::stoi(argv[x]);
            if (x == 1)
                this->_multipTimeCook = std::stoi(argv[x]);
            if (x == 2)
                this->_nbrCooksPerKitchen = std::stoi(argv[x]);
            if (x == 3)
                this->_TimeRefill = std::stoi(argv[x]);
        }
    }
    catch (...)
    {
        std::cout << "!Bad input!" << std::endl;
        return 84;
    }
    return 0;
}

float Plazza::getMultiplier()
{
    return this->_multipTimeCook;
}

size_t Plazza::getnbrCooks()
{
    return this->_nbrCooksPerKitchen;
}

size_t Plazza::getTimeRefill()
{
    return this->_TimeRefill;
}

int main(int argc, char **argv)
{
    Plazza c;
    if (argc == 2 && ((std::string)argv[1]).compare("-h") == 0)
    {
        printHelper();
        return 0;
    }
    if (c.checkArg(argc, argv) == 84)
    {
        printHelper();
        return 84;
    }
    Reception a(c.getMultiplier(), c.getnbrCooks(), c.getTimeRefill());
    a.parsing();
    return 0;
}
