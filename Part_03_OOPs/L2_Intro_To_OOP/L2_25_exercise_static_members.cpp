#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere
{
  public:
    Sphere(int radius) : radius_(radius), volume_(pi_ * 4 / 3 * pow(radius_, 3))
    {
        if (radius <= 0)
            throw std::invalid_argument("radius must be positive");
    }

    int Radius() const
    {
        return radius_;
    }
    int Volume() const
    {
        return volume_;
    }

    // TODO: mutator
    void Radius(int radius)
    {
        if (radius <= 0)
            throw std::invalid_argument("radius must be positive");
        radius_ = radius;
        volume_ = pi_ * 4 / 3 * pow(radius_, 3);
    }

  private:
    // float constexp pi_{3.14159};
    static constexpr float pi_ =
        3.14159f; // 对于静态成员变量，可以在类内进行初始化，因为它们的内存空间是在编译时分配的，所以初始化也在编译时进行。而对于非静态成员变量，它们的初始化发生在对象的构造过程中，因此不能在类内进行初始化。
    int radius_;
    float volume_;
};

// Test
int main(void)
{
    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);

    sphere.Radius(3);
    assert(sphere.Radius() == 3);
    assert(abs(sphere.Volume() - 113.1) < 1);

    bool caught{false};
    try
    {
        sphere.Radius(-1);
    }
    catch (...)
    {
        caught = true;
    }
    assert(caught);
}