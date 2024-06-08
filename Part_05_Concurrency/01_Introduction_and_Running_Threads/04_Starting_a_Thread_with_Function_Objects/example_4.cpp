#include <iostream>
#include <thread>

int main()
{
    int id = 0;
    id++;
    auto f1 = [id]() { std::cout << "ID = " << id << std::endl; }; // OK, 'id' is captured by value
    id++;
    auto f2 = [&id]() { std::cout << "ID = " << id << std::endl; }; // OK, 'id' is captured by reference
    // auto f3 = [id]() { std::cout << "ID = " << ++id << std::endl; }; // Error,'id' may not be modified
    auto f4 = [id]() mutable { std::cout << "ID = " << ++id << std::endl; }; // OK, 'id' may be modified

    // execute lambdas
    f1();
    f2();
    std::cout << id << std::endl;
    f4();
    std::cout << id << std::endl;
    return 0;
}