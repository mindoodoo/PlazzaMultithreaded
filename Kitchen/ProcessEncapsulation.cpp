/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include "ProcessEncapsulation.hpp"

ProcessEncapsulation::ProcessEncapsulation(std::string &ipcPath) : _ipc(ipcPath) {
    std::cout << "In process encapsulation constructor" << std::endl;
}

ProcessEncapsulation::~ProcessEncapsulation()
{
    if (this->_pid)
        std::remove(this->_ipc.getIpcPath().c_str());
}

pid_t ProcessEncapsulation::startProcess()
{
    this->_pid = fork();

    if (!this->_pid) { // If child
        this->_ipc.openWrite();
        this->processMain();
    } else {
        this->_ipc.openRead();
        std::string msgRead;
        msgRead << this->_ipc;
        std::cout << msgRead << std::endl;
        this->_ipc.openWrite();
    }
    return this->_pid;
}

pid_t ProcessEncapsulation::getPid() const
{
    return _pid;
}
