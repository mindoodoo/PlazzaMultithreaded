/*
** EPITECH PROJECT, 2022
** ThreadPool
** File description:
** .
*/

#pragma once

#include <vector>
#include "Pizza.hpp"
#include "ThreadEncapsulation.hpp"

class ThreadPool {
public:
    ThreadPool(int nbThreads);

    void start();
    void stop();
    void newJob();
    static void threadLoop(void *pool);

    bool isInactive();

private:
    int _nbThreads;
    int _activeThreads;

    std::vector<std::unique_ptr<ThreadEncapsulation<void*>>> _workers;
    std::function<void(Pizza, int)> _jobs;
};
