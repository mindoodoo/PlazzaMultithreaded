/*
** EPITECH PROJECT, 2022
** ThreadPool
** File description:
** .
*/

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int nbThreads) : _nbThreads(nbThreads)
{
    if (nbThreads > std::thread::hardware_concurrency())
    {
        std::cerr << "WARNING: Number of threads greater than maximum hardware concurrency.\n";
        std::cerr << "Undefined behaviours is to be expected" << std::endl;
    } // Note : this check should be replaced by an exception in the future
}

void ThreadPool::start()
{
    this->_activeThreads = this->_nbThreads;
    for (int i = 0; i < this->_nbThreads; i++)
        this->_workers.push_back(std::make_unique<ThreadEncapsulation<ThreadPool *>>(ThreadPool::threadLoop, this));
    for (auto &thread : this->_workers)
        thread->join();
}

void ThreadPool::newJob()
{
}
void ThreadPool::threadLoop(ThreadPool *pool)
{
    while (true)
    {
        pool->_lock.lock(); // Needs to be replaced with mutex encapsulation
        std::unique_lock lock(pool->_lock);
        pool->_cv.wait(lock, [pool]
                       { return !pool->_jobs.empty(); });
        pool->_activeThreads++;
        std::function newJob = pool->_jobs.front();
        pool->_jobs.pop_front();
        // Needs condition var for refill (potentially)
        // + generic way to pass arguments to jobs
        //        newJob();
    }
}

bool ThreadPool::isInactive()
{
    return (_activeThreads == 0);
}
