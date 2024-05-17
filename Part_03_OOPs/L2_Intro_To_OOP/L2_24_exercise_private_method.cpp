#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

class Sphere
{
  public:
    Sphere(float radius)
    {
        SetRadius(radius);
    }
    float GetRadius() const;      // accessor
    void SetRadius(float radius); // mutator
    float Volume() const;

  private:
    float radius_;
    float volume_;
    static constexpr float pi_ = 3.14159; // be evaluated at compile time instead of runtime
    void Validate();
};

void Sphere::Validate()
{
    if (radius_ < 0)
    {
        throw std::invalid_argument("Radius now is less than 0");
    }
}

float Sphere::GetRadius() const
{
    return this->radius_;
}

void Sphere::SetRadius(float radius)
{
    radius_ = radius;
    Validate();
    volume_ = pi_ * 4 / 3 * pow(radius_, 3);
}

float Sphere::Volume() const
{
    return volume_;
}

int main()
{
    Sphere sphere(5);
    assert(sphere.GetRadius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);

    sphere.SetRadius(3);
    assert(sphere.GetRadius() == 3);
    assert(abs(sphere.Volume() - 113.1) < 1);

    bool caught{false};
    try
    {
        sphere.SetRadius(-1);
    }
    catch (...)
    {
        std::cout << "Radius now is less than 0" << std::endl;
        caught = true;
    }
    assert(caught);
}