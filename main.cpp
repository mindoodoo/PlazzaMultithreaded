#include <cstdlib>
#include <iostream>
#include <thread>
#include <fstream>
#include <unistd.h>
#include "Kitchen/Ipc.hpp"

int main()
{
   Ipc ipc("TODELETE");

   if (fork()) { // Parent
       std::string msg = "WSG";
       msg >> ipc;
       std::cout << "parent sent message" << std::endl;
       msg << ipc;
       std::cout << msg << std::endl;
   } else { // Child
       std::string msg;

       msg << ipc;
       msg >> ipc;
       std::cout << msg << std::endl;
   }
   std::this_thread::sleep_for(std::chrono::seconds(10));
}

// Peek works when msg sent through echo
// No msg sending through IPC, but non blocking
// Read (right after peak) blocking