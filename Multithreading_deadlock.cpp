#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1;
std::mutex m2;

void fun1()
{
    std::cout << "Enter thread1 " << std::endl;
    std::lock_guard<std::mutex> lock1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock2(m2);

    std::cout << "Thread 1 finished\n";
}

void fun2()
{
    std::cout << "Enter thread2 " << std::endl;
    std::lock_guard<std::mutex> lock2(m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock1(m1);

    std::cout << "Thread 2 finished\n";
}

int main()
{
    std::cout << "Enter main() " << std::endl;
    std::thread t1(fun1);
    std::thread t2(fun2);

    t1.join();
    t2.join();

    return 0;
}