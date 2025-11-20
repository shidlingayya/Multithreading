#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void thrad1() {
    for (int i = 0; i < 100; ++i) {
        cout << "A";
        this_thread::sleep_for(chrono::milliseconds(2));
    }
}

void thread2() {
    for (int i = 0; i < 100; ++i) {
        cout << "B";
        this_thread::sleep_for(chrono::milliseconds(2));
    }
}

int main() {
    thread worker1(thrad1);
    thread worker2(thread2);
    worker1.join();
    worker2.join();
    cout << "\n";
}