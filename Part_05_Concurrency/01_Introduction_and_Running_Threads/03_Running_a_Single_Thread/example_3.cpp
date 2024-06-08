#include <iostream>
#include <thread>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "This concurrent id:" << std::this_thread::get_id() << std::endl;
    std::cout << "Finished work in thread\n";
}

int main()
{
    // create thread
    std::thread t(threadFunction);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Main concurrent id:" << std::this_thread::get_id() << std::endl;
    std::cout << "Finished work in main\n";

    //
    // wait for thread to finish
    t.join();
}