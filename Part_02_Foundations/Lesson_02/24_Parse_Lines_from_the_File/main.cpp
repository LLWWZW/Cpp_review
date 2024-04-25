#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<int> ParseLine(std::string Line)
{
    std::istringstream theString(Line);
    std::vector<int> outputVector;
    int n;
    char c;
    while (theString >> n >> c)
    {
        outputVector.push_back(n);
    }
    return outputVector;
}
