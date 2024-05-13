#include <cassert>
#include <iostream>
#include <string>

class Person {
 public:
  Person(std::string person_name) : name(person_name) {}
  std::string name;
};

int main() {
  Person tony("Tony");
  Person bob("Bob");
  assert(tony.name != bob.name);
}