#include <iostream>
#include <vector>

// Define a function "AdditionFunction" here.
// Instead of just two ints, this function should accept a vector<int>
// as the argument, and it should return the sum of all the ints in the vector.

int AdditionFunction(std::vector<int> v)
{
    int sum = 0;
    for (int i : v)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    std::vector<int> v{1, 2, 3};
    std::cout << AdditionFunction(v) << std::endl;
}