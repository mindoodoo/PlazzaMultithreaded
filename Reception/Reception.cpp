/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include "Reception.hpp"

Reception::Reception(float multipTimeCook, size_t nbrCooksPerKitchen, size_t TimeRefill)
{
    this->_multipTimeCook = multipTimeCook;
    this->_nbrCooksPerKitchen = nbrCooksPerKitchen;
    this->_TimeRefill = TimeRefill;
}

Reception::~Reception() {}

void Reception::StockInputInVec(std::string input, std::vector<std::string> &sortinput)
{
    std::string temp = "";
    sortinput.clear();

    for (size_t i = 0; i < input.length(); ++i)
    {
        if (input[i] == ' ')
        {
            sortinput.push_back(temp);
            temp = "";
        }
        else if (input[i] == ';')
        {
            sortinput.push_back(temp);
            temp = "";
            sortinput.push_back(";");
        }
        else
            temp.push_back(input[i]);
    }
    sortinput.push_back(temp);
}

void Reception::stockCSVMenuInVec()
{
    std::string Filename = "Reception/Menu.csv";
    std::vector<std::string> CSVrow;
    std::string line;
    std::string word;

    std::ifstream file(Filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            CSVrow.clear();
            std::stringstream str(line);
            while (getline(str, word, ','))
            {
                CSVrow.push_back(word);
            }
            _CSVcontents.push_back(CSVrow);
        }
    }
    else
    {
        std::cout << "Can't read file" << std::endl;
    }
}

void Reception::displayMenu()
{
    int color = 31;

    for (size_t i = 1; i < 5; i++)
    {
        std::cout << "\033[1;" << color << "m" << _CSVcontents[i][0] << "\033[0m ";
        std::cout << "\n";
        color++;
    }
}

PizzaSize Reception::convertSizeEnum(const std::string &str)
{
    if (str == "S")
        return PizzaSize::S;
    else if (str == "M")
        return PizzaSize::M;
    else if (str == "L")
        return PizzaSize::L;
    else if (str == "XL")
        return PizzaSize::XL;
    else if (str == "XXL")
        return PizzaSize::XXL;
    std::cout << "WARNING, YOU MUST NOT BE HERE, PLEASE CHECK CONVERTSIZE FUNCTION FOR SOLVE THIS PROBLEM !" << std::endl;
    return PizzaSize::XXL;
}

PizzaType Reception::convertTypeEnum(const std::string &str)
{
    if (str == "megina")
        return PizzaType::megina;
    else if (str == "margarita")
        return PizzaType::margarita;
    else if (str == "americana")
        return PizzaType::americana;
    else if (str == "fantasia")
        return PizzaType::fantasia;
    std::cout << "WARNING, YOU MUST NOT BE HERE, PLEASE CHECK CONVERTTYPE FUNCTION FOR SOLVE THIS PROBLEM !" << std::endl;
    return PizzaType::fantasia;
}

int Reception::checkErrorInput(std::vector<std::string> &sortinput)
{
    int arg = 0;
    for (size_t i = 0; i < sortinput.size(); i++)
    {
        if (sortinput[i][0] == ';')
        {

            if (arg == 3)
            {
                std::cout << "arg if arg  == 3" << arg << std::endl;
                arg = 0;
            }
            else if (arg != 3 || arg != 4)
            {
                std::cout << "arg if arg  != 3 " << arg << std::endl;
                return 84;
            }
        }
        else
            arg++;
    }
    return 0;
}

void Reception::stockPizzaInVec(std::vector<std::string> &sortinput)
{

    int done = 1;
    int nbPizzaOrder = 0;
    int pizzaAdd = 0;

    for (size_t i = 0; i < sortinput.size(); i++)
    {
        if (sortinput[i][0] == ';')
            i = i + 2;
        for (size_t j = 1; j <= 4; j++)
        {
            if (sortinput[i] == _CSVcontents[j][0])
            {
                done++;
                break;
            }
        }
        i++;
        for (size_t j = 1; j <= 5; j++)
        {
            if (sortinput[i] == _CSVcontents[j][3])
            {
                done++;
                break;
            }
        }
        i++;
        for (size_t j = 0; sortinput[i][j + 1] != '\0'; j++)
        {
            if (sortinput[i][j + 1] == ';')
                break;
            if (sortinput[i][0] == 'x' && sortinput[i][j + 1] >= '0' && sortinput[i][j + 1] <= '9')
                continue;
            else
            {
                done--;
                break;
            }
        }
        if (sortinput[i][0] != 'x')
            done--;
        if (done != 3)
        {
            std::cout << "\033[1;31mBad order, your order must have this format:\n\tpizzaName SIZE xQUANT; [...]; pizzaName SIZE xQUANT\033[0m" << std::endl;
            break;
        }
        else
        {
            nbPizzaOrder = atoi(sortinput[i].substr(1, sortinput[i].length() - 1).c_str());
            PizzaSize size = convertSizeEnum(sortinput[i - 1]);
            PizzaType type = convertTypeEnum(sortinput[i - 2]);
            for (int j = 0; j < nbPizzaOrder; j++)
            {
                _orders.push_back(Pizza(type, size));
                pizzaAdd++;
            }
            std::cout << "\033[1;32mOrder add to the queue\033[0m" << std::endl;
        }
        done = 1;
    }
}

void Reception::parsing()
{
    std::string input;
    std::vector<std::string> sortinput;

    std::cout << "To see the Menu write: Menu" << std::endl;
    while (true)
    {
        std::cout << "Enter your order: ";
        std::getline(std::cin, input);
        stockCSVMenuInVec();
        if (input == "clear")
            exit(0);
        if (input == "Menu")
        {
            displayMenu();
            AddLog("Menu printed by the user");
        }
        else
        {
            StockInputInVec(input, sortinput);
            if (checkErrorInput(sortinput) == 84)
                std::cout << "\033[1;31mBad order, your order must have this format:\n\tpizzaName SIZE xQUANT; [...]; pizzaName SIZE xQUANT\033[0m" << std::endl;
            else
            {
                stockPizzaInVec(sortinput);
                splitOrderInKitchen();
            }
        }
    }
}

void Reception::splitOrderInKitchen()
{
    std::vector<Kitchen> kitchen;
    std::vector<std::vector<Pizza>> pizza;
    size_t pizzaMax = this->_nbrCooksPerKitchen * 2;
    int a = 0;

    pizza.push_back(std::vector<Pizza>());
    for (size_t i = 0; i < _orders.size(); i++)
    {
        if (pizza[a].size() == pizzaMax)
        {
            a++;
            pizza.push_back(std::vector<Pizza>());
        }
        pizza[a].push_back(_orders[i]);
        _orders.erase(_orders.begin());
    }
    for (size_t i = 0; i < pizza.size(); i++)
    {
        Kitchen newKitchen = Kitchen(std::string("ipc/ipc") + std::to_string(i),
                                     this->_nbrCooksPerKitchen,
                                     i, this->_TimeRefill);
        if (!newKitchen.startProcess())
            exit(0); // This will have to be replaced by adequate frees in the future
        kitchen.push_back(newKitchen);
        kitchen[i].requestOrder(pizza[i]);
    }
}
