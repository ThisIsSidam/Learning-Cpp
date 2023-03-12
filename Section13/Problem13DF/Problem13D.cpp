// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 11/03/2023
//
// Problem13D Of Learning C++
// After Day39
// Name- Number 'em All
// --------------------------------------

/*
Make a program that makes a copy of a file with number bullets at the start.
There should be a bit of space given between the numbers and the lines. And 
empty lines shouldn't have numbers, only lines with words. 

Joke: Is this descrimination? Giving numbers to only those with characters 
in them. What should this be called? Characterism? Whitespacism? or just
spacism?
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

bool isspace(const std::string &str);

int main() {

    std::ifstream in_file {"RomeoJuliet.txt"};
    std::ofstream out_file {"RomeoJulietCopy.txt", std::ios::app};

    if (!in_file) {
        std::cerr << "Error Opening File!" << '\n';
        return 1;
    }
    if (!out_file) {
        std::cerr << "Error opening file" << '\n';
        return 1;
    }


    std::string line;
    int line_num {0};
    while (std::getline(in_file, line)){
        if (isspace(line)) 
        {
            out_file << line << '\n';
        }
        else
        {
            out_file << std::setw(10) << std::left << ++line_num
                     << line << '\n';

        }
    }

    std::cout << "Copy Made Successfully!" << '\n';

    return 0;
}

bool isspace (const std::string &str) {
    for (int i {0}; i < static_cast<int>(str.length()); i++)
    {
        if (std::isprint(str.at(i)))
        {
            return 0;
        }
    }
    return 1;
}