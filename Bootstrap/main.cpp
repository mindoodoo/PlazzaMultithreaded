/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** .
*/

#include "include.h"

void *incrementCounter(void *num)
{
    for (int i = 0; i < 5; i++)
        ((Counter *)num)->incrementCounter();
    return nullptr;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "FUCK YOU" << std::endl;
        return 1;
    }

    int t = atoi(av[1]);
    Counter number = Counter(0);
    ThreadEncaps **threads = (ThreadEncaps **)calloc(t, sizeof(ThreadEncaps *));

    for (int i = 0; i < t; i++) {
        threads[i] = new ThreadEncaps(incrementCounter, &number);
    }
    for (int i = 0; i < t; i++) {
        threads[i]->join(nullptr);
    }

    std::cout << "Expected : " << t*5 << std::endl;
    std::cout << "Got : " << number.getCounter() << std::endl;
}
