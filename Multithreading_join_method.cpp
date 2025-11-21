// 1_singleThreaded.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <thread>
using namespace std;

class workerthread
{
public:
    void operator()()
    {
        std::cout << "Worker thread " << std::this_thread::get_id() << " Running" << std::endl;
    }
};

int main() {
    std::vector<std::thread> threadList;
    for (auto i = 0; i < 10; i++)
    {
        threadList.push_back(std::thread(workerthread()));
    }
    //std::for_each(threadList.begin(), threadList.end(), std::mem_fn(&std::thread::join));
    std::cout << "Exiting Thread " << std::endl;
}