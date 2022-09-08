// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 06/09/2022
//
// Day34 Of Learning C++
// --------------------------------------

    /* 
    * --Exception Handling--
    * Is used for Synchronous Code, and Asynchronous code. And what do those two big words mean,
    * I don't know either, I'm gonna search them after this and hope I edit it afterwards. 
    * 
    * What are Exceptions?
    * - Insufficient Resources    - Invalid Resources    - Invalid Operators
    * - Range Violations    - Underflow and overflows    - and many more
    * 
    * Exception Safe- This is said when your code handles exceptions.
    * 
    * -Terminology-
    * Exception- An object or primitive type that signals an error has occured.
    * 
    * Throwing an exception (Raising an exception) - Your code detects that error has occured or
    * will. Place where error occcured may not know how to handle the error, and code can throw an
    * exception describing the error to another part of the program that knows how to handle the
    * error.
    * 
    * Catching the exception (Handle the error) - Code that handles the exception. May or may not 
    * cause the program to terminate.
    * 
    * -Keywords-
    * throw- Throwing an exception, and is followed by an argument.
    * 
    * try- In curly braces called the try block, you place code that may throw an exception. If the
    * block throws an exception, the try block is exited. The throw exceptio is handled by catch 
    * handler. If no catch handler exists, the program terminates.
    * 
    * catch- First in  normal brackets, in contains the type of exception it will catch, it's like 
    * an argument in functions, then comes curly braces where you place code that is executed when this
    * catches the exception.
    * 
    * A basic example- 
    * 
    * double average {}; 
    * 
    * try{  // If total is 0 then throw it otherwise just calculate the average.
    *   if(total== 0) {
    *       throw 0;
    *   }
    *   average = sum/total;
    * } // If total actually was 0 then show the error message.
    * catch(int &ex) {
    * std::cerr << "Can't devide by zero" << '\n';
    * }
    * 
    * std::cerr also comes from iostream and is used to show error messages. 
    * 
    * The same thing could have been done if-else, then why did we use it. It's because this is just an
    * example of how things are, actually exception handling is used with functions.
    * 
    * Note- Error like this could actually occur, diving an int with zero could crash the program. Dividing
    * a floatig point with zero will give "inf" as result which means infinity and dividing zero with zero 
    * gives "nan" as result which says "Not a Number". 
    * 
    * Now let's see it's use in a function.
    */

#include <iostream>
#include "Savings.h"

double calc(int sum, int total){ 
    if (total == 0) {
        throw 0;
    }
    return static_cast<double>(sum)/total; // Coz the return type is double.
}

int main()
{
    // Exception handling in function
    double average {};
    int sum {}, total {};
    std::cout << "Enter Sum and Total with a space: ";
    std::cin >> sum >> total;
    try{
        average = calc(sum, total);
        std::cout << "Average: " << average << '\n';
    }
    catch(int &ex) {
        std::cout << "Can't divide with zero." << '\n';
    }

    /*
    * --Handling Mulitple Exception--
    * This is easy, just add a new catch hanler with the newer type of exception. If that type is 
    * thrown, it will catch and say, "I got you kid". 
    * 
    * --Catch all Handler--
    * This handler is to be added at the end. If an exception is thrown whose handler doesn't exist,
    * this will catch it. Syntax-
    * 
    * catch(...) { // Three dots
    *   std::cerr << "Some Unknown Error Occured1" << '\n';
    * }
    * 
    * --Stack Unwinding--
    * This is something hard to understand, so I made a different file for it. Go check out, Day35. 
    * Should have I named it 34.5.
    * 
    * --User defined Exception Classes--
    * 
    * Best Practices- 
    * Throw an object not a primitive type(int, double, we threw int in examples above for easy
    * explanation).
    * Throw an object by value and catch it by reference(or const ref).
    * 
    * Ex- 
    * Besides throwing 0 as exception, we should have-
    * 
    * class DivideByZeroException {} // Even an empty class does it, default constructor is enough.
    * 
    * Throwing -> throw DivideByZeroException();
    * 
    * Catching -> catch(const DivideByZeroException &ex) {..}.
    * 
    * 
    * --noexcept keyword--
    * This keyword is used at the end (Same place as overload keyword).
    * You are not allowed to throw exceptions in noexcept functions, if an exception is thrown,
    * the the program will be terminated and the exception won't be handled.
    * 
    * --Class Level Exception--
    * Exception can be thrown from withing a class. 
    * 
    * From method- There work the same as functions.
    * 
    * Constructor:
    * - Constructor may fail.
    * - Constructor don't return any value, so that messes things up.
    * - Thrown an exception in constructor only when you can't initialize an object. 
    * Ex- When you are opening an account, given balance is zero and opening zero balance accounts are 
    * not allowed, so you throw an exception.
    * 
    * Destructor:
    * - Destructors are noexcept by default. 
    * - So, never ever throw exceptions inside it, otherwise nothing will be deleted and data will leak.
    *    
    * Let's see an example.
    */

   int balance {};
   std::cout << "Enter balance amount: ";
   std::cin >> balance;
   try {
       Savings_Acc hero {balance};
       hero.display_balance();
   }
   catch (const IllegalBalanceException &ex) {
       std::cerr << "Opening zero balance accounts is not allowed!" << '\n';
   }
   catch (const NegativeBalanceException &ex) {
       std::cerr << "Negative balance is not allowed! " << '\n';
   }
   catch (...) {
       std::cerr << "It seems like the bank is having hiccups! Try later." << '\n';
   }

    return 0;
}


