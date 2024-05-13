#include <iostream>

struct Date {
  int day{1};
  int month{1};
  int year{2000};
};

int main() {
  Date date;
  //   date.day = 1;
  //   date.month = 10;
  //   date.year = 2024;
  std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
}