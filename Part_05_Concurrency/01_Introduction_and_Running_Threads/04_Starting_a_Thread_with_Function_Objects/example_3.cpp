#include <iostream>
#include <thread>

class Vehicle
{
  public:
    Vehicle(int id)
    {
        _id = id;
    }
    void operator()()
    {
        std::cout << "Vehicle object has been created: " << _id << std::endl;
    }

  private:
    int _id;
};

int main()
{
    // create thread
    std::thread t = std::thread(Vehicle(1));
    t.join();
    return 0;
}