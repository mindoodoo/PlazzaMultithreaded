#include <cstdlib>
#include <iostream>
#include <thread>
#include <fstream>
#include <unistd.h>
#include "Kitchen/Ipc.hpp"
#include "Kitchen/Kitchen.hpp"

int main()
{
    Kitchen kitchen("ipc/ipc1", 4, 1, 500);

    if (!kitchen.startProcess()) {
        capacity_t capa = kitchen.requestCapacity();
        std::cout << "Capa is : " << capa.totalCapacity;
    }
}

// Peek works when msg sent through echo
// No msg sending through IPC, but non blocking
// Read (right after peak) blocking