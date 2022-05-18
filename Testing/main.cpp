#include <iostream>
#include "ThreadEncapsulation.hpp"

void printNumbers(int a, int b, int c) {
    std::cout << a << b << c << std::endl;
}

int main()
{
    ThreadEncapsulation<int, int, int> thread(&printNumbers, 1, 2, 3);
    thread.join();

    return 0;
}