#include <iostream>
#include<thread>
#include<atomic>
std::atomic<int> temp(0);

void increment_temp()
{
    std::cout << "Inside th1: " << std::endl;
    temp++;
    std::cout << temp << std::endl;
}

void decrement_temp()
{
    std::cout << "Inside th2: " << std::endl;
    temp--;
    std::cout << temp << std::endl;
}

int main()
{
    std::thread th1(increment_temp);
    std::thread th2(decrement_temp);
    th1.join();
    th2.join();
    return 0;
}