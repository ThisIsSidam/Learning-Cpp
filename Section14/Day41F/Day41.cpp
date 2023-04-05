//----------------------------------------------
// Name- Anshu Kumar Singh a.k.a. Sidam
// Date- 12/03/23
// Purpose- Notes of C++

// Day41 of Learning C++
//----------------------------------------------

/*
== STL ==

STL stands for Standard Template Library. Is is a library of powerful, reusable,
adaptable generic classes and functions.

- It is implemented and used using C++ templates.
- It is an assortment of commonly used containers.
- Known time and size complexity.
- Tried and tested reusability.
- Consistent, fast, type safe and extensive.

= Main elements of STL ====================

Containers- Collections of objects or primary types.
Ex- Arrays, Vectors, Deque, Stack, Set, Map, etc.

Algorithms- Functions for processing sequences of elements from containers.
Ex- Find, Max, Count, Accumulate, Sort, etc.

Iterators- Generate sequences of elements from containers.
Ex- Forward, Reverse, By value, By reference, etc.

= Example of use of STL ========================

#include <vector> Allows working with vectors.
#include <algorithm> Allows use of STL Algorithms.

std::vector vec {1, 4, 2, 3};
std::sort(vec.begin(), vec.end()); This will return a sorted Vector.
std::reverse(vec.begin(), vec.end()); This will return a vector sorted in 
reverse order.

While the .begin() and .end() are iterators.

Again,

int num {std::accumulate(vec.begin(), vec.end(), 0)};
This adds up all elements in the vector from .begin to .end. The third 
argument is very important since it shows from where the adding will start
from. 0 in this case. Then, 10 will be stored in num. And the third argument
also needs to have an appropriate value, 0 in int's case and 0.0 in double's
case.

= Type of Containers =======================

1. Sequence Containers- Array, Vector, List, Forward List and Deque.
2. Associative Containers- Set, Multi Set, Map and Multi Map.
3. Container Adapters- Stack, Queue, Priority Queue. 

Note: Container Adapters don't support iterators. 

= Types of Iterators ========================

Input Iterators- From container to program.
Output Iterators- From program to containers.
Forward Iterators- Navigate one item at a time in one direction.
Bidirectional Iterator- Navigate one item at a time in both the direction.
Random Access- Directly access a container item.

= Types of Algorithms ===========================

There are around 60 or more algorithms which are devided as:
i) Modifying       ii) Non_modifying

= Generic Programming ============================

"Writing code that works with a variety of types as arguments as long as those
argument types meet specific syntactic and semantic requirements."
                            - Bjarne Stroustrup

You may get it with this example even more clearly. Think of a function that 
returns the square of a number. So, you make a function that asks for int as 
parameter and returns an int. But what if when you need to get the square of
a double or a float or a long or something else. You would have to create a 
function for all of them. So, Generic Programming is something with which you
can do that same thing with only a single function.

= Generic Programming with Macros ================================

We have used a macro before. 

#define x y

This is a macro. I don't know if this is the only one or there are more. But 
for now. This is a macro.

It is a preprocessor directive. And we know that preprocessor directives don't
know c++. 

What define does is replace x with y.

In case of,

#define pi 3.14

Where it sees a pi, it will replace it with 3.14. That's it. But we can use it 
with parameters too.
*/

#include <iostream>
#define Max(x, y) ((x > y) ? x : y)
#define Sqr1(a) a*a
#define Sqr2(a) ((a)*(a))

int main() {

    int one {100};
    int two {20};

    int max {Max(one, two)};
    std::cout << max << '\n';

    /*
    What happens is define switches the Max(one, two), that's all. 
    And the statement becomes: 
    
    int max {(one, two) ? one : two};

    It can do that because define doesn't know c++ and hence variable datatypes
    doesn't matter to it. Hence it doesn't requires those. And just does simple 
    substitution. 

    One problem that may arise is that it doesn't follow precedence charts either.
    Hence sometimes the mathmatical answers may not be right. As a solution, it is
    recommended to always keep everything wrapped in parenthesis. So, parenthesis
    will also be substituted along with the value that may help in the calculations.
    */ 


    // Using first Sqr1 Macro 
    // Extra spaces for extra readability
    int result1 { Sqr1 (5) }; // Expected to have 25
    std::cout << "result1 : " << result1 << '\n';

    int result2 { 100 / Sqr1 (5) };  // Expected to have 4
    std::cout << "result2 : " <<  result2 << '\n'; // It messed up

    // Using second Sqr2 Macro
    int result3 { 100 / Sqr2 (5) }; // Exprected to have 4
    std::cout << "result3 : " << result3 << '\n'; // Correct


    return 0;
}