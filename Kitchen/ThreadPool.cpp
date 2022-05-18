/*
** EPITECH PROJECT, 2022
** ThreadPool
** File description:
** .
*/

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int nbThreads) : _nbThreads(nbThreads) {
    if (nbThreads > std::thread::hardware_concurrency()) {
        std::cerr << "WARNING: Number of threads greater than maximum hardware concurrency.\n";
        std::cerr << "Undefined behaviours is to be expected" << std::endl;
    } // Note : this check should be replaced by an exception in the future
}

void ThreadPool::start() {
    for (int i = 0; i < _nbThreads; i++)
        this->_workers.push_back(std::make_unique<ThreadEncapsulation<void *>>(ThreadPool::threadLoop, this));
    for (auto &thread: this->_workers)
        thread->join();
}

void ThreadPool::stop() {

}

void ThreadPool::newJob() {

}
void ThreadPool::threadLoop(void *pool) {
    std::cout << "In threadLoop" << std::endl;

    return;
}

bool ThreadPool::isInactive() {
    return (_activeThreads == 0);
}
