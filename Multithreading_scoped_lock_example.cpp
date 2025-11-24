#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1, m2;

void taskA()
{
    std::scoped_lock lock(m1, m2);
    std::cout << "task A aquired both locks" << std::endl;
}
void taskB()
{
    std::scoped_lock lock(m1, m2);
    std::cout << "task B aquired both locks" << std::endl;
}

int main()
{
    std::thread t1(taskA);
    std::thread t2(taskB);
    if (t1.joinable())
    {
        t1.join();
    }
    if (t2.joinable())
    {
        t2.join();
    }
    return 0;
}
