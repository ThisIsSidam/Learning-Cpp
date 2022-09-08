// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 07/09/2022
//
// Day35 Of Learning C++
// --------------------------------------

/* 
--Stack Unwinding--
Before starting I ask of you to be informed about the "Stack", we've studied it before. 
Go have a revision. 

If an exception is thrown but not caught in the current scope, C++ tried to find a handler 
for the exception by unwindin the stack.

Function in which the exception was not caught terminates and is removed from the call stack. 

If a try block was used, then catch blocks are checked for a match.

If not try block was used or catch handler doens't match, stack unwinding occurs again.

If the stack is unwound back to main and no catch handler handles the exception, the program
terminates.

Now, we'll see exactly this with two cases.

Case 1:
This time an exception won't occur. There are four function below, a, b, c and d. where one opens
another. We open func_a from main and then all the functions are opened. Imagine the stack, main 
is first pushed on the stack then a, b, c then d in the end. And then they start closing off, 
fist d pops off the stack, then c, b, a and main in the end (Popping happens in reverse order of 
pushing). Everything happens normally as expected. Now, in case 2 we'll see what changes a simple 
exception bring.

Case 2:
There are some commented lines that you have to uncomment now, just like previous time all the 
function are pushed on stack with order. Now, func_d has thrown an exception this time. And 
the search has begun for it's catch handler. As we read above, if handler is not found, that 
scope will be removed from stack, hence d pops off the stack, then c, b and a. Then the handler is
found on main. And, did you think that code will again start from func_d, no. We are now on main
and the next code on main will run now. 

All this was to tell you that if the function is removed from the stack, then it's scope ends, 
meaning all the destructors will be called, no next code of that scope will run. So, we MUST 
deal with any pointer that we may have or data will be leaked and it may not sound like a 
big problem but it is. You understand it in the future, for now, know that memory loss is a 
gigantic issue that you MUST AVOID.
*/

#include <iostream>

void func_d() {
    std::cout << "Starting Function D" << '\n';
    // throw 0;
    std::cout << "Closing Function D" << '\n';
}

void func_c() {
    std::cout << "Starting Function C" << '\n';
    func_d();
    std::cout << "Closing Function C" << '\n';
}

void func_b() {
    std::cout << "Starting Function B" << '\n';
    func_c();
    std::cout << "Closing Function B" << '\n';
}

void func_a() {
    std::cout << "Starting Function A" << '\n';
    func_b();
    std::cout << "Closing Function A" << '\n';
}
int main()
{
    std::cout << "Starting Program" << '\n';

    // try {
        func_a();
    // }
    // catch (int &ex) {
    //     std::cerr << "We have an exception!!" << '\n';
    // }

    std::cout << "Closing Program" << '\n';

    /* Return here after completing Day34, this part is offlimits till then.
    *
    *--C++ Standard Library Exception Class--
    *
    * C++ Provides std::exception, which is a base class.
    * In this there is a virtual function named what() that you must implement.
    * You can create your own user-defined exception subclasses. 
    * 
    * Function- virtual const char* what() const noexcept;
    * 
    * It is so you can just do, obj.what() in the catch block and it's error
    * line will be there and you don't have to type it out again and again.
    * 
    * There is a whole Exception class Hierarchy, and know that it is not small.
    * You can search it up and learn more about it.
    * 
    * It's used like this-
    * 
    * class AException: public std::exception {
    *   public:
    *   // constructor
    *   // destructor
    *   virtual const char* what() const noexcept{
    *       return "Error A has happened!";
    *   }
    * };
    * 
    * catch(const AException &ex) {
    *   std:cout << ex.what() << '\n';
    * }
    * 
    * Now you are all done. 
    */

    return 0;
}