/*
** EPITECH PROJECT, 2022
** ThreadPool
** File description:
** .
*/

#include "ThreadPool.hpp"

template <class... argsTypes>
ThreadPool<argsTypes...>::ThreadPool(int nbThreads) : _nbThreads(nbThreads)
{
    if (nbThreads > std::thread::hardware_concurrency())
    {
        std::cerr << "WARNING: Number of threads greater than maximum hardware concurrency.\n";
        std::cerr << "Undefined behaviours is to be expected" << std::endl;
    } // Note : this check should be replaced by an exception in the future
}

template <class... argsTypes>
void ThreadPool<argsTypes...>::start()
{
    this->_activeThreads = this->_nbThreads;
    for (int i = 0; i < this->_nbThreads; i++)
        this->_workers.push_back(std::make_unique<ThreadEncapsulation<ThreadPool *>>(ThreadPool::threadLoop, this));
    for (auto &thread : this->_workers)
        thread->join();
}

template <class... argsTypes>
void ThreadPool<argsTypes...>::pushJob(ThreadPool::Job newJob)
{
    this->_jobs.push_back(newJob);
    this->_cv.notifyOne();
}

template <class... argsTypes>
void ThreadPool<argsTypes...>::threadLoop(ThreadPool *pool)
{
    while (true)
    {
        std::unique_lock lock(pool->_lock.acquireLock());

        pool->_cv.wait(lock, [pool] {
            return !pool->_jobs.empty();
        });
        pool->_activeThreads++;

        ThreadPool::Job newJob = pool->_jobs.front();
        pool->_jobs.pop_front();
        newJob.execFunction();

        pool->_activeThreads--;
    }
}

template <class... argsTypes>
bool ThreadPool<argsTypes...>::isInactive()
{
    return (_activeThreads == 0);
}
