#include <assert.h>
class Square
{
  public:
    Square(float side) : side_(side)
    {
    }

  private:
    float side_;
    friend class Rectangle;
};

class Rectangle
{
  public:
    Rectangle(Square s) : width(s.side_), height(s.side_)
    {
    }
    int Area();

  private:
    float width;
    float height;
};

int Rectangle::Area()
{
    return width * height;
}

int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16);
}