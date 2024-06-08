#include <iostream>
#include <memory>
#include <string>
void function(std::unique_ptr<std::string> &&up)
{
    std::unique_ptr<std::string> _up = std::move(up);
    std::cout << *_up << std::endl; // 输出 "String in Heap"
}

void copy(std::string copied)
{
    std::cout << &copied << std::endl;
}

int main()
{

    // std::unique_ptr<std::string> up = std::make_unique<std::string>("String in Heap");
    // std::cout << up.get() << std::endl;
    // function(std::move(up));
    // std::cout << up.get() << std::endl;
    std::string origin("Origin");
    std::cout << &origin << std::endl;
    copy(origin);
}