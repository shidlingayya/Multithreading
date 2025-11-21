// 1_singleThreaded.cpp
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void workerthread()
{
    std::cout << "Created workerthread: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Worker thread exited" << std::endl;
}

int main() {
    std::thread t1(workerthread);
    if (t1.joinable())
    {
        t1.detach();
    }
    std::cout << "Main thread exited" << std::endl;
}