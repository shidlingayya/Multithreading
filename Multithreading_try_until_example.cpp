#include <iostream>
#include <mutex>
#include <thread>

std::timed_mutex test_mutex;

void fun()
{
    auto now = std::chrono::steady_clock::now();

    if (test_mutex.try_lock_until(now + std::chrono::seconds(5)))
    {
        std::cout << "Welcome to Thread fun" << std::endl;
        test_mutex.unlock();
    }
    else
    {
        std::cout << "Failed to acquire lock" << std::endl;
    }
}

int main()
{
    std::thread t1(fun);
    t1.join();
    return 0;
}
