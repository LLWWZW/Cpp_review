#include <iostream>

int main()
{
    int i = 1;
    while (i <= 10)
    {
        if (i % 2 == 0)
        {
            std::cout << i << "\n";
        }
        i++;
    }
}