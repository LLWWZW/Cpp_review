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
    void Validate();

  private:
    float radius_;
    const float pi_ = 3.14159;
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
}

float Sphere::Volume() const
{
    return pi_ * 4 / 3 * pow(radius_, 3);
}

int main()
{
    Sphere sphere(5);
    assert(sphere.GetRadius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);
}