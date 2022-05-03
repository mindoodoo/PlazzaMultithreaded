/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** .
*/

#include "include.h"

// OLD MAIN
//
//
//void *incrementCounter(void *num)
//{
//    for (int i = 0; i < 5; i++)
//        ((Counter *)num)->incrementCounter();
//    return nullptr;
//}
//
//int main(int ac, char **av)
//{
//    if (ac != 2) {
//        std::cout << "FUCK YOU" << std::endl;
//        return 1;
//    }
//
//    int t = atoi(av[1]);
//    Counter number = Counter(0);
//    ThreadEncaps **threads = (ThreadEncaps **)calloc(t, sizeof(ThreadEncaps *));
//
//    for (int i = 0; i < t; i++) {
//        threads[i] = new ThreadEncaps(incrementCounter, &number);
//    }
//    for (int i = 0; i < t; i++) {
//        threads[i]->join(nullptr);
//    }
//
//    std::cout << "Expected : " << t*5 << std::endl;
//    std::cout << "Got : " << number.getCounter() << std::endl;
//}

void *producer(void *arg)
{
    auto queue = (SafeQueue*)arg;

    while (true) {
        queue->push(rand() % 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void *consumer(void *arg)
{
    auto queue = (SafeQueue*)arg;
    int val;

    while (true) {
        if (!queue->tryPop(val)) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }
        std::cout << "Consumed : " << val << std::endl;
    }
}

int main(int ac, char **av)
{
    int nbProducers;
    int nbConsumers;
    ThreadEncaps **producers;
    ThreadEncaps **consumers;
    SafeQueue queue;

    if (ac != 3) {
        std::cerr << "Not enough arguments\n";
        return 84;
    }
    nbProducers = atoi(av[1]);
    nbConsumers = atoi(av[2]);

    producers = (ThreadEncaps **)calloc(nbProducers, sizeof(ThreadEncaps *));
    consumers = (ThreadEncaps **)calloc(nbConsumers, sizeof(ThreadEncaps *));

    for (int i = 0; i < nbProducers; i++)
        producers[i] = new ThreadEncaps(producer, &queue);
    for (int i = 0; i < nbConsumers; i++)
        consumers[i] = new ThreadEncaps(consumer, &queue);
    for (int i = 0; i < nbProducers; i++)
        producers[i]->join(nullptr);
    for (int i = 0; i < nbConsumers; i++)
        consumers[i]->join(nullptr);
    return 0;
}
