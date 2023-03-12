// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 07/03/2023
//
// Problem13C Of Learning C++
// After Day38
// Name - Find it the hard way
// --------------------------------------

/* 
Well we have another problem. This time we have to create a word finder program.
We have a RomeoJuliet.txt which has the whole script of the Romeo and Juliet play
from the MIT site. The program that we have to make will first ask the user for 
a word and then tell the user how many times that word is present in file. Make
the search tool case sensitive and is also selected as a substring, meaning, when
we search "love", "love" is also counted as well as "loved" since it also has the
word in it as a substring. Go!
*/

#include <iostream>
#include <string>
#include <fstream>


class ErrorOpeningFile : public std::exception 
{
    public: 
        virtual const char* what() const noexcept 
        {
            return "It looks like the file had died in the cold!";
        }
};

class WordNotFound : public std::exception 
{
    public: 
    virtual const char* what() const noexcept 
    {
        return "The word was not found in the file!";
    }
};

int search(const std::string file_name, const std::string word);
void print_result(int, const std::string &);

int main() {
    try {   
    std::string ask;
    std::cout << "Enter the substring you want to search for: ";
    std::cin >> ask;

    int found {search("RomeoJuliet.txt", ask)};

    print_result(found, ask);
    }

    catch(const ErrorOpeningFile &ex) 
    {
        std::cout << ex.what() << '\n';
    }
    catch(const WordNotFound &ex) 
    {
        std::cout << ex.what() << '\n'; 
    }
    
    return 0;
}

int search(const std::string file_name, const std::string word) {
    
    std::ifstream in_file{file_name};

    if(!in_file) 
    {
        throw ErrorOpeningFile();
    }

    char c;
    int letter {0};
    int words_found {0};
    
    while (!in_file.eof()) {
        in_file.get(c);
        if (c == word.at(letter)) 
        {   
            letter++;
        } 
        else 
        {
            letter = 0;
            continue;
        }
        if (letter == static_cast<int>(word.size())) 
        {
            words_found++;
            letter = 0;
        }
    }

    in_file.close();
    return words_found;
}

void print_result(int num, const std::string &word) {

    if (num == 0) 
    {
        throw WordNotFound();
    }

    std::cout << "The word \"" << word 
              << "\" was found " << num 
              << " time(s) in the file." << '\n';
}
