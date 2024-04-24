#include <iostream>
#include <string>
#include <fstream>

void ReadBoardFile(std::string file_path)
{
    std::fstream theFile(file_path);
    if (theFile)
    {
        std::cout << "file loaded" << std::endl;
        std::string line;
        while (getline(theFile, line))
        {
            std::cout << line << "\n";
        }
    }
    else
    {
        std::cout << "file didn't be founded" << std::endl;
    }
}

int main()
{
    std::string file_path = "C:/Users/zhoul/OneDrive/Desktop/uda_cpp/Cpp_review/21_Read_the_Board_from_a_File/files/1.board";
    ReadBoardFile(file_path);
}