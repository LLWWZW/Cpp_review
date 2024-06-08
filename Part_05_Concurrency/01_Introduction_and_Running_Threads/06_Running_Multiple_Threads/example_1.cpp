#include <iostream>
#include <thread>
#include <vector>

void printHello()
{
    // perform work
    std::cout << "Hello from Worker thread #" << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; i++)
    {

        // lw: std::thread 是一个不可复制的类型
        // std::thread t(printHello);
        //  threads.push_back(std::move(t)); // works
        threads.push_back(std::thread(printHello)); // works
        //  or
        // threads.emplace_back(std::thread(printHello)); // 导入右值，临时变量
        // threads.push_back(t); // compile error;
    }
    std::cout << "Hello from Main thread #" << std::this_thread::get_id() << std::endl;

    for (auto &t : threads)
    {
        t.join();
    }
    return 0;
}