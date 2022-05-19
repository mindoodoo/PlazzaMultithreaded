#include <cstdlib>
#include <iostream>
#include "ThreadPool.hpp"

void waitSomeTime(int time)
{
    std::cout << "Waiting for : " << time << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::cout << "Done waiting for : " << time << std::endl;
}

int main()
{
    ThreadPool<int> pool(3);

    for (int i = 10; i > 0; i--)
        pool.pushJob(ThreadPool<int>::Job(waitSomeTime, i));

    pool.start();

    return 0;
}