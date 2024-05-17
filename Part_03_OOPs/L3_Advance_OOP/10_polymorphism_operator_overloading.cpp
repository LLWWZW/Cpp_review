#include <iostream>

class Point
{

  public:
    Point(int x, int y) : x_(x), y_(y)
    {
    }
    Point operator+(Point p2);
    int x_;
    int y_;
};
Point Point::operator+(Point p2)
{

    return {this->x_ + p2.x_, this->y_ + p2.y_};
}

int main()
{
    Point p1{1, 2};
    Point p2{3, 4};
    Point p3 = p1 + p2;
    std::cout << " x:" << p3.x_ << " y:" << p3.y_ << std::endl;
}