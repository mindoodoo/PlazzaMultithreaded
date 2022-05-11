/*
** EPITECH PROJECT, 2021
** Main
** File description:
** Main
*/

#include "ProcessEncapsulation.hpp"

pid_t ProcessEncapsulation::startProcess() {
    this->_pid = fork();

    if (!this->_pid)
        this->processMain();
    std::cout << "Pid being returned " << this->_pid << std::endl;
    return this->_pid;
}

pid_t ProcessEncapsulation::getPid() const {
    return _pid;
}

ProcessEncapsulation::ProcessEncapsulation(std::string &ipcPath): _ipcPath(ipcPath)
{
    if (mkfifo(ipcPath.c_str(), 0666) < 0)
        std::cerr << "Error creating fifo pipe : " << strerror(errno) << std::endl;
}

std::string ProcessEncapsulation::receiveMessage() const
{
    std::ifstream ipcStream(this->_ipcPath);
    std::stringstream ss;

    ss << ipcStream.rdbuf();
    return ss.str();
}

void ProcessEncapsulation::sendMessage(std::string msg) const
{
    std::ofstream ipcStream(this->_ipcPath);

    ipcStream << msg;
}
