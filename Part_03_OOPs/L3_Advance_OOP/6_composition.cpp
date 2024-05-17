#include <assert.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
// class Wheel
// {
//   public:
//     Wheel() : diameter(50)
//     {
//     }
//     float diameter;
// };

// int main()
// {
//     std::vector<Wheel> wheels{4, Wheel()};
// }

// Define PI
#define PI 3.14159;

class LineSegment
{
  public:
    float length;
};
class Circle
{
  public:
    // float radius_;
    Circle(LineSegment &radius);
    double Area();

  private:
    LineSegment radius_;
};
Circle::Circle(LineSegment &radius) : radius_(radius)
{
}
double Circle::Area()
{
    pow(Circle::radius_.length, 2) * PI;
}

int main()
{
    LineSegment radius{3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}