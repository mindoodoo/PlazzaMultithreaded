/*
** EPITECH PROJECT, 2022
** theplazza
** File description:
** ProcessEncapsulation
*/

#ifndef PROCESSENCAPSULATION_HPP_
#define PROCESSENCAPSULATION_HPP_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>

class ProcessEncapsulation {
    public:
        ProcessEncapsulation(std::string &ipcPath);
        ~ProcessEncapsulation() = default;

        pid_t startProcess();
        virtual int processMain() = 0;

        // IPC
        std::string receiveMessage() const;
        void sendMessage(std::string msg) const;

        // Getters
        pid_t getPid() const;

    protected:
        pid_t _pid;
        std::string _ipcPath;
};

#endif /* !PROCESSENCAPSULATION_HPP_ */
