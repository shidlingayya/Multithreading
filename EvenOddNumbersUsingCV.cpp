#include <iostream>
#include<thread>
#include<functional>
#include<mutex>
#include<condition_variable>

using namespace std;

class PrintOddEven
{
public:
    PrintOddEven(int count = 0) :m_count(count) {}
    virtual ~PrintOddEven() {}
    void printOdd(void)
    {
        while (1)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::unique_lock<std::mutex> olock(m_mtx);
            auto odd_check = [this]()->bool
            {
                return (m_count % 2 == 1);
            };
            m_cond.wait(olock, odd_check);
            std::cout << m_count << std::endl;
            m_count++;
            m_cond.notify_all();
        }
    }

    void printEven(void)
    {
        while (1)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::unique_lock<std::mutex> elock(m_mtx);
            auto even_check = [this]()->bool
            {
                return (m_count % 2 == 0);
            };
            m_cond.wait(elock, even_check);
            cout << m_count << endl;
            m_count++;
            m_cond.notify_all();
        }
    }
private:
    std::mutex m_mtx;
    std::condition_variable m_cond;
    int m_count;
};

int main()
{
    PrintOddEven poe;
    std::thread th1(&PrintOddEven::printOdd, &poe);
    std::thread th2(&PrintOddEven::printEven, &poe);
    th1.join();
    th2.join();
    return 0;
}