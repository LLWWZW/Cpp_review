#include <cassert>
#include <iostream>
#include <string>

class Student
{
  private:
    std::string name;
    int grade;
    double grade_point_average;

  public:
    Student(std::string na, int grad, double gpa);
    std::string GetName()
    {
        return name;
    }
    int GetGrade()
    {
        return grade;
    }
    int GetGPA()
    {
        return grade_point_average;
    }
    void SetName(std::string name);
    void SetGrade(int grade);
    void SetGPA(double gpa);
};

void Student::SetName(std::string name)
{
    this->name = name;
}
void Student::SetGrade(int grade)
{
    if (0 <= grade && grade <= 12)
        this->grade = grade;
    else
    {
        throw std::invalid_argument("values exceeds boundary");
    }
}
void Student::SetGPA(double gpa)
{
    if (0.0 <= gpa && gpa <= 4.0)
        this->grade_point_average = gpa;
    else
    {
        throw std::invalid_argument("values exceeds boundary");
    }
}

// Student::Student(std::string na, int grad, double gpa) : name(na), grade(grad), grade_point_average(gpa)
// {
// }
Student::Student(std::string na, int grad, double gpa)
{
    SetName(na);
    SetGrade(grad);
    SetGPA(gpa);
}
int main()
{
    Student student_first{"Tony", 4, 3.0};
    bool caught{false};

    try
    {
        Student student_second{"Tony", 100, 3.0};
    }
    catch (...)
    {
        std::cout << "Values exceeds boundary" << "\n";
        caught = true;
    }
    assert(caught);
}