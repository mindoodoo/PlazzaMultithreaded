#include <iostream>
#include "../Kitchen/ThreadPool.hpp"

int main()
{
    ThreadPool pool(2);

    pool.start();

    return 0;
}