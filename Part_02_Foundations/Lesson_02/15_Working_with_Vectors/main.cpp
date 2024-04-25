#include <iostream>
#include <vector>

int main()
{
    // 1D vector Access
    std::vector<int> a = {0, 1, 2, 3, 4};
    std::cout << a[0] << std::endl;
    // 2D vector Access
    std::vector<std::vector<int>> b = {
        {1, 1, 2, 3}, {2, 1, 2, 3}, {3, 1, 2, 3}};
    std::cout << b[1][2] << std::endl;
    std::cout << b.size() << "x" << b[0].size() << std::endl;
}