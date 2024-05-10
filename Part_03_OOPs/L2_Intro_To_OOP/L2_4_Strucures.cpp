#include <iostream>

struct Date {
  int day;
  int month;
  int year;
};

int main() {
  Date date;
  date.day = 1;
  date.month = 10;
  date.year = 2024;
  std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
}