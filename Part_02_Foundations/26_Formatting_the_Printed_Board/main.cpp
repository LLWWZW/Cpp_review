/*
enumerator
An enum, short for enumerator, is a way to define a type in C++ with values that are restricted to a fixed range.
For an explanation and examples, see the notebook below.
*/

/*
Enums
C++ allows you to define a custom type which has values limited to a specific range you list or "enumerate".
This custom type is called an "enum".

Suppose you were writing a program that stores information about each user's car, including the color.
You could define a Color enum in your program, with a fixed range of all the acceptable values:

We want to limited the possible colors.

    white
    black
    blue
    red

https://en.cppreference.com/w/cpp/language/enum

scoped enums
    => enum + class/structure + name {items}

unscoped enums (only remove the class/sturcture from scoped enums)
    => enum + name {items}

*/

#include <iostream>

void scoped_enum()
{
    enum class Color
    {
        white,
        black,
        blue,
        red
    };
    Color my_color;
    my_color = Color::blue;

    // Test to see if my car is red.
    if (my_color == Color::red)
    {
        std::cout << "The color of my car is red!"
                  << "\n";
    }
    else
    {
        std::cout << "The color of my car is not red."
                  << "\n";
    }
}

void unscoped_enum()
{

    enum Color
    {
        white = 0,
        black,
        blue,
        red
    };

    Color my_color = blue;
    std::cout << my_color << "\n";
    // Test to see if my car is red.
    if (my_color == red)
    {
        std::cout << "The color of my car is red!"
                  << "\n";
    }
    else
    {
        std::cout << "The color of my car is not red."
                  << "\n";
    }
}

void enum_switch()
{
    enum class keypad
    {
        up,
        down,
        left,
        right
    };
    keypad input;
    input = keypad::down;

    switch (input)
    {
    case keypad::up:
        std::cout << "up"
                  << "\n";
        break;
    case keypad::down:
        std::cout << "down"
                  << "\n";
        break;
    case keypad::left:
        std::cout << "left"
                  << "\n";
        break;
    case keypad::right:
        std::cout << "right"
                  << "\n";
        break;
    }
}

int main()
{
    enum_switch();
}