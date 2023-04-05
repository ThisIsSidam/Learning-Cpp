// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 27/03/2023
//
// Problem14D Of Learning C++
// After Day50
// Name - Palindrome 2
// --------------------------------------

/*
This time we are gonna do the same thing we did in the Problem14A, just
with stack and queue. Go!
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cctype>
#include <iomanip>

bool is_palindrome (std::string &);

int main() {

    std::vector<std::string> vec { "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++", 
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome",
        "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(15) << std::left << "Result" << "String\n";

    for (auto i : vec) 
    {
        std::cout << std::setw(15) << std::left << is_palindrome(i) << i << '\n';
    }

    return 0;
}

bool is_palindrome (std::string &str) {
    std::stack<char> reverse;
    std::queue<char> straight;

    for ( auto i {0}; i < str.size(); i++ ) 
    {
        if ( isalpha(str.at(i)) )
        {
            reverse.push(toupper(str.at(i)));
            straight.push(toupper(str.at(i)));
        }
    }

    while ( !straight.empty() )
    {
        if ( reverse.top() != straight.front() )
        {
            return 0;
        }
        reverse.pop();
        straight.pop();
    }
    
    return 1;
}