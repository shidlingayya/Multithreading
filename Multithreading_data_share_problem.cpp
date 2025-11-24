#include <iostream>
#include <mutex>
#include <thread>

std::mutex m_mutex;

void shared_print(char value, int index) 
{
   // m_mutex.lock();
    std::cout << value << index << std::endl;
   // m_mutex.unlock();
}

void fun(char value, int count)
{
    for (auto i = 0; i < count; ++i)
    {
        shared_print(value, i);
    }
}

int main()
{
    std::thread th1(fun, 'A', 5);
    std::thread th2(fun, 'B', 5);

    if (th1.joinable())
    {
        th1.join();
    }

    if (th2.joinable())
    {
        th2.join();
    }

    return 0;
}