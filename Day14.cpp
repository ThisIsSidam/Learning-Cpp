// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 31/03/2022
//
// Day14 Of Learning C++
// --------------------------------------

#include <iostream>
#include <string>

using namespace std;

int main()
{

    /*
    * --C++ Style Strings--
    *
    * First of all, include <string> file, and will have to use the std:: if you're not using namespace std.
    * 
    * And like vector, these strings are objects, and have functions that we called methods.
    * 
    * Some of the characteristics are-
    * 
    * It has dynamic size, so unlike arrays, you don't have limits.
    * It is safer.
    * Can be easily converted.
    * You can use equality, and other operators on them.
    * Doesn't get filled with garbage value if not initialized.
    * 
    * Let's see some ways of initialization.
    */

    // string str1; // No garbage value.
    // cout << str1 << endl;

    // string str2 {"Sidam"}; // Normal.
    // cout << str2 << endl;

    // string str3 {"Sidam", 3}; // Only the first three elements, meaning "Sid".
    // cout << str3 << endl;

    // string str4 {"Sidam", 2, 3}; // Takes 3 chars from the 2nd index char.
    // cout << str4 << endl;

    // string str5 (4, 'a'); //  4 times a - aaaa.
    // cout << str5 << endl;

    /*
    * You can use array style indexing in these. And since strings are objects, .at() method also works.
    * On top of that we can even throw these strins in Range based For Loops, even with datatype int, it
    * will convert the characters into ASCII codes.
    * 
    * -Concatenation-
    * It is adding two strins, C style strings don't support this feature, but C++ Style does.
    * We can even concatenate, a C++ style string with a C style strings, it will be converted.
    * Don't forget that literal strings are C style strings, you can't concatenate these.
    * 
    * Ex-
    * cout << str2 + "is my name." << endl;
    * will work.
    * 
    * But 
    * cout << "I added Sid " + "and Sam to make " + str2 << endl;
    * won't work, and will give an error.
    * 
    * And like the additional operator, we can use other operators with two strings, even if one of them 
    * is of C style.
    * 
    * -Functions-
    * All will be in this format-
    * string_name.method_name(arguments);
    */

    // string str6 {"Hello there, my name is Sidam."};
    // cout << str6 << endl;

    // cout << str6.substr(13, 16) << endl; // Creates a subset, 1st argument is starting index, 2nd is length.

    // cout << str6.find('m') << endl; // Gives the starting index of the char or string you wanna find.
    // // And returns string::npos if the char you wanna find in not present. You can use that in if-else 
    // // statements to do something when not found.

    // cout << str6.find('m', 14) << endl; // 2nd argument is for when you want to find something after a 
    // // specific point, and that argument is the index of that point.

    // str6.erase(0, 13); // Erase a part of the string, 1st argument is starting point, 2nd is length.
    // cout << str6 << endl; 

    // cout << str6.length() << endl; // The length of the string.
 
    // str6.clear(); // Erases the whole string.
    // cout << str6 << endl; // Yup just an empty line thanks to endl.

    /*
    * Now, the inputting problem that comes in C style strings in also here.
    * We can use this-
    * 
    * getline(cin, string_name);
    * 
    * Yup, getline again, but different.
    */

    // string str7;
    // cout << "What are your two favourite villain? Enter with a space: ";
    // getline(cin, str7);
    // cout << "Mine are: " + str7 << endl;
    // cout << "Wow, they match." << endl;

    // Next- 
    return 0;

}