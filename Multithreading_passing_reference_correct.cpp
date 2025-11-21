#include <iostream>
#include <thread>

void threadCallback(int const& x)
{
    int& y = const_cast<int&>(x);
    ++y;
    std::cout << "Inside thread: " << y << std::endl;
}

int main()
{
    int x = 10;
    std::cout << "Value of x inside main thread (before join): " << x << std::endl;

    std::thread t(threadCallback, std::ref(x));
    t.join();  // Wait for thread to finish

    std::cout << "Value of x inside main thread (after join): " << x << std::endl;
    return 0;
}