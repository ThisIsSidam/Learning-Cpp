//----------------------------------------------
// Name- Anshu Kumar Singh a.k.a. Sidam
// Date- 14/03/23
// Purpose- Notes of C++
//
// Day44 of Learning C++
//----------------------------------------------


    /*
    == Algorithm == 
    STL algorithms work on sequence container elements provided to them by an 
    iterator. 

    There are lots of algorithms in the library so you should yourself check 
    the c++ reference website to check them all out.

    Different containers support different types of algorithm. All algorithms
    require iterators but some require some extra information 
    in order to do their work:
    i) Functors (Function Objects)
    ii) Function pointer
    iii) Lambda Expressions

    They actually just require a function that you can give it in these ways.

    == Iterator Invalidation ==
    It is possible that an iterator may become invalid during processing.

    Suppose we are iterating over a vector and we use the .clear method. 
    The element on which don't even exist anymore, the iterators is pointing
    at invalid locations, hence the iterator becomes invalid.

    == find == 
    This is a very useful algorithm that uses the equality operator. So, we 
    can freely use it on primitive types but we need to have the overloaded 
    equality operator to use it on user-defined classes. 

    == for_each ==
    This is an algorithm that asks for a function that it applies to each
    element of the container.

    syntax: for_each(vec.begin(), vec.end(), func); 

    func represents the third argument, where we put in the func. We can 
    either give in a lambda expression that we'll learn in the next section,
    or we can make a function and give in just it's name without any 
    parenthesis. That would be the function pointer. Giving in the parens
    call the function, and without it, it acts like a pointer. The third 
    method is to use a Functor, a function object.

    == Function Object ==     
    Let's just see this one in practice.
    */

#include <iostream>
#include <vector>
#include <algorithm>

struct square_functor { 
    void operator()(int x) { std::cout << x*x << " "; }
};

// We make a public class or a struct and overload the parenthesis. 

square_functor square_1;
// Make a global object of that class.

int main() {

    std::vector<int> vec {5, 7, 2, 6};

    std::for_each(vec.begin(), vec.end(), square_1);
    // Then we give that object as an argument. Then the for_each 
    // algorithm takes that function/functor and applies it to 
    // all elements of the vector elements you gave with the iterators
    // with the () operator that we have overloaded.  

    std::cout << '\n';
    return 0;
}

 