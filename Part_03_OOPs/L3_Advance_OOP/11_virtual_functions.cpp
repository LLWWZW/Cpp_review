#include <cassert>
#include <cmath>
class Shape
{
  public:
    Shape()
    {
    }
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};

class Rectangle : public Shape
{
  public:
    Rectangle(double length, double width) : length_(length), width_(width)
    {
    }
    double length_;
    double width_;
    double Area() const
    {
        return length_ * width_;
    }
    double Perimeter() const
    {
        return length_ * 2 + 2 * width_;
    }
};

class Circle : public Shape
{
  public:
    Circle(double radius) : radius_(radius)
    {
    }
    double radius_;
    static double constexpr pi = 3.1415926;
    double Area() const
    {
        return pi * pow(radius_, 2);
    }
    double Perimeter() const
    {
        return 2 * pi * radius_;
    }
};

int main()
{
    double epsilon = 0.1; // useful for floating point equality

    // Test circle
    Circle circle(12.31);
    assert(abs(circle.Perimeter() - 77.35) < epsilon);
    assert(abs(circle.Area() - 476.06) < epsilon);

    // Test rectangle
    Rectangle rectangle(10, 6);
    assert(rectangle.Perimeter() == 32);
    assert(rectangle.Area() == 60);
}