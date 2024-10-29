#pragma once
#include <iostream>
#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>
#include "SpinLock.h"

int counter = 0;
SpinLock lock;
void increment()
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i)
    {
        std::lock_guard<SpinLock> guard(lock);
        ++counter;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration<double>(end - start).count() << std::endl;
}

int counter2 = 0;
std::mutex lock2;
void increment2()
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i)
    {
        std::lock_guard<std::mutex> guard(lock2);
        ++counter2;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration<double>(end - start).count() << std::endl;
}

void LockMain()
{
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << std::endl;

    std::thread t3(increment2);
    std::thread t4(increment2);

    t3.join();
    t4.join();

    std::cout << "Counter2: " << counter2 << std::endl;
}