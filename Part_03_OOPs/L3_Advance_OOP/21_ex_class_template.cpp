#include <assert.h>
#include <sstream>
#include <string>
template <typename KeyType, typename ValueType> class Mapping
{
  public:
    Mapping(KeyType k, ValueType v) : key(k), val(v)
    {
    }
    std::string Print() const
    {
        std::ostringstream stream;
        stream << key << ": " << val;
        return stream.str();
    }
    KeyType key;
    ValueType val;
};

// Test
int main()
{
    Mapping<std::string, int> mapping("age", 20);
    assert(mapping.Print() == "age: 20");
}