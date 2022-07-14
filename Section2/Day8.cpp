// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 22/03/2022
//
// Day8 Of Learning C++
// --------------------------------------

#include <iostream>
using namespace std;

int main()
{

    /*
    * --Expressions--
    * 
    * are a sequence of operators and operands that specify a computation.
    * Examples- 
    * 34  - Literal Expressions
    * 3 + 4 - Addition Expressions
    * a = 5 - Assignation Expressions
    * 
    * --Statements-- 
    * 
    * are a complete line of code that performs some action.
    * Contains Expressions and ends with ';'.
    * 
    * Ex-
    */

    int x; // Declaration Statement
    x = 5; // Assignment Statement

    15 + 25; // Also a statement that is of no use.

    /* 
    * Ahead you will see lots of different kinds of statements like, " If statement", "Whil statement" 
    * and lots more, but not now. 
    * 
    * -- Operators--
    * 
    * -Build up Expressions.
    * -Are usually Binary, meaning that are used with mainly two operands.
    * - Unary and Ternary is also exist.
    * 
    * -Assignment Operator-
    * (=) is used to assign values.
    * Remember that, this
    * int x {2}; is called Initialisation.
    * and this
    * x = 4; is called assigning value.
    * 
    * Always remember, values on RHS are assigned to LHS. If what you typed doesn't make sense to the 
    * compiler, it will throw an error at you.
    * You can also do, 
    * x = y = 100;
    * Both x and y will be equal to 100. See what happens here, First y = 100, is the statement, y is LHS 
    * and 100 is RHS, after that expression is completed, only y remains and becomes the RHS, where x is 
    * the LHS, and since y is equal to 100, the value 100 will be assigned to x.
    * 
    * -Mathematical Operators-
    * 
    * (+) Addition operator is used for adding values. 
    * (-) Subtraction operator is used for subtracting values. 
    * (*) Multiplication operator is used for multiplying values. 
    * (/) Division operator is used for dividing values.
    * (%) Modulus operator gives of the remainder of the division of two numbers.
    * 
    * Remember that, all except the Modulus operator work with both ints and floats, Modulus operator only
    * works with ints. 
    * Also, if you use an operator with ints, the results will also be in ints, in cases of (+, -, *) 
    * getting a float as a result of ints is not possible. It is possible with (/). 
    * Ex - 
    */

    // int num1 {10}, num2 {5};
    // cout << num2/num1 << endl; // Think you'll get 0.5. NO!

    // // The vars need to be float.
    // float float1 {10.0}, float2 {5.0};
    // cout << float2/float1 << endl; // Now, it's what you expected.

    // Next- Increment and Decrement Operator along with Erocion and Type Casting.


    return 0;

}