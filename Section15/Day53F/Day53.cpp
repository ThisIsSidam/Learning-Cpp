//----------------------------------------------
// Name- Anshu Kumar Singh a.k.a. Sidam
// Date- 30/03/23
// Purpose- Notes of C++
//
// Day53 of Learning C++
//----------------------------------------------

/*
== Stateful Lambda Expressions ==

- These have non-filled Capture Lists, which defines what information/variable
should be captured.

- In case of Stateless Lambdas, the compiler actually makes an object of a simple 
class that it creates. It looks something like this:



Stateless Lambda: [] (int x) { std::cout << x };

Class: 
class CompilerGeneratedName {

public: 
    CompilerGeneratedName();  

    void operator() (int x) {
        std::cout << x;
    }
};



It is a simple class with no attributes, a simple constructor and an overloaded 
Parenthesis Operator/ Function Call operator that does the function work.

Now, let's see the case of Stateful Lambdas:




A variable present in the program: int x {10};

Stateful Lambda: [x] (y) { std::cout << x + y; };

Class: 
class CompilerGeneratedName {

private: 
    int x;

public: 
    CompilerGeneratedName(int x) : x{x} {};

    void operator() (int y) const {
        std::cout << x + y;
    }
};



This is also a pretty simple class, where we see that the lambda expression 
takes a variable in the program and it becomes a attribute of the class. And to
make it so the member variable doesn't get modified, the overloaded 
Function call operator is now a const method.

But if we want to modify that variable. We can use the "mutable" keyword.

[x] () mutable {};


= Capturing Mode =

There are three of these and automatically capture all the variable used in 
the body of the lambda expression.

[=] : Takes all variables by values.
[&] : Takes all variables by reference.
[this] : Used inside of a class, it captures the object by reference.

Note: In a class, any of these will work the same. They'll take attributes by
reference. Since, "=" will make confusions, it will be removed or maybe is 
already removed.

If we want, we can also explicitly get a variable by ref. when using "=" like
this:

[=, &x] () {};

Or, get a variable by value while using "&":

[&, x] () {};

Note: These modes are specified at the start of the capture list, all the explicit
captures come after them.  

Note: Adding an explicit capture which takes a variable by value while using the "="
mode or an explicit capture which takes a variable by ref. whle using the "&", causes 
error as the modes have already included those variable.
*/

#include <iostream>

int main() {

    int x {10};

    // Normally just capturing and using an enviornment variable.
    [x] (int y) { std::cout << x + y << '\n'; } (10);

    // Making it mutable.
    [x] (int y) mutable {
        x = 20;
        std::cout << x + y << '\n';
    } (20);

    // It was with value, hence copied, original variable wasn't modified.
    std::cout << "Original Var: " << x << '\n';

    // Now, with refernce and only modifying it.
    [&x] (int y) mutable {
        x = 20;
        std::cout << x + y << '\n';
    } (30);

    // The original is also modified now.
    std::cout << "Original Var: " << x << '\n';

    // Let's make more variable.
    int y {50};
    int z {200};

    // And use the Capture modes.
    [=, &y] (int a) mutable {
        x = 5000;
        y = 10000;
        std::cout << x + y + a << '\n';
    } (20000);
    // x was taken by value with the capture mode, y was explicitly taken by
    // reference. And z wasn't needed, so wasn't taken at all.

    std::cout << x << " " << y << " " << z << '\n';

    // "&" capture mode can be used the same way.
    // "this" capture mode can be used inside a class to get access to attributes.

    // Note: Lambdas are very useful with Standard Template Library functions and 
    // hence are used with them a lot.

    



    return 0;
}