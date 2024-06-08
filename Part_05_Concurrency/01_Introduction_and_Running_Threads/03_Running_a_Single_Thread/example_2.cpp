#include <iostream>
#include <thread>

int main()
{
    unsigned int nCores = std::thread::hardware_concurrency();
    std::cout << "This machine supports concurrency with " << nCores << " cores available" << std::endl;
    // std::cout << "Concurrent world from main! Thread id = " << std::this_thread::get_id() << std::endl;
    return 0;
}