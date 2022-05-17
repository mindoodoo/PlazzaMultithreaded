/*
** EPITECH PROJECT, 2021
** Ipc
** File description:
** .
*/

#include "Ipc.hpp"

Ipc::Ipc(const std::string &ipcPath) : _ipcPath(ipcPath) {
    if (mkfifo(ipcPath.c_str(), 0666) < 0)
        std::cerr << "Error creating fifo pipe : " << strerror(errno) << std::endl;
}

std::string &operator<<(std::string &str, Ipc &ipc) {
    std::ifstream ipcStream(ipc.getIpcPath());
    std::stringstream ss;


    ss << ipcStream.rdbuf();
    str = ss.str();
    return str;
}

std::string &operator>>(std::string &str, Ipc &ipc) {
    std::ofstream ipcStream(ipc.getIpcPath());

    ipcStream << str;
    return str;
}

const std::string &Ipc::getIpcPath() const {
    return _ipcPath;
}
