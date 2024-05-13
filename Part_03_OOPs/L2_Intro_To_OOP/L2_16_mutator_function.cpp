#include <cassert>
#include <cstring>
#include <iostream>
#include <string>

class Car
{
    int horsepower{0};
    int weight{0};
    char *brand;

  public:
    int GetHorsepower() const;
    void SetHorsepower(int hp);
    int GetWeight() const;
    void SetWeight(int wt);
    std::string GetBrand() const;
    void SetBrand(std::string brd);
};

int Car::GetHorsepower() const
{
    return horsepower;
}

void Car::SetHorsepower(int hp)
{
    horsepower = hp;
}

int Car::GetWeight() const
{
    return weight;
}

void Car::SetWeight(int wt)
{
    weight = wt;
}

std::string Car::GetBrand() const
{
    std::string result = "Brand name: ";
    result += Car::brand;
    return result;
}

void Car::SetBrand(std::string brd)
{
    Car::brand = new char[brd.size() + 1];
    strcpy(brand, brd.c_str());
}

// Test in main()
int main()
{
    Car car;
    car.SetBrand("Tata");
    std::cout << car.GetBrand() << "\n";
}