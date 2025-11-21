#include <iostream>
#include <thread>

void newThreadCallback(int* p)
{
    std::cout << "Inside thread: " << *p << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    *p = 10;
}

void startThread()
{
    int* p = new int();
    *p = 10;
    std::cout << "Value of p inside main thread: " << *p << std::endl;
    std::thread t1(newThreadCallback, p);
    t1.detach();
    delete p;
    p = nullptr;
}

int main()
{
    startThread();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return 0;
}