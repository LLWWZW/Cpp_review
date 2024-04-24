/*vector push_back*/

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3};
    for (int i; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    v.push_back(4); // !!!! important
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "\n";
    }
}