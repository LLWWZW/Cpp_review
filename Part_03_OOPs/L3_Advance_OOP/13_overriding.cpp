#include <cassert>
#include <cmath>
#define PI 3.14159

class VehicleModel
{
  public:
    // TODO: Declare virtual function Move()
    virtual void Move(double v, double t) = 0;
};

class ParticleModel : public VehicleModel
{
  public:
    double x, y, theta;
    void Move(double v, double theta) override;
};

void ParticleModel::Move(double v, double t)
{
    theta += t;
    x += v * cos(theta);
    y += v * cos(theta);
}

class BicycleModel : public ParticleModel
{
  public:
    double L{1};
    void Move(double v, double theta) override;
};

void BicycleModel::Move(double v, double t)
{
    theta += v / (L * tan(theta));
    x += v * cos(theta);
    y += v * cos(theta);
}

int main()
{
    // Test function overriding
    ParticleModel particle;
    BicycleModel bicycle;
    particle.Move(10, PI / 9);
    bicycle.Move(10, PI / 9);
    assert(particle.x != bicycle.x);
    assert(particle.y != bicycle.y);
    assert(particle.theta != bicycle.theta);
}