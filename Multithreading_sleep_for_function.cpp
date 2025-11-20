// 1_singleThreaded.cpp
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    std::cout << "Start" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(2s);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Waited : " << elapsed.count() << std::endl;
}