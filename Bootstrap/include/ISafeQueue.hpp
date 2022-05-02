//
// Created by mindoo on 02.05.22.
//

#pragma once

#include "include.h"

class ISafeQueue {
public:
    virtual ~ISafeQueue() = default;
    virtual void push(int value) = 0;
    virtual bool tryPop(int &value) = 0;
};
