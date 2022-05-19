//
// Created by mindoo on 19.05.22.
//

#include "CondVarEncaps.hpp"

const std::condition_variable &CondVarEncaps::getCv() const {
    return _cv;
}

void CondVarEncaps::notifyOne() {
    this->_cv.notify_one();
}

void CondVarEncaps::notifyAll() {
    this->_cv.notify_all();
}

template <class Predicate>
void CondVarEncaps::wait(std::unique_lock<std::mutex> &lock, Predicate lambda) {
    this->_cv.wait(this->_lock, lambda);
}
