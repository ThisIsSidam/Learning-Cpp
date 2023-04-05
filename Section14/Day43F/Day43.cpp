//----------------------------------------------
// Name- Anshu Kumar Singh a.k.a. Sidam
// Date- 13/03/23
// Purpose- Notes of C++
//
// Day43 of Learning C++
//----------------------------------------------

/*
== Using Literal Template Parameter ==
We give a type in main for template functions and classes. But what if we want to
give a value to it. 

Like a function that creates an array but you have to get the array size from user 
while you don't want to ask it with cin. What if you can make it so the size was
given as a template parameter. 
*/

#include <iostream>
#include <string>
#include <vector>

template <int T, typename P>

class person {
    P ary[T];
public:
    person(P x) {
        for(auto i {0}; i < T; i++) {
            ary[i] = x;
        }
    }

    void display() {
        for (auto i: ary) {
            std::cout << i << " ";
        }
        std::cout << '\n';
    }
};
// We here made a class that has a template value and a template type. With them
// we make an array of template type of the template value size. And give some
// argument of template type to the constructor that it fills the array with.
int main() {

    person<5, int> jack {4};
    person<6, std::string> oggy {std::string{"Oggy"}};

    jack.display();
    oggy.display();

    /*
    == Containers == 
    are data structures that can store object of almost any tpe. 
    
    Each container has member functions. Some are specific to containers 
    while lots are available to all containers.

    Each container has an associated header file. #include <container_type>

    = Common Functionality Offered by Containers == 
    
    Default Constructor - Creates empty containers.
    Overloaded Consructor - Comes with many options.
    Copy Constructor - Copy all elements to another container.
    Move Constructor - Move all elements to another container.
    Copy Assignment Operator
    Move Assignment Operator
    size - Tells the number of elements in the container.
    empty - Returns true if container is empty.
    insert
    Comparison Operators ( <, >, <=, >=, ==, !=)
    swap - Swap elemens of two containers.
    erase - Erases one or more elements.
    clear - Erases all elements.

    begin and end- Normal Iterators
    cbegin and cend- Contant Iterators
    rbegin and rend- Reverse Iterators
    crbegin and crend- Constant Reverse Iterators
    Note: Not all containers support all the iterators.

    = What elements can be stored in containers? = 
    When an element is given to store in a container, it's copy is made and then
    it is stored. So, all primitive types are good to go. But the user-defined
    classes must have a copy or move assignment operators overloaded.

    All kinds of containers are further ahead but know that the ordered containers
    require the provided data's type (I'm talking about classes here) to have 
    the less than(<) and equality operators overloaded as it saves the data in 
    ordered manner because of which it requires those operators.

    == Iterators == 
    Allow abstracting an arbitrary container as a sequence of elements.

    They are objects that work like pointers by design, hence support pretty much
    all kinds of stuff that pointers support, like, dereferencing, preincrement 
    and all. 

    Most containerr classes can be traversed with iterators.

    Iterator must be declared based on the container type they will iterate over.

    Syntax: container_type::iterator_type name;
    */
    std::vector<int> fav_num {4, 5, 2, 6};

    std::vector<int>::iterator it = fav_num.begin();
    // .begin() returns an iterator pointing to the first element.

    std::cout << *it << '\n';
    // Very much like pointers.

    // We can also leave it to the compiler to deduce the type of iterator.
    auto it2 = fav_num.end();

    std::cout << *(it2 - 2) << '\n'; // Second last object, 2.
    // .end() returns an iterator pointing to a location right after the last
    // element. NOT THE LAST ELEMENT BUT RIGHT AFTER IT. 
    // Like this-> 4 5 2 6 _
    // .begin() points at 4 while .end() points at the location after last
    // element 6.

    /* 
    == Operations on Iterators ===
    There are lots of operators that can be used on iterators, like
    preincrement and post increment work on all iterators, while there
    some operators that only work on certain iterators, like predecrement
    and postdecrement work only on bi-directional iterators
    
    List can be long so search the net.

    == Use of Iterators in Ranged Based For Loops ==
    On the inside, the ranged based for loops also use iteratos. There code
    looks something like this:

    for (auto it {vec.begin()}; it < vec.end(); it++) {
        //stuff
    }

    == Reverse Iterators ==
    This is an iterator that works backwords. For understanding simply, when
    a reverse iterator is used for a vector like {2, 5, 7, 4}, it becomes 
    something like {4, 7, 5, 2}. Backwards, and everything stays pretty much 
    the same.

    It is made something like this:
    std::vector<int>::reverse_iterator it = vec.begin();
    or
    auto it = vec.rbegin();

    Notice that the auto version's .begin gets an 'r' before 'b'. That is to 
    tell the compiler to create a reverse iterator and not a normal one.

    == More Iterator Types ==
    .begin and .end - iterator - Normal Iterators 
    .rbegin and .rend - reverse_iterator - Reverse Iterators 
    .cbegin and .cent - const_iterator - Constant Iterators 
    .crbegin and .crend - const_reverse_iterator - Constand Reverse Iterators 

    You only need to give the specified begin and end when you are using auto
    otherwise when you are giving the iterator types, you need not do that.

    */

    return 0;
    }