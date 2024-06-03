#include <iostream>
// int x = 20;           // 左值
// int &&rrx1 = x;       // 非法：右值引用无法被左值初始化
// const int &&rrx2 = x; // 非法：右值引用无法被左值初始化

int main()
{
    // int x = 10;
    // int y = 20;
    // double &&rr2 = x + y;
    // std::cout << &rr2 << std::endl;
    // rr2 = 9.4;

    // int x = 10;
    // int y = 20;
    // // 1.右值引用只能引用右值

    // int &&rr1 = 10;
    // double &&rr2 = x + y;
    // const double &&rr3 = x + y;

    // int t = 10;
    // // int&& rrt = t; // 编译报错，不能直接引用左值

    // // 2.但是右值引用可以引用被move的左值
    // int &&rrt = std::move(t);
    // int *&&rr4 = std::move(p);
    // int &&rr5 = std::move(*p);
    // const int &&rr6 = std::move(b);
}