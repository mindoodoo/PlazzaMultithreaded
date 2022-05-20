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
        std::cout << "PARENT: Opening read for parent process" << std::endl << std::endl;
        this->_ipc.openRead();
        std::cout << "PARENT: After opening read for parent process" << std::endl;
        std::string msgRead;
        std::cout << "PARENT: Before reading new msg for PARENT process" << std::endl;
        msgRead << this->_ipc; // BLOCKS HERE
        std::cout << "PARENT: After reading message for parent process" << std::endl;
        std::cout << msgRead << std::endl;
        this->_ipc.openWrite();
        std::cout << "PARENT: After opening write for parent process" << std::endl;
    }
    return this->_pid;
}

pid_t ProcessEncapsulation::getPid() const
{
    return _pid;
}
