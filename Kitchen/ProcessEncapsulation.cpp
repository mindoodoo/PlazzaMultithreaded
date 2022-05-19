/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include "ProcessEncapsulation.hpp"

ProcessEncapsulation::ProcessEncapsulation(std::string &ipcPath) : _ipc(ipcPath) {}

ProcessEncapsulation::~ProcessEncapsulation()
{
    if (this->_pid)
        std::remove(this->_ipc.getIpcPath().c_str());
}

pid_t ProcessEncapsulation::startProcess()
{
    this->_pid = fork();

    if (!this->_pid) // If child
        this->processMain();
    return this->_pid;
}

pid_t ProcessEncapsulation::getPid() const
{
    return _pid;
}
