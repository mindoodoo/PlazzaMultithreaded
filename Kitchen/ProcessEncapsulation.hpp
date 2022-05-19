/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** ProcessEncapsulation
*/

#pragma once

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "Ipc.hpp"

class ProcessEncapsulation
{
public:
    ProcessEncapsulation(std::string &ipcPath);
    ~ProcessEncapsulation();

    pid_t startProcess();
    virtual int processMain() = 0;

    // Getters
    pid_t getPid() const;

protected:
    pid_t _pid;
    Ipc _ipc;
};
