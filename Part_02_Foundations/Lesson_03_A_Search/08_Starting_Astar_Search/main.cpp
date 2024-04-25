#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

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
    while (sline >> n >> c && c == ',')
    {

        if (n == 0)
        {
            row.push_back(State::kEmpty);
        }
        else
        {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

std::vector<std::vector<State>> ReadBoardFile(std::string path)
{
    std::ifstream myfile(path);
    std::string line;
    std::vector<std::vector<State>> board;
    while (getline(myfile, line))
    {
        std::vector<State> row = ParseLine(line);
        board.push_back(row);
    }
    return board;
}

// TODO: Write the Search function stub here.
/*
Search( grid, initial_point, goal_point ) :

    1.Initialize an empty list of open nodes.

    2.Initialize a starting node with the following:
        x and y values given by initial_point.
        g = 0, where g is the cost for each move.
        h given by the heuristic function (a function of the current coordinates and the goal).

    3.Add the new node to the list of open nodes.

    4.while the list of open nodes is nonempty:
        4.1 Sort the open list by f-value and pop the optimal cell (called the current cell).
        4.2 Mark the cell's coordinates in the grid as part of the path.
        4.3 if the current cell is the goal cell:
            return the grid.
        else, expand the search to the current node's neighbors. This includes the following steps:
            Check each neighbor cell in the grid to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
            If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
            Mark the cell as closed.

    5.If you exit the while loop because the list of open nodes is empty, you have run out of new nodes to explore and haven't found a path.
*/
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int initial_point[2], int goal_point[2])
{
    std::cout << "No path found!" << std::endl;
    return;
}

std::string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "â›°ï¸   ";
    default:
        return "0   ";
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
    int init_point[2]{0, 0};
    int goal_point[2]{4, 5};
    auto board = ReadBoardFile("C:/Users/zhoul/OneDrive/Desktop/uda_cpp/Cpp_review/27_Formatting_the_Printed_Board/1.board");
    auto solution = Search(board, init_point, goal_point);
    PrintBoard(solution);
}