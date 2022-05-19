//
// Created by mindoo on 19.05.22.
//

#pragma once

#include <mutex>
#include <functional>
#include <condition_variable>

class CondVarEncaps {
public:
    void notifyOne();
    void notifyAll();

    template <class Predicate>
    void wait(std::unique_lock<std::mutex> &lock, Predicate lambda);

    const std::condition_variable &getCv() const;

private:
    std::unique_lock<std::mutex> _lock;
    std::condition_variable _cv;
};