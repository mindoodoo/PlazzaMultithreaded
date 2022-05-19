/*
** EPITECH PROJECT, 2021
** MutexEncapsulation
** File description:
** .
*/

#include "MutexEncapsulation.hpp"

MutexEncapsulation::MutexEncapsulation() {
    this->_lock = std::make_shared<std::mutex>();
}

const std::shared_ptr<std::mutex> &MutexEncapsulation::getLock() const {
    return _lock;
}
