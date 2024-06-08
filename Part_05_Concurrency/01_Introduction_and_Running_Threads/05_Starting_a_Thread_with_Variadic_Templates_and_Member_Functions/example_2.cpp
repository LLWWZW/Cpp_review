#include <iostream>
#include <string>
#include <thread>

void Printname(std::string name, int waitTime)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    std::cout << "Address of name: " << &name << std::endl;
    std::cout << "Name (from Thread) = " << name << std::endl;
}

int main()
{
    std::string name1 = "MyThread1";
    std::string name2 = "MyThread2";

    std::cout << "Address of name1: " << &name1 << std::endl;
    std::thread t1(Printname, name1, 50);

    std::cout << "Address of name2: " << &name2 << std::endl;
    std::thread t2(Printname, std::move(name2), 100);
    t1.join();
    t2.join();

    // print name from main
    std::cout << "Name (from Main) = " << name1 << std::endl;
    std::cout << "Name (from Main) = " << name2 << std::endl;
    return 0;
}