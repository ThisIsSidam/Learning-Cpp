// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 20/03/2023
//
// Problem14A Of Learning C++
// After Day46
// Name - Palindrome
// --------------------------------------

/*
A palindrome is something that has the same spelling the other way around. Like, peep, deed, wow, noon.
It can also be a whole sentence, like, Santa at nasa. In this problem we will have a vector of strings, 
and we'll send all the strings of that vector into a function that expects a string reference and 
that function will return a bool; it will check if the string is a palindrome or not. 

In the function, we have to use deques and change the whole string into capital case to avoid case 
differnce while checking, and also remove all non-alphabet characters. Then check whether the string 
was a palindrome or not and return true or false. And yeah, neatly display it. Go!
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <iomanip>

bool is_palindrome(std::string &str);

int main() {

    std::vector<std::string> vec {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++", 
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome",
        "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(20) << std::left << "Result" << "String" << '\n';
    for ( auto s : vec) 
    {
        std::cout << std::setw(20) << std::left << is_palindrome(s) << s << '\n';
    }

    return 0;
}

bool is_palindrome(std::string &str) {
    std::deque<char> deq;
    std::deque<char> reverse_deq;
    
    for ( auto i : str ) 
    {
        if ( isalpha(i) ) 
        {
            deq.push_back(toupper(i));
            reverse_deq.push_front(toupper(i));
            
        }
    }

    return deq == reverse_deq;
}
