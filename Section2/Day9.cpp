// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 24/03/2022
//
// Day9 Of Learning C++
// --------------------------------------

#include <iostream>
using namespace std;

int main()
{

    /*
    * --Increment and Decrement Operator--
    *
    * There operators are unary and increase or decrease 1 from a var. Yeah, sounds pretty simple, right!
    * Overuse of this can makes things too complicated and normal use of these with lots of other operators 
    * is already complicated. Considering 'i' as a var, these are,
    * 
    * Postfix-
    * i++ and i-- adds and subtracts 1 from i after the statement ends.
    * 
    * Prefix-
    * ++i and --i adds and subtracts 1, right there first and uses it.
    * 
    * Ex-
    */
    
    // Postfix
    // int num1 {10}, num2 {20}, num3 {};

    // num3 = num1++ + num2; // num3 = 10 + 20, and then, num1 = 10+1;
    
    // cout << num3 << " " << num2 << " " << num1 << endl;

    // // Prefix
    // num1 = 10; // Assigning values to normal.
    // num3 = 0;

    // num3 = ++num1 + num2; // num1 = 10 + 1, and then, num3 = 11 + 20;

    // cout << num3 << " " << num2 << " " << num1 << endl;

    /*
    * I hope you get it, don't use this multiple times in a single statement. Or the results might 
    * be something unexpected. 
    * 
    * --Mixed Type Expressions--
    * For an operator to work, it has to get the same type of operands if there are more than one.
    * If not, the compiler will try to convert the datatype of the operand itself, which is called 
    * Coercion. But this might affect your calculations and might even give you errors if the 
    * compiler fails to do the coercion.
    * 
    * So, how Coercion happens. There are two things, Promotion and Demotion, every type has a class of
    * its own, which is based on the values they can hold, the higher values they can hold the higher 
    * class they are of.
    * If a variable of lower class, wait you get the idea of how promotion and demotion happens, right.
    * So after that, know that promotion is the first thing that generally happens. Like you are 
    * multiplying 2.5 and 2. Here, 2.5 is of a higher class that 2, so, 2 which is a lower class will be
    * promoted to 2.0 and then multiplied. 
    * Also, know that in demotion, precision cutoff happens. Like, 100.2, when demoted, the value 100.2
    * can't fit in the demoted value and hence it will be 100 and 0.2 goes down the hill.
    * 
    * Well, we can also just convert the variable datatypes ourselves.
    * 
    * --Type Casting--
    * 
    * syntax-
    * static_cast<datatye>(variable)
    * 
    * You put in the datatype you want to convert the variable into in the angular brackets and the name
    * of the variable in the parenthesis, and it's done. 
    */
     
    // int class_number {4};
    // char section {'B'};

    // static_cast<char>(class_number);

    // cout << class_number << section << endl;

    // One more example

    // int num54 {2};
    // double num33 {2.5}, num4343 {};

    // num4343 = static_cast<double>(num54) * num33;

    // cout << num4343 << endl;

    // Next- Equality, Relational and Logical operator along with Short-Circuit Evaluation, Compound 
    // Assignment and Precedence and Associativity.

    return 0;

}