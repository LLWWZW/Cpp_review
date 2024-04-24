#include <iostream>
#include <string>

// Write the PrintStrings function here.
void PrintStrings(std::string a, std::string b)
{
    std::cout << a << " " << b << std::endl;
}
int main()
{
    std::string s1 = "C++ ist";
    std::string s2 = "super cool.";
    PrintStrings(s1, s2);
}