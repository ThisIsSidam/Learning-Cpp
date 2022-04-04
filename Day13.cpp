// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 30/03/2022
//
// Day13 Of Learning C++
// --------------------------------------

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{

    /*
    * --Character Functions--
    * 
    * We already know how to use char datatype. Well, there are lots of functions that we can use 
    * to help ourself. To use those we first have to add-
    * <cctype> file with the preprocessor directive.
    * 
    * Note: These functions return ASCII code so, you might need to convert them. Also, you may know 0 is 
    * false and 1 is true, now know that any number beside 0 is also true.
    * 
    * Now, let's see what some of these functions are-
    */


    // cout << boolalpha;
    // // These return boolean value-
    // cout << static_cast<bool>(isalpha('3')) << endl; // True if the char is a letter.
    // cout << static_cast<bool>(isalnum('3')) << endl; // True if the char is a letter or a number.
    // cout << static_cast<bool>(isdigit('a')) << endl; // True if the char is a number.
    
    // cout << static_cast<bool>(islower('a')) << endl; // True if the char is a lowercase letter.
    // cout << static_cast<bool>(isupper('a')) << endl; // True if the char is an uppercase letter.

    // cout << static_cast<bool>(isprint('\n')) << endl; // True if the char is a printable char.
    // cout << static_cast<bool>(ispunct('&')) << endl; // True if the char is a punctuation char, like symbols.
    // cout << static_cast<bool>(isspace(' ')) << endl; // True if the char is a whitespace.

    // // These return altered values.
    // cout << static_cast<char>(tolower('A')) << endl;
    // cout << static_cast<char>(toupper('a')) << endl;
 
    /*
    * Now let's see Strings
    *
    * --C style Strings--
    * 
    * First know that when we use characters directly in "", they are also strings are called
    * string literals or literal strings.
    * 
    * Now,
    * You create a char array like this-
    * 
    * char name[6] {"Anshu"};
    * 
    * That is a C style string, a string of characters or say an array of characters.
    * One, very important thing to know is that these strings are terminated by the 
    * NULL character '\0' We don't see it, but it's there, like I created that string 
    * above, "Anshu", it looks like it has 5 characters so I should have created the array
    * of size 5, but no, they should always be atleast 1 extra space for the null char.
    * 
    * If you think that you'll have to add stuff later into it, so, create the array of 
    * much larger size or you can have problems. The other empty spots will be covered by
    * the null chars until you add something else.
    * 
    * Assignation-
    * Think you declared a string but didn't initialize it. And doing that filled the array with garbage 
    * values. So, try to assign value to it later
    * like this-
    * 
    * char title [10];
    * title = "Singh";
    * 
    * Well that's illegal, this won't work. 
    * For assigning values to an initialized char array, you have to do this-
    * 
    * strcpy(string_name, "string");
    * 
    * The function is String Copy, and is called strcpy in short. First argument is the string you 
    * want to copy another string into, second argument is the name of the string or that string itself
    * that you want to add.
    * 
    * Note: You have to add <cstring> for this.
    * 
    * Let's see this in action.
    */ 

    // char hero[50];
    // cout << hero << endl; // Can see garbage value.
    // strcpy(hero, "Captain America"); // This will erase whatever there was previously.
    // cout << hero << endl;

    // // Let's see a couple more functions that come with <cstring>.
    
    // strcat(hero, " and the Winter Soldier"); // Concatenates anothers string on the back of a string.
    // cout << hero << endl;

    // cout << strlen(hero) << endl; // Length of a string.
    
    // cout << strcmp("And", "and") << endl; // Compares two strings.

    /*
    * Now, you know that the extraction operator ">>" only takes input until it encounters a space.
    * And after it the remaining input is left out for another var if there is any. 
    * But what if you want to input a string that has spaces.
    * Normally, the extraction operator will just break it in two. 
    * 
    * So, for that we use getline.
    */

    // char fav_hero[50] {};

    // cout << "What is the name of your favourite SuperHero: ";
    // cin.getline(fav_hero, 25);
    // cout << fav_hero << endl;

    /*
    * In getline function, the first argument is the name of the string you want to take the input in.
    * And the second argument is the limit of characters. Like in the example you can't give any more than
    * 25 characters even if the size of the string is higher. If you do it anyways, the text will be cut out.
    * 
    * Next- C++ Strings and their Functions.
    */

    return 0;

}