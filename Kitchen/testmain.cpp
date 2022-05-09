//
// Created by mindoo on 09.05.22.
//

#include <iostream>
#include "Kitchen.hpp"

int main()
{
    std::string ipcName = "testNamedPipe";
    Kitchen testKitchen(2, ipcName);

    if (testKitchen.startProcess()) {
        std::cout << "Outside if\n";
        testKitchen.sendMessage("Hello world !");
    }
}
