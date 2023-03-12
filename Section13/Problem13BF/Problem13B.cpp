// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 05/03/2023
//
// Problem13B of Learning C++
// After Day38 
// Name - You get zero marks
// --------------------------------------

/*
This time we have to make a program that can print out the mcq results of students
with the help of a file that has their mcq results. There are 10 question with 4 
options each. The first line in the file is the actual answers then it has the name
of the student on second line and the answer of that student on third line, then the
name of the second on fourth line with their answer on fifth line, this keeps going
on. You have to make a program that prints out the individual marks of all the 
students along with the average marks in the bottom. Do this, while making the 
end result asthetically pleasing with the help of manipulators. GO!
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main() {
    
    std::ifstream in_file {"Responses.txt"};

    if (!in_file) {
        std::cerr << "File says, \"I Have a Boyfriend!\"." << '\n';
        return -1;
    }

    std::string right_answers;
    std::getline(in_file, right_answers);

    std::cout << std::setw(22) << "Test Answers" << '\n';
    std::cout << "------------------------------" << '\n';

    int total_marks {0};
    int total_students {0};
    while (!in_file.eof()) {
        std::string name;
        std::getline(in_file, name);
        std::cout << std::setw(15) << std::left << name;
        int marks {0};
        std::string student_marks;
        std::getline(in_file, student_marks);
        for ( int i {0}; i < static_cast<int>(student_marks.size()); i++) {
            marks += (student_marks.at(i) == right_answers.at(i)) ? 1 : 0;
        }
        std::cout << std::setw(15) << std::right << marks << '\n';
        total_marks += marks;
        total_students++;
    }

    std::cout << "------------------------------" << '\n';

    double average_marks {static_cast<double>(total_marks)/total_students};
    std::cout << std::setw(15) << std::left << "Average"
              << std::setw(15) << std::right 
              << std::setprecision(1) << std::fixed 
              << average_marks << '\n';

    in_file.close();
    return 0;
}
