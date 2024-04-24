#include <iostream>
#include <vector>

int main()
{
    /*For loop with an index variable*/
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << std ::endl;
    }

    /* The Increment Operator */
    auto i = 1;
    auto c = i++; // post-increment assgin i to c and then increments i.
    std::cout << "Post-increment example:" << std::endl;
    std::cout << "The value of c is:" << c << std::endl;
    std::cout << "The value of i is:" << i << std::endl;

    i = 1;
    c = ++i; // Pre-increment increments i and assign i to c.
    std::cout << "Pre-increment example:" << std::endl;
    std::cout << "The value of c is:" << c << std::endl;
    std::cout << "The value of i is:" << i << std::endl;

    /* For Loop with a Container */
    // C++ offers several ways to iterate over containers.
    // One way is to use an index-based loop as above.
    // Another way is using a "range-based loop", which you will see frequently
    // in the rest of this course.
    std::vector<int> a{1, 2, 3, 4, 5};
    for (int i : a)
    {
        std::cout << i << std::endl;
    }
}