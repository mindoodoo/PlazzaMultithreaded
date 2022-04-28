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
    auto *threads = (pthread_t *)calloc(t, sizeof(pthread_t));

    for (int i = 0; i < t; i++) {
        pthread_create(&threads[i], NULL, &incrementCounter, &number);
    }
    for (int i = 0; i < t; i++) {
        pthread_join(threads[i], NULL);
    }

    std::cout << "Expected : " << t*5 << std::endl;
    std::cout << "Got : " << number.getCounter() << std::endl;
}
