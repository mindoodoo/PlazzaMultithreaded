#include <cstdlib>
#include <iostream>
#include <thread>
#include <fstream>
#include <unistd.h>
#include "Kitchen/Ipc.hpp"

int main()
{
    std::fstream stream;
    stream.open("TODELETE");

    if (fork()) { // parent
        std::string msg = "Hello world!";
        stream << msg;
        std::cout << "Sent hello" << std::endl;
    } else { // child;
        std::string received;
        std::stringstream ss;

        ss << stream.rdbuf();
        std::cout << ss.str() << std::endl;
        std::cout << "Received message" << std::endl;
    }


//    Ipc ipc("TODELETE");
//
//    if (fork()) { // Parent
////        ipc.openRead();
//        ipc.openWrite();
//
//        std::string msg = "WSG";
//        msg >> ipc;
//        std::cout << "parent sent message" << std::endl;
//    } else { // Child
//        ipc.openRead();
//        ipc.openWrite();
//        std::string msg;
//
//        msg << ipc;
//        msg << ipc;
//        std::cout << msg << std::endl;
//    }
//    std::this_thread::sleep_for(std::chrono::seconds(10));
}

// Peek works when msg sent through echo
// No msg sending through IPC, but non blocking
// Read (right after peak) blocking