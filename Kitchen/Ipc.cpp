/*
** EPITECH PROJECT, 2021
** Ipc
** File description:
** .
*/

#include "Ipc.hpp"

Ipc::Ipc(const std::string &ipcPath) : _ipcPath(ipcPath)
{
    remove(this->_ipcPath.c_str());
    if (mkfifo(ipcPath.c_str(), 0666) < 0)
        std::cerr << "Error creating fifo pipe : " << strerror(errno) << std::endl;
}

std::string Ipc::getBuf() {
    std::stringstream ss;
    std::string output;
    this->_fileStream.open(this->_ipcPath, std::ios::in);
    this->_fileStream >> output;
    this->_fileStream.close();
    return output;
}

void Ipc::sendBuf(std::string buf) {
    this->_fileStream.open(this->_ipcPath, std::ios::out);
    this->_fileStream << buf;
    this->_fileStream.close();
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
