// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 03/06/2022
//
// Day24 Of Learning C++
// --------------------------------------

/*
* --Operater Overloading--
* We do a hell a lot of stuff with operators right. Like with the assignment op. (=), we assign RHS value to 
* LHS value. Well, what if the LHS and RHS both are class objects. So, we have powers in C++ language to
* overload the operators. Nearly all of them are overloadable but there always are exceptions, right. These 
* Exceptions are- The Scope resolution op. (::), Pointer to Member op. (.*), Dot op. (.) and the sizeof() op.
* 
* And the things we should know before actually doing it are-
* a. Presedence and Associativity can't be changed. 
* b. "Arity" can't be changed. Meanging, if an op, is an Unary op., it will still be Unary and can't be 
* turned into Binary.
* c. Can't create new op.
* d. You can't change how an op. works with primitive types like, ints, doubles, etc.
* e. (), [], -> and the assignment op. (=) can only be declared as member methods and others can be 
* declared as a member method or a global func.
* 
* --Overloading Assingment Op.--
* With assigment op. we can do both copy and move, copy for L-values and Move for R-values.
* But first you need to clarify on what is assignment and what is not.
* Ex-
* int jack = 4; This is initialisation.
* jack = 40; This is assignment.
* 
* Use of Assignment op. for initialisation makes it a bit confusing so, it was just a refreshment.
* Not like I haven't told you this before.
* 
* It is not necessary to have these overloaded assignment operators if you don't have any
* pointers in the class, the compiler will do a nice job for those times. This goes for moving 
* too. But with pointers, you should have these as a must. The not so needed discription and
* what is happening in the code type of commments are given in the Mystring.h file.
*
* --Overloading Operators as Member Methods--
* Like we overloaded the assignment operator, we can overload others too. First we'll see the 
* Unary operators and then head to Binary Operators. And in next file we'll see Overloading
* operators as Functions. And there is a reason I've divided them into two parts and it's that
* they have kinda the same parameters so they can't be used together. Overload the operators as
* member methods or as global functions, the choice is yours.
*
* --Overloading Unary Operators--
* There are four that can be overloaded, and those are ++, --, -, and !. They don't need
* any parameters since they are unary. And with the increment and decrement operator
* we can overload both pre and post, just that to make a difference, we give an unused int
* to the post incr/decrement operator as parameter. Although I won't be trying out those 
* since the class I made is about char.
*
* --Overloading Binary Operators--
* There are lots of those, but I'll just try out these ones, +, -, !=, ==, <,  and >. They all
* require a parameter which is the rhs value. 
*/

#include <iostream>
#include <cstring>
#include "Mystring.h"

int main()
{
    Mystring hello {"Hello"};
    hello.display_details();

    Mystring nul {};
    nul = Mystring{"Nothing"}; //Overloadedd Assignment Op. (Copy)
    nul.display_details();

    Mystring ohayo {};
    ohayo = "Ohayo Gozaimas"; //Overloaded Assigment Op. (Move)
    ohayo.display_details();

    Mystring small_ohayo {}; 
    small_ohayo = -ohayo; //Overloaded Unary Operator (-)
    small_ohayo.display_details(); 

    Mystring hello_goku {};
    hello_goku = ohayo + " Son Goku-San"; // Overloaded Binary Operator (+)
    hello_goku.display_details();

    std::cout << std::boolalpha;
    std::cout << (ohayo == small_ohayo) << '\n'; // Overloaded Binary Operator (==)

    /*
    * Note: While concatinating, if both of the operands are same type objects, like in this case, if both
    * of those are Mystring objects, it's fine. And if the right one is not an object but a string literal 
    * Even that is fine because the compiler will adjust and convert it. But if the left operand is a 
    * string literal. That may cause errors. Since left operands should be Lvalues and not Rvalues.
    * For example -
    * 
    * hello_goku = "Son Goku-San " + ohayo;
    * 
    * This will cause errors.
    */

    return 0;
}