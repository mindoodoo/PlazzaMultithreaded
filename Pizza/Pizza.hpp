/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_

    #include <string>
    #include <sstream>
    #include <iostream>


    enum PizzaType
    {
        megina = 1,
        margarita = 2,
        americana = 4,
        fantasia = 8
    };

    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    class Pizza {
        public:
            Pizza(enum PizzaType pizzaType, enum PizzaSize size);
            Pizza(std::string serialization);

        ~Pizza();
            enum PizzaType getType() const;
            enum PizzaSize getSize() const;
            std::string serialize() const;

        private:
            enum PizzaType _type;
            enum PizzaSize _size;
    };

#endif /* !PIZZA_HPP_ */
