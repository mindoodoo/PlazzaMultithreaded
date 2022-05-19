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
#include "CondVarEncaps.hpp"

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

        void execFunction() {
            std::apply(this->_function, this->_arguments);
        }

    private:
        std::function<void(argsTypes...)> _function;
        std::tuple<argsTypes...> _arguments;
    };

    ThreadPool(size_t nbThreads) : _nbThreads(nbThreads)
    {
        if (nbThreads > std::thread::hardware_concurrency())
        {
            std::cerr << "WARNING: Number of threads greater than maximum hardware concurrency.\n";
            std::cerr << "Undefined behaviours is to be expected" << std::endl;
        } // Note : this check should be replaced by an exception in the future
    };

    void start() {
        this->_activeThreads = this->_nbThreads;
        for (size_t i = 0; i < this->_nbThreads; i++)
            this->_workers.push_back(std::make_unique<ThreadEncapsulation<ThreadPool *>>(ThreadPool::threadLoop, this));
        for (auto &thread : this->_workers)
            thread->join();
    };

    void pushJob(ThreadPool::Job newJob) {
        this->_jobs.push_back(newJob);
        this->_cv.notifyAll();
    };

    static void threadLoop(ThreadPool *pool) {
        std::shared_ptr lock = pool->_lock.getLock();

        while (true)
        {
            pool->_cv.wait(*lock, [pool] {
                return !pool->_jobs.empty();
            });
            pool->_activeThreads++;
//        std::cout << "Mutex status is : " << pool->_lock.getLock().try_lock() << std::endl;
            ThreadPool::Job newJob = pool->_jobs.front();
            pool->_jobs.pop_front();
            newJob.execFunction();

            pool->_activeThreads--;
        }
    };

    bool isInactive() {
        return (_activeThreads == 0);
    };

private:
    size_t _nbThreads;
    int _activeThreads = 0;
    MutexEncapsulation _lock;
    CondVarEncaps _cv;

    std::vector<std::unique_ptr<ThreadEncapsulation<ThreadPool *>>> _workers;
    std::deque<ThreadPool::Job> _jobs;
};
