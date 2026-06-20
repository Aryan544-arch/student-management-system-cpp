#include <iostream>
#include <vector>
#include "student_management.hpp"
#include <cctype>
#include <limits>

std::string normalizeName(std::string n)
{
    if (n.empty())
    {
        return "";
    }
    bool hasLetter = false;
    for (char ch : n)
    {
        if (ch != ' ')
        {
            hasLetter = true;
            break;
        }
    }
    if (!hasLetter)
    {
        return "";
    }
    n[0] = toupper(n[0]);
    for (size_t i = 1; i < n.length(); i++)
    {
        n[i] = tolower(n[i]);
        if (n[i - 1] == ' ')
        {
            n[i] = toupper(n[i]);
        }
    }
    return n;
}

void displayMainMenu()
{
    std::cout << "Press: " << std::endl
              << std::endl;
    std::cout << "1 to Add Student" << std::endl;
    std::cout << "2 to View All Student Details" << std::endl;
    std::cout << "3 to Search Student" << std::endl;
    std::cout << "4 to Update Student Marks" << std::endl;
    std::cout << "5 to Delete Student Record" << std::endl;
    std::cout << "6 to Exit" << std::endl;
}

void addStudent()
{

    int n;
    std::cout << "How many Students do you want to add: ";
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (n < 1)
    {
        std::cout << "Invalid Size" << std::endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        std::string studentName;
        double marks;
        int age;
        std::cout << "Enter Name: ";
        getline(std::cin, studentName);
        studentName = normalizeName(studentName);
        if (studentName.empty())
        {
            std::cout << "Invalid Name\n";
            i--;
            continue;
        }
        std::cout << "Enter Age and Marks: ";
        std::cin >> age >> marks;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        StudentRecord s1(studentName, marks, age);
        students.push_back(s1);
    }

    if (n == 1)
        std::cout << "Student Added Successfully" << std::endl;
    else
        std::cout << "Students Added Successfully" << std::endl;
}

void viewAllStudent()
{
    int flag = 0;
    std::cout << "Student Records:" << std::endl;
    for (int i = 0; i < students.size(); i++)
    {
        students[i].display();
        flag = 1;
    }
    if (!flag)
    {
        std::cout << "No Student Present" << std::endl;
    }
}

void searchStudent()
{
    std::string studentName;
    std::cout << "Enter Name: ";
    getline(std::cin, studentName);
    studentName = normalizeName(studentName);
    int flag = 0;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getName() == studentName)
        {
            students[i].display();
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        std::cout << "No Student Present" << std::endl;
    }
}

void updateStudentMarks()
{
    std::string studentName;
    double marks;
    std::cout << "Enter Name: ";
    getline(std::cin, studentName);
    studentName = normalizeName(studentName);
    std::cout << "Enter Marks: ";
    std::cin >> marks;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int flag = 0;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getName() == studentName)
        {
            students[i].updateMarks(marks);
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        std::cout << "No Student Present" << std::endl;
    }
}

void deleteStudentRecord()
{
    std::string studentName;
    std::cout << "Enter Name: ";
    getline(std::cin, studentName);
    studentName = normalizeName(studentName);
    int flag = 0;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getName() == studentName)
        {
            students.erase(students.begin() + i);
            std::cout << "Student Deleted Successfully\n";
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        std::cout << "No Student Present" << std::endl;
    }
}