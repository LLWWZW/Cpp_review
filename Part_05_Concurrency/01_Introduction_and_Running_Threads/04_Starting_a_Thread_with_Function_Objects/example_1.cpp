#include <iostream>
#include <thread>

class Vehicle
{
  public:
    void operator()()
    {
        std::cout << "Vehicle object has been created \n";
    }
};

int main()
{
    // create a thread
    // std::thread t((Vehicle()));
    std::thread t((Vehicle())); // 最左优先解析规则（Most Vexing Parse）
    /*双重括号的使用是为了避免最左优先解析规则。单个括号 std::thread t(Vehicle()); 会被编译器解释为一个函数声明（函数 t
     * 返回一个 std::thread 对象，并接受一个 Vehicle 类型的参数）。双重括号 (Vehicle()) 明确表示创建一个临时 Vehicle
     * 对象并传递给 std::thread 构造函数。*/

    // std::cout << "Concurrent world from main! Thread id = " << std::this_thread::get_id() << std::endl;

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    t.join();

    return 0;
}