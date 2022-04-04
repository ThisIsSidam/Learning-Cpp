// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 24/03/2022
//
// Day10 Of Learning C++
// --------------------------------------

#include <iostream>
using namespace std;

int main()
{

    /*
    * --Equality Operator--
    * 
    * Before you have used the symbol (=) as a symbol that shows that two things are equal. Well, here, 
    * that assignment operator. And (==) is what we use as it's replacement. 
    * 
    * (==) - Equal To Operator - Gives Boolean value True when two values are equal and false for when they
    * aren't.
    * (!=) - Not Equal To Operator - Gives False for when two values are equal and true for when they aren't.
    * 
    * ONE MORE THING, if you output a bool var, 1 is shown for true and 0 for false. 
    * std::boolalpha, changes that, True is printed as true and you get the idea.
    * To reverse this we also have std::noboolalpha.
    */

    bool hello {}, hello2 {};
    hello = 1 == 2;
    hello2 = 1 == 1;

    cout << hello << " " << hello2 << endl;

    cout << boolalpha;

    cout << hello << " " << hello2 << endl;

    // One more thing, see this-

    bool hello3 {};

    hello3 = 12.0 == 11.99999999999999999999;

    cout << hello3 <<endl;

    /* 
    * It shows true because the C++ has his limits, it can't be that precise. But there are some files that 
    * you can include for precision, but that is not needed for now.
    * 
    * 
    * --Relational Operator--
    * 
    * These operators return boolean value according to the relation of the two operands. These are,
    * (<), (>), (<=) and (>=). I don't think they need any explanation.
    * 
    * --Logical Operator--
    * 
    * (Not / !) - NOT operator- You can use the word or the exclamation sign. It is a Unary operator, and 
    * switches the value of the operand. True for False and False for True.
    * 
    * (And / &) - AND operator- It is a binary operator, and is true only if both the operands are true, 
    * otherwise, it's false.
    * 
    * (Or / ||) - OR operator- It is a Binary operator, and returns the value True if any of the operands 
    * are True.
    * 
    * Also, when I say that an oper. is binary, it means it needs atleast two operands. Hence, you can 
    * use AND and OR oper. for more than just that.
    * 
    * And there, is one more (<=>), it is a new operator, that came with C++20, but it's not in our syllabus.
    * So, for now, just know that it also exists.
    */

    // cout << !(1 == 1) << " " << !(1 == 2) << endl;
    // cout << (1 == 1 & 2 == 1) << " " << (1 == 1 & 2 == 2) << endl; 
    // cout << (1 == 1 || 2 == 1) << " " << (1 == 1 || 2 == 2) << endl; 

    /* 
    * If you use multiple logical operators in one statement, you should know the precedence of them, 
    * that which one is used first and after that by the compiler.
    * And that is, NOT > AND > OR
    * 
    * --Short Circuit Evaluation--
    * 
    * When Evaluating a logical Expression, C++ stops  as soon as the result is known.
    * Like, while using the AND oper. if the first operand is known to be false, the whole expressions 
    * will be false, so, we can say that the result is already known, hence C++ stops. 
    * Another example is that, while using the OR oper. if the first operand is known to be true, the 
    * whole expression is known to be true, hence C++ stops. 
    *
    * 
    * --Compound Assignment--
    * 
    * We can mix operands with assignment operator to make these. Like, +=, -=, *=, /= and more.
    * 
    * Think you want to do this- var1 = var1 + var2;
    * Well you can just type- var1 += var2; 
    * It's the same thing, and it is the same for other operators too, just change the operators.
    * 
    * --Presedence and Associativity--
    * 
    * There will be times, when you'll have to use many oper. in a single statement. And you'll be 
    * all messed up thinking which one is used first by the compiler, because without it you won't be able
    * to predict the answer which is a very important thing.
    * To help you with that, there are loads of tables on the internet.
    * 
    * The tables tell you which operator is used first and which is used last in case there are multiple 
    * operators. Also, there are lots of operators who have the same precedence level. In that case, you
    * have to use check the ASSOCIATIVITY, it is usually given in the same table as 'left to right' or 
    * the opposite. 
    * Let's make it clear with an example-
    * x = 2 + a - b;
    * '+' and '-' come on the same precedence level. And the associativilty is 'left to right' as of I 
    * remember. So, first the Addition will take place and then the subtaction, If the operators will be 
    * switched out. The Subtraction will take place first. 
    * It is also true that, either one of the results are not gonna have a difference but with different 
    * and complex operators, the will sure be difference, and I showed you '+' and '-' just for example.
    * 
    * Next - Solve a Problem and then, If-Else and Switch-Case statements along with Conditional operator. 
    */
   
    
    return 0;


}