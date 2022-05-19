/*
** EPITECH PROJECT, 2022
** ThreadPool
** File description:
** .
*/

#pragma once

#include <vector>
#include <deque>
#include <mutex>
#include <condition_variable>
#include "Pizza.hpp"
#include "ThreadEncapsulation.hpp"
#include "MutexEncapsulation.hpp"

class ThreadPool
{
public:
    ThreadPool(int nbThreads);

    void start();
    void pushJob();
    static void threadLoop(ThreadPool *pool);

    bool isInactive();

private:
    int _nbThreads;
    int _activeThreads;
    MutexEncapsulation _lock;
    std::condition_variable _cv;

    std::vector<std::unique_ptr<ThreadEncapsulation<ThreadPool *>>> _workers;
    std::deque<std::function<void(Pizza, int)>> _jobs;
};
