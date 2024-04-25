#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum class State
{
    kEmpty,
    kObstacle
};

std::vector<State> ParseLine(std::string line)
{
    std::istringstream sline(line);
    int n;
    char c;
    std::vector<State> row;
    State curstate;
    while (sline >> n >> c && c == ',')
    {
        if (n == 0)
        {
            curstate = State::kEmpty;
        }
        else if (n == 1)
        {
            curstate = State::kObstacle;
        }
        row.push_back(curstate);
    }
    return row;
}

std::vector<std::vector<State>> ReadBoardFile(std::string path)
{
    std::ifstream myfile(path);
    std::vector<std::vector<State>> board{};
    if (myfile)
    {
        std::string line;
        while (std::getline(myfile, line))
        {
            std::vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

// TODO: Create the CellString function here,
// using the following return strings:
// "⛰️   "
// "0   "
std::string CellString(State cell)
{

    switch (cell)
    {
    case State::kEmpty:
        return "0";
    case State::kObstacle:
        return "⛰️   ";
    }
}

void PrintBoard(const std::vector<std::vector<State>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            std::cout << CellString(board[i][j]);
        }
        std::cout << "\n";
    }
}

int main()
{
    auto board = ReadBoardFile("C:/Users/zhoul/OneDrive/Desktop/uda_cpp/Cpp_review/27_Formatting_the_Printed_Board/1.board");
    PrintBoard(board);
}
