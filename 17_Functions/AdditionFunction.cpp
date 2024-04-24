#include <iostream>

// Function declared and defined here.
int AdditionFunction(int i, int j)
{
    return i + j;
}

int main()
{
    auto d = 3;
    auto f = 7;
    std::cout << AdditionFunction(d, f) << "\n";
}