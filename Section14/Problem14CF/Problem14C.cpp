// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 25/03/2023
//
// Problem14C Of Learning C++
// After Day49
// Name - A lotta words
// --------------------------------------

/*
We have a text file that has a part of a story. We have to make a program that 
lists all the words in text file with the number of occurences
of the words. You must use a map of <std::string, int> pair for this, where the string is the 
word and the int is the number of occurences. 

Now Go!
*/

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

std::string& clean_it (std::string&);
bool check (std::string &, std::map<std::string, int> &);
int search(std::stringstream &, std::string &);

void find_board(std::map<std::string, int> &);

int main() {

    std::string file_name;
    std::cout << "Enter the file path: ";
    std::cin >> file_name;

    std::ifstream ifile {file_name};
    std::stringstream ss;

    if (ifile) 
    {
        while (!ifile.eof())
        {
            std::string to_clean;
            std::getline(ifile, to_clean);

            std::string cleaned { clean_it(to_clean) };
            ss << cleaned;
        }    
    }
    else {
        std::cerr << "File not found!\n";
        return -1;
    }

    std::map<std::string, int> reg1;

    while (!ss.eof())
    {

        std::string word;
        if (ss >> word)
        {
            if ( !check(word, reg1) )
            {
                reg1[word] = search(ss, word);
                ss.seekg(0);
            
            }
        }
    }


    find_board(reg1);

    ifile.close();
    return 0;
}

std::string& clean_it (std::string &raw) {
    std::string buff;
    buff += "\n";

    for ( int i {0}; i < static_cast<int>(raw.size()); i++) 
    {
        if (isalpha(raw.at(i)) or iswspace(raw.at(i)))
        {
            buff += tolower(raw.at(i));
        }
        
    }

    raw = buff;
    return raw;
}

bool check (std::string &str, std::map<std::string, int> &reg) {

    if ( reg.size() == 0 )
    {
        return 0;
    }

    auto it = reg.begin();
    while ( it != reg.end()  )
    {
        if (str == it->first)
        {
            return 1;
        }
        it++;
    }

    return 0;

    //I just saw the results, and damn, I just messed it all up. Pretty horrible way I went.
    
}

int search(std::stringstream &s, std::string &w) {
    int occur = 1;

    while(!s.eof())
    {
        std::string word;
        s >> word;
        if (word == w)
        {
            occur++;
        }
    }
    return occur;
}

void find_board(std::map<std::string, int> &reg)  {
    auto it = reg.begin();

    std::cout << std::setw(15) << std::left 
              << "Word" << "Occurences" << '\n';

    while (it != reg.end() )
    {
        std::cout << std::setw(15) << std::left 
                  << it->first << it->second << '\n';

        it++;    
    }
}