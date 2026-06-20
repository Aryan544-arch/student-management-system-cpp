#include <iostream>
#include <vector>
#include "student_management.hpp"
#include<cctype>
#include<limits>

int main()
{
    while (true)
    {
        displayMainMenu();
        int n;
        std::cout << "Enter Choice: ";
        std::cin >> n;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (n == 6) return 0;
        switch(n){
            case 1: addStudent(); break;
            case 2: viewAllStudent(); break;
            case 3: searchStudent(); break;
            case 4: updateStudentMarks(); break;
            case 5: deleteStudentRecord(); break;
            default: std::cout<<"Wrong Input"<<std::endl;
        }
    }
}