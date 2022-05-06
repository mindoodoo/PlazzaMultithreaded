/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_

enum PizzaType
{
    Regina = 1 ,
    Margarita = 2 ,
    Americana = 4 ,
    Fantasia = 8
};

enum State {
    IN_QUEUE,
    COOKING,
    DONE
};

class Pizza {
    public:
        Pizza(enum PizzaType pizzaType);
        ~Pizza();
        enum PizzaType getPizzaType() const;
        enum State getState() const;
        void setState(enum State);

    private:
        const enum PizzaType _pizzaType;
        enum State _state;
};

#endif /* !PIZZA_HPP_ */
