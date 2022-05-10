/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    #include <vector>
    #include "ProcessEncapsulation.hpp"

    enum INGREDIENTS {
        DOE,
        TOMATO,
        GRUYERE,
        HAM,
        MUSHROOMS,
        STEAK,
        EGGPLANT,
        GOAT_CHEESE,
        CHIEF_LOVE
    };

    class Kitchen : public ProcessEncapsulation {
        public:
            Kitchen(int nbCooks, std::string &ipcPath);
            int processMain() override;

    private:
        int _nbCooks;
        std::vector<size_t> _ingredients;
    };


#endif /* !KITCHEN_HPP_ */
