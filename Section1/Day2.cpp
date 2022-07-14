// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 15/03/2022
//
// Day2 Of Learning C++
// --------------------------------------

#include <iostream>

int main()
{   
    /*
    * One thing that I should tell you before anything, there are multiple little codes that 
    * I write to explain or show a specific thing, so if you'll try trying the last code, the
    * upper codes will also get executed, so, I have commented every little snippet of code, 
    * leaving just the first one, cause that's where you'll start from, right. So, if you want 
    * use them, you will have to uncomment them by removing the "//" and commmet them again 
    * before trying in other snippet. Also, don't be stupid enough to uncomment text instead of
    * code.
    */

    /*
    * Cin and Cout
    *
    * Insertion operator(<<) is used with Cout to print out stuff on the console, and extraction 
    * operator(>>) is used with Cin to take input from the keyboard.
    */

    // int num;
    // std::cin >> num; 
    // std::cout << num << std::endl;

    /*
    * That "int num;", you'll will study that after all this, for now just know that you're 
    * creating a variable, after that with "cin" and "cout" we took input from the user and
    * printed out that value and in the end, "endl" is used to endline the line there, without
    * it, anything that was going to be printed out after it would have been printed right next 
    * to the number we printed. Try removing it, and you'll know, don't leave the "std::".
    * 
    * "std::" means standard namespace. In C++, there are multiple namespace and might have 
    * similarily named keywords and if we use multiple namespaces and use a keyword present in
    * both, the compiler will get confused thinking which one to use, that is called Naming
    * Conflict. To prevent that we use it.
    * 
    * We can also include, "using namespace std;" right after the preprocessor directive if 
    * we know it before hand that we're going to use just that namespace. 
    * 
    * Or we can also write in this way, "using std::cout;" if we want to include specific
    * keywords.
    * 
    * One more thing, spaces are ignored by system, if we input "    34", it will still be 
    * taken as just "34".
    */

    // Also,
    // int num2, num3;
    // std::cin >> num2;
    // std::cin >> num3;
    // // Is same as
    // int num4, num5;
    // std::cin >> num4 >> num5;

    // Sure the vars are different, but we did two line work in one.

    /*
    * Concept of inputting
    *
    * When you give something as input, the system ignores every space before any real 
    * value. When a real value appears, like you gave, "   44543" as input, all spaces 
    * will be ignored and when 4 appears, it is saved in the variable, then the other numbers
    * too and it ends or another space appears the inputting to that variable ends. And if there
    * is still some value remaining in the input you gave, it will then be saved in any other
    * variable, if there is one. All I want to tell you is that you can give two inputs 
    * in one line, the inputting starts after you click Enter. Let's see an example.
    */

    // int num6, num7;
    // std::cin >> num6 >> num7;
    // // Try giving the input in one line with space. 
    // std::cout << num6 << std::endl << num7 << std::endl;

    // We've now come to the end, next time we'll learn variables.

    return 0;

}