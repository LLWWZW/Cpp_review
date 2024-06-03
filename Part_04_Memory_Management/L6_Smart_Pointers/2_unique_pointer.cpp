#include <memory>
void UniquePointer()
{
    std::unique_ptr<int> unique(new int);
    *unique = 2;
}