#include <iostream>

void hello()
{
    std::cout << "Hello, World!" << std::endl;
}

class Human
{
};
class Dog
{
};
class Cat
{
};

void hello(Human human)
{
    std::cout << "Hello, Human!" << std::endl;
}
void hello(Dog dog)
{
    std::cout << "Hello, Dog!\n";
}
void hello(Cat cat)
{
    std::cout << "Hello, Cat!\n";
}

int main()
{
    hello();
    hello(Human());
    hello(Dog());
    hello(Cat());
}