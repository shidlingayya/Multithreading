// 1_singleThreaded.cpp
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void fun1()
{
    std::cout << "thread1 created with id: " << std::this_thread::get_id() << std::endl;
}

void fun2()
{
    std::cout << "thread2 created with id: " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::thread thread1(fun1);
    std::cout << std::endl;
    std::thread thread2(fun2);
    std::cout << std::endl;
    thread1.join();
    thread2.join();
}