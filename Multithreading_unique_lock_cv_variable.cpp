#include <iostream>
#include <mutex>
#include <thread>

std::mutex _m;
std::condition_variable cv;

void doTheWork()
{
    std::cout << "Processing the shared data" << std::endl;
}

void waitingForWork()
{
    std::cout << "waiting for data" << std::endl;
    std::unique_lock<std::mutex> lock(_m);
    cv.wait(lock);
    doTheWork();
    std::cout << "Work is completed" << std::endl;
}

void setDataReady()
{
    std::cout << "Sender: Data is Ready" << std::endl;
    cv.notify_one();
}

int main()
{
    std::cout << "Start of main() " << std::endl;
    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);
    t1.join();
    t2.join();
    return 0;
}
