#include <cassert>
#include <iostream>

struct Date {
 public:
  void Day(int d) { this->day = d; }  // mutator
  int Day() { return this->day; }     // accessor
  void Month(int m) { this->month = m; }
  int Month() { return this->month; }
  void Year(int y) { this->year = y; }
  int Year() { return this->year; }

 private:
  int day{1};
  int month;
  int year;
};

int main() {
  Date date;
  date.Day(29);
  date.Month(8);
  date.Year(1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}