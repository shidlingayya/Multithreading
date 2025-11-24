#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;

void worker()
{
    if (m.try_lock()) {
        std::cout << "Worker: acquired lock\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        m.unlock();
    }
    else {
        std::cout << "Worker: could NOT acquire lock\n";
    }
}

int main()
{
    //It is locked here, Hence worker thread will fail to lock it
    std::lock_guard<std::mutex> main_lock(m);

    std::thread t(worker);
    t.join();
}