#include <iostream>
#include <string>
class Animal
{
  public:
    std::string color;
    std::string name;
    int age;
};

class Snake : public Animal
{
  public:
    float length;
    void MakeSound()
    {
        std::cout << "Hiss...\n";
    }
};

class Cat : public Animal
{
  public:
    float height;
    void MakeSound()
    {
        std::cout << "Meow....\n";
    }
};

int main()
{
    Snake snake;
    snake.age = 15;
    snake.color = "brown";
    snake.length = 10;
    snake.MakeSound();

    Cat cat;
    cat.name = "ajfks";
    cat.age = 20;
    cat.height = 5;
    std::cout << "My name is " << cat.name << " and Age is: " << cat.age << "\n";
    cat.MakeSound();
}