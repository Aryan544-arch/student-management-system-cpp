#ifndef STUDENT_MANAGEMENT_HPP
#define STUDENT_MANAGEMENT_HPP

#include <iostream>
#include <vector>

class StudentRecord
{
private:
    std::string studentName;
    double studentMarks;
    int studentAge;

public:
    StudentRecord(std::string studentName, double studentMarks, int studentAge)
    {
        if (studentName.empty())
            this->studentName = "Unknown";
        else
            this->studentName = studentName;
        studentMarks > 0 ? this->studentMarks = studentMarks : this->studentMarks = 0;
        studentAge > 0 ? this->studentAge = studentAge : this->studentAge = 0;
    }
    void updateMarks(double marks)
    {
        marks > 0 ? studentMarks = marks : studentMarks = 0;
        std::cout << "Marks Updated Successfully" << std::endl;
    }
    std::string getName() const
    {
        return studentName;
    }
    void display() const
    {
        std::cout << "Student Name: " << studentName << std::endl;
        std::cout << "Student Age: " << studentAge << std::endl;
        std::cout << "Student Marks: " << studentMarks << std::endl
                  << std::endl;
    }
};

extern std::vector<StudentRecord> students;
std::string normalizeName(std::string);
void displayMainMenu();
void addStudent();
void viewAllStudent();
void searchStudent();
void updateStudentMarks();
void deleteStudentRecord();

#endif