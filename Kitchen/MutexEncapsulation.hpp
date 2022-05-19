/*
** EPITECH PROJECT, 2021
** MutexEncapsulation
** File description:
** .
*/

#pragma once

#include <memory>
#include <mutex>

class MutexEncapsulation
{
public:
    MutexEncapsulation();

    const std::shared_ptr<std::mutex> &getLock() const;

private:
    std::shared_ptr<std::mutex> _lock;
};
