// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 18/03/2022
//
// Day5 Of Learning C++
// --------------------------------------

#include <iostream>
#define x 4
using namespace std;

int main()
{

    // --Sizeof() Operator--
    // Used to know the size of stuff.

    // int num {54};
    // cout << sizeof(num) << endl; // In bytes, and as we learned the memory size an int occupies is 2 or 4 bytes.
    // char alpha {'$'};
    // cout << sizeof(alpha) << endl;

    // We can also just use the datatype names/keywords.
    // cout << sizeof(int) << " " << sizeof(float) << endl;

    //--MIN and MAX--
    /* 
    * This are values that are assigned to vars when needed. Like, when you want to have a var whose value
    * is as low as possible, or as high as possible. 
    * 
    * Also, to use them you have to include <climits>
    * These are- 
    * INT_MIN, SHORT_MIN, LONG_MIN, LLONG_MIN and CHAR_MIN and
    * INT_MAX,SHORT_MAX, LONG_MAX, LLONG_MAX and CHAR_MAX
    * 
    * You can try checking their values with sizeof, just know that they may not be same for every system.
    */

    // --Constants--
    /*
    * Are nothing but just values you can't change.
    * There are mainly 5 types of constants.
    */

    // Literal - Using values as they are.

    // cout << 3 * 4 << endl; // Here, 3 and 4 are literal constants.
    /* 
    * There are also different literals with special words with them.
    * Like, 12L, 344LL, etc.
    * 
    * There are also Escape codes that come in this catagory.
    * '\n' - Next line.
    * '\t' - tab.
    * '\r' - return.
    * '\b' - backspace.
    * "\'" - single quote.
    * '\"' - double quote.
    * '\\' - backslash.
    * 
    * You can include a single quote normally if you are writting in a double, but you can't when you are
    * wring in a single quote, and the same goes for doubles. Let's see an example of all this.
    */

    // cout << "\"Next line \n a tab \t here double\b backspaces\b \"" << endl; 
    // cout << "hello there \r there" << endl;
    // \r returns the cursor to the beginning of the line, and the text from there is not moved, it's overlapped.

    // Const Keyword - You can just add const in the beginning of a var declaration, and it will become a 
    // constant.

    // const int number {343};
    // cout << number << endl;
    // number = 434;  // Run this only when you want to see the error caused when trying to change value of a const.

    // #define preprocessor directive.
    /*
    * It is a preprocessor direcive, so it runs before the compiler and replaces all given words with the 
    * given values.
    * ex- #define pi 3.14
    * 
    * Then it will replace all the pi in the code to 3.14, and as I have told you before, preprocessor doesn't
    * know C++, so it won't tell you if a certain things is gonna cause an error.
    * Hence, it is not told not to be used by my teacher, but we can atleast try, right. 
    */

    // cout << x * 4 << endl;

    /* 
    * There are two more, 
    * Constant Expressions and Enumerated Constants that we don't have to study now, 
    * so just know that there are more that exist.
    * 
    * This is the end of day, we'll solve a problem next and learn about Arrays after that.
    */
    return 0;

}