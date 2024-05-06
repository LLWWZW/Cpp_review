#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

enum class State
{
    kStart,
    KFinish,
    kEmpty,
    kObstacle,
    kClosed,
    kPath
};

const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

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

int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>> &open_nodes, \ 
            std::vector<std::vector<State>> &grid)
{
    std::vector<int> node = {x, y, g, h};
    open_nodes.push_back(node);
    grid[x][y] = State::kClosed;
}

bool Compare(std::vector<int> node1, std::vector<int> node2)
{
    if (node1[2] + node1[3] > node2[2] + node2[3])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CellSort(std::vector<std::vector<int>> *v)
{
    std::sort(v->begin(), v->end(), Compare);
}

bool CheckValidCell(int x, int y, std::vector<std::vector<State>> &grid)
{

    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
    {
        if (State::kEmpty == grid[x][y])
        {
            return true;
        }
    }

    return false;
}

void ExpandNeighbors(std::vector<int> &current_node, int *goal, std::vector<std::vector<int>> &openlist, std::vector<std::vector<State>> &grid)
{
    int curx = current_node[0];
    int cury = current_node[1];
    int curg = current_node[2];
    int curh = current_node[3];
    int newg = curg + 1;
    std::cout << __func__ << ", cru x:" << curx << ", cur y:" << cury << "\n";

    for (int i = 0; i < 4; i++)
    {

        int poetential_x = curx + delta[i][0];
        int poetential_y = cury + delta[i][1];

        // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        //  if the point is State::kEmpty (which means not kObstcal, kPath)
        if (CheckValidCell(poetential_x, poetential_y, grid))
        {
            // Increment g value, compute h value, and add neighbor to open list
            // for future use.
            int newh = Heuristic(poetential_x, poetential_y, goal[0], goal[1]);
            std::cout << poetential_x << poetential_y << goal[0] << goal[1] << newg << newh << "\n";
            AddToOpen(poetential_x, poetential_y, newg, newh, openlist, grid);
        }
    }
}

std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid,
                                       int initial_point[2], int goal_point[2])
{
    // initialize the paramters
    std::vector<std::vector<int>> open{};
    int x = initial_point[0];
    int y = initial_point[1];
    int g = 0;
    int h = Heuristic(x, y, goal_point[0], goal_point[1]);
    AddToOpen(x, y, g, h, open, grid); // add x,y,g,h (state) into OPEN LIST;

    while (open.size() > 0)
    {
        CellSort(&open);
        std::vector<int> current = open.back();
        open.pop_back();
        x = current[0];
        y = current[1];
        grid[x][y] = State::kPath;
        if (x == goal_point[0] && y == goal_point[1])
        {
            grid[initial_point[0]][initial_point[1]] = State::kStart;
            grid[goal_point[0]][goal_point[1]] = State::KFinish;
            return grid;
        }
        ExpandNeighbors(current, goal_point, open, grid);
    }
    std::cout << "No path found!" << std::endl;
    return std::vector<std::vector<State>>{};
}

std::string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "â›°ï¸   ";
    case State::kPath:
        return "ðŸš—   ";
    case State::kEmpty:
        return "E   ";
    case State::kClosed:
        return "C   ";
    case State::kStart:
        return "ðŸš¦   ";
    case State::KFinish:
        return "ðŸ   ";
    default:
        return "?   ";
        // TODO: Add cases to return "ðŸš¦   " for kStart
        // and "ðŸ   " for kFinish.
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
    auto board = ReadBoardFile("C:/Users/zhoul/OneDrive/Desktop/uda_cpp/Cpp_review/Part_02_Foundations/Lesson_03_A_Search/08_Starting_Astar_Search/1.board");
    auto solution = Search(board, init_point, goal_point);
    PrintBoard(solution);
}