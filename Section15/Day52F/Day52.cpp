//----------------------------------------------
// Name- Anshu Kumar Singh a.k.a. Sidam
// Date- 30/03/23
// Purpose- Notes of C++
//
// Day52 of Learning C++
//----------------------------------------------

/*
== Lambda Expressions ==

- Are used so that we don't have to create a function for every little piece of code and
because when we make a function, it may be that it was used only once in the whole program.
And the function implementation may be very far away from where it is used, so making 
changes to the function becomes a problem.

- Do not forget about Function Objects. We should use Lambda Expressions for all the small
programs that we need to make, but for the longer function, we should always use function 
pointers.

= Structure =

[] () -> return_type specifiers {};

[] : Capture List- Defines the start of the Lambda.

() : Parameter List- Comma separated list of parameters. 

-> return_type: Return Type- Can be omitted if the return type is void, or if the lambda is
simple, we can leave it to the compiler to deduce it.

specifiers : Optional Specifiers- Mutable and Constexpr.

{} : Body of code.

= Example = 

[] () { std::cout << "Hi"; };
- Simply displays "Hi".

[] (int x) { std::cout << x;};
- Takes x as parameter and displays it.

[] (int x, int y) { std::cout << x + y; };
- Takes two inputs and displays their addition.

Let's see some more.
*/

#include <iostream>

void func () {
    std::cout << "Hi from Proper Function.\n";
}

int main() {

    // Let's see this both ways.
    [] () { std::cout << "Hi from Lambda Expr.\n"; } ();
    // We're calling the lambda with the parens in the end, like we call a 
    // normal function.

    func(); // Calling the proper function.

    auto func1 = [] () { std::cout << "Hi again\n"; };
    func1();
    // We can assign the funciton to a variable. And leave the compiler to 
    // deduce the function type, which is something like std::function. That we'll
    // see a bit later. Kinda like we're giving the function a name. This is for when
    // want to use the lambda multiple times.

    auto func2 = [] (int x, int y) -> int { return x + y; };
    // Setting a return type.

    std::cout << func2(4, 6) << std::endl; 

    // But we can also leave the type for compiler to deduce.

    auto func3 = [] (int x, int y, int z) { return x + y + z; };

    std::cout << func3(3, 5, 2) << std::endl;

    /*
    == Types of Lambda Expressions ==

    - Stateless: Empty Capture List
    - Statefull: Filled Capture List

    = Stateless Lambda =

    An empty capture list means that the expression captures no information from
    it's enviornment, and only knowns about the info passed to it via the parameter
    list.

    The examples we saw above are all Stateless lambda expressions.

    - Note: We can also use reference parameters in lambda expressions.
    */ 

    auto func4 = [] (int &x) { return x++; };
    int forty {40};
    std::cout << forty << std::endl;

    func4(forty);
    std::cout << forty << std::endl;

    // We can also use Pointer parameters.

    auto func5 = [] (int *x) { std::cout << *x << std::endl; };
    func5(&forty);

    // What if we want the a lambda expression to take multiple types of 
    // Parameters.

    auto func6 = [] ( auto x, auto y) { std::cout << x + y << std::endl; };
    func6(3, 4); // It can take ints.
    func6(3.4, 7.5); // Or floats.
    func6(3.5, 3); // Or both at the same time.

    /*
    = Lambda Expressions as Function Parameters =

    - These require you to include <functional> header file.

    void funcnew ( std::function<void(int)> func1) {
        // Function Body
    }

    Here, void in angular brackets is the return type, while the int is the 
    parameter of the function we are giving as parameter.
    
    or we can also do this

    void funcnew ( void (*func1) (int) ) {
        // Function Body
    }

    Here, we are giving the function pointer as the parameter. void in the parens 
    is the return type while int is the parameter. 

    But, now with C++20, we can just do this,

    void funcnew (auto func1) {
        // Function Dody
    }

    Now, we can just leave it all for the compiler to deduce.

    == Returning Lambda Expressions ==

    - This also needs the <functional> header file.

    std::function<void(int)> funcnew () {
        return [] (int x) { std::cout << x; };
    }

    This is simple, just put it as the return type and type out the expression 
    in the return statement.

    or we can just use auto.

    auto funcnew () {
        return [] (int x) { std::cout << x; };
    }

    The question may arise that why would you return a Lambda. And how would you use
    it.

    auto func = funcnew();
    func(10);

    We first saved the returned lambda in a variable. Now we know the type it gets,
    std::function<void(int)> for this specific one. Then we can use it like we normally 
    do.

    We'll know it's main use with Stateful lambda expressions.

    One last thing:

    = Predicate Functions =
    A function that takes one or more values as parameters and returns a boolean value,
    is known as Predicate function. 

    There isn't much here about this. But, reference website is just for these situations.    

    */    

    return 0;
}