/*
** EPITECH PROJECT, 2021
** Ipc
** File description:
** .
*/

#include "Ipc.hpp"

Ipc::Ipc(const std::string &ipcPath) : _ipcPath(ipcPath)
{
    if (mkfifo(ipcPath.c_str(), 0666) < 0)
        std::cerr << "Error creating fifo pipe : " << strerror(errno) << std::endl;
}

std::string Ipc::getBuf() {
    std::stringstream ss;
    std::string output;

    ss << this->_readStream->rdbuf();
    output = ss.str();
    return output;
}

void Ipc::sendBuf(std::string buf) {
    *(this->_writeStream) << buf;
}

void Ipc::openRead() {
    this->_readStream = new std::ifstream(this->_ipcPath);
}

void Ipc::openWrite() {
    this->_writeStream = new std::ofstream(this->_ipcPath);
}

std::string &operator<<(std::string &str, Ipc &ipc)
{
    str = ipc.getBuf();

    return str;
}

std::string &operator>>(std::string &str, Ipc &ipc)
{
    ipc.sendBuf(str);

    return str;
}

const std::string &Ipc::getIpcPath() const
{
    return _ipcPath;
}
