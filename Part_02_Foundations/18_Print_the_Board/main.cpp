#include <iostream>
#include <vector>

void PrintBoard(std::vector<std::vector<int>> twod_vector)
{
    for (int j; j < twod_vector.size(); j++)
    {
        for (int i : twod_vector[j])
        {
            std::cout << i;
        }
        std::cout << "\n";
    }
}
int main()
{
    std::vector<std::vector<int>> board{{0, 1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 1, 0}};

    PrintBoard(board);
}