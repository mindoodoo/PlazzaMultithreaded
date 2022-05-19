/*
** EPITECH PROJECT, 2021
** Ipc
** File description:
** .
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

class Ipc
{
public:
    Ipc(const std::string &ipcPath);

    const std::string &getIpcPath() const;
    std::string getBuf();
    void sendBuf(std::string buf);

private:
    std::string _ipcPath;
    std::ifstream *_readStream;
    std::ofstream *_writeStream;
};

std::string &operator<<(std::string &str, Ipc &ipc);
std::string &operator>>(std::string &str, Ipc &ipc);
