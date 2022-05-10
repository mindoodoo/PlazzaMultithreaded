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
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    enum State
    {
        IN_QUEUE,
        COOKING,
        DONE
    };

    class Pizza {
        public:
            Pizza(enum PizzaType pizzaType, enum PizzaSize size);
            ~Pizza();
            enum PizzaType getType() const;
            enum PizzaSize getSize() const;
            enum State getState() const;
            void setState(enum State);

        private:
            const enum PizzaType _type;
            enum PizzaSize _size;
            enum State _state;
    };

#endif /* !PIZZA_HPP_ */
