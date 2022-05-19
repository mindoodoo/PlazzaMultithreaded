//
// Created by mindoo on 19.05.22.
//

#pragma once

#include <mutex>
#include <functional>
#include <condition_variable>

class CondVarEncaps {
public:
    void notifyOne() {
        this->_cv.notify_one();
    };

    void notifyAll() {
        this->_cv.notify_all();
    };

    template <class Predicate>
    void wait(std::mutex *lock, Predicate lambda) {
        std::unique_lock l(*lock);
        this->_cv.wait(l, lambda);
    };

    const std::condition_variable &getCv() const {
        return _cv;
    };

private:
    std::condition_variable _cv;
};
