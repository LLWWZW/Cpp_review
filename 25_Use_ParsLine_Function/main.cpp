#include <iostream>
#include <string>
#include <vector>
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

std::vector<std::vector<int>> ReadBoardFile(std::string filePath)
{
    std::fstream the_file_path(filePath);
    std::vector<std::vector<int>> board;
    std::string line;
    while (getline(the_file_path, line))
    {
        board.push_back(ParseLine(line));
    }
    // std::cout << &board << std::endl;
    return board;
}

void PrintBoard(const std::vector<std::vector<int>> board)
{
    std::cout << &board << std::endl;
    // board[0][0] += 1; // error
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            std::cout << board[i][j];
        }
        std::cout << "\n";
    }
}

int main()
{
    std::vector<std::vector<int>> board;
    std::string file_path = "C:/Users/zhoul/OneDrive/Desktop/uda_cpp/Cpp_review/25_Use_ParsLine_Function/1.board";
    board = ReadBoardFile(file_path);
    std::cout << &board << std::endl;
    PrintBoard(board);
}