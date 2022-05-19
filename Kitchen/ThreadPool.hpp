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


// Note : This is the same templating argument pack as ThreadEncapsulation
template <class... argsTypes>
class ThreadPool
{
public:
    class Job {
    public:
        Job(const std::function<void(argsTypes...)> &function, argsTypes... argv) :
        _function(function) {
            this->_arguments = std::make_tuple(argv...);
        };

    private:
        std::function<void(argsTypes...)> _function;
        std::tuple<argsTypes...> _arguments;
    };

    ThreadPool(int nbThreads);

    void start();

    void pushJob(ThreadPool::Job newJob);

    static void threadLoop(ThreadPool *pool);

    bool isInactive();


private:
    int _nbThreads;
    int _activeThreads;
    MutexEncapsulation _lock;
    std::condition_variable _cv;

    std::vector<std::unique_ptr<ThreadEncapsulation<ThreadPool *>>> _workers;
    std::deque<ThreadPool::Job> _jobs;
};
