// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 31/08/2022
//
// Day32 Of Learning C++
// --------------------------------------

/*
--Raw Pointers--
The type of pointers we have been using all this time. It provides us absolute flexibility with 
memory management. - Allocation - Deallocation and also - Lifetime Management.

But has some serious problems:
- Uninitialized (Wild) Pointer
- Memorey leaks
- Dangling Pointer
- and more.
We have discussed them before so we won't repeat them. 

--Smart Pointers--
Smart Pointes are objects that can only point to heap-allocated memory and they automatically call
delete when they are no longer needed and they adhere to the RAII principle.

There are multiple types:
- Unique    - Shared    - Weak 
- Auto (This has goten Deprated, so nor should you use these niether will we study them.)

First thing to do is add <memory> with the preprocessor directive.
Smart pointers are defined by class templates, like vectors, you put the name and put the 
data type in angular brackets. And since there are multiple types of Smart pointers, we 
won't just be writing smart_pointers<data_type> but the type of smart pointer in that place.

Basically smart pointers are wrappers around raw pointers that manage the raw pointers.

Overloaded Operators:
- Dereference(*)    - Member Selection(->)  
- Pointer Arithmetic not supported(++, --, etc)

Can have custom deleters that you can use as needed.

Syntax-
{
    std::smart_pointer_type<some_class> ptr_name = new some_class{};

    ptr->method();
    std::cout << (*ptr);
}

--RAII--
stands for Resource Acquisition Is Initializaton

Common Idiom or Pattern used in software design based on container object lifetime.

RAII object are allocated on stack.

Resource Acquisition:
- Opens a file  - Allocation of memory  - Acquire a lock

Is Initialization:
- The resource is acquired in a constructor.

Resource relinquishing:
- Happen in destructor  - Close file    - Deallocate the memory - Release the lock

--Unique Pointer--
This one is simple smart and very effective.

Goes like this: unique_ptr<T>

Pointer to an object of type T on heap. It is unique, meaning there can only be one
unique pointer pointing to that object. Owns what it points to.

Can't be assigned or copied. Can be moved.

When pointer is destroyed, what it points to is automatically destroyed. 

Functions related to Unique pointer, make_unique keyword and auto keyword are
some things you'll see directly in code. 

--Shared Pointer--
This one provides shared ownership  of the heap object. 

Goes like this: shared_ptr<T>

It isn't unique, there can be many pointers pointing at the same object on heap.
It establishes shared ownership relationship. 

Can be assigned or copied. Can also be moved.

Doesn't support managing array by default. 

It has a method use_count that has a count of the number of shared pointers having 
ownership over this, it automatically increments and decrements itself and when it is
0, the object on heap gets destroyed.
*/

#include <iostream>
#include <memory>
#include <vector>

int main()
{
    std::cout << "===== Unique Pointer Section ====================" << '\n';
    std::unique_ptr<int> knight_of_one {new int{1}};
    std::cout << "Knight of One: " << *knight_of_one << '\n';
    *knight_of_one = 10; // Changing value 
    std::cout << "Knight of One: " << *knight_of_one << '\n';
    std::unique_ptr<int> knight_of_two {new int{2}};
    std::cout << "Knight of Two: " << *knight_of_two << '\n';
    // knight_of_one = knight_of_two; // Assignation not allowed in unique, causes error.
    
    std::vector<std::unique_ptr<int>> knights;
    // knights.push_back(knight_of_one); // Causes error coz this is copying, which isn't allowed.
    knights.push_back(std::move(knight_of_one)); // Move is allowed, this moves ownership and
    // now, knight_of_one is nullified.
    
    knights.push_back(std::move(knight_of_two));

    for(auto &knight: knights) {
        std::cout << "Knight: " << *knight << '\n';
    }
    
    // Now, some functions of Unique Pointers
    std::unique_ptr<int> knight_of_three {new int{3}};
    std::cout << ".get() gives address: " << knight_of_three.get() << '\n';
    knight_of_three.reset(); // Nulls out the pointer and deletes the data.

    // Below lines are used to check if the pointer has value or not.
    std::unique_ptr<int> knight_of_four {new int{4}};
    if(knight_of_one) {
        std::cout << *knight_of_four << '\n'; // knight_of_one has been nulled out.
    } // If this has value, the statement will execute.
    
    if(knight_of_four) {
        std::cout << *knight_of_four << '\n';
    } // This one will execute, since it has value, knight_of_one didn't have value.

    // Now, let's see a better way to initialise the unique pointer.
    std::unique_ptr<int> knight_of_five = std::make_unique<int>(5);
    std::cout << "Knight of Five: " << *knight_of_five << '\n';

    // Use of auto keyword.
    auto knight_of_six = std::make_unique<int>(6);
    std::cout << "Knight of Six: " << *knight_of_six << '\n';

    std::cout << "===== Shared Pointer Section ====================" << '\n';

    auto zero = std::make_shared<int>(0);
    // Initiliasation including new is same as unique pointer.
    // Dereferencing and change of values are same as unique pointer too.
    std::cout << "Use count: " << zero.use_count() << '\n';

    std::shared_ptr<int> lelouch {zero}; //copying is allowed in shared pointer.
    std::cout << "Lelouch: " << *lelouch << '\n';
    std::cout << "Zero: " << *zero << '\n';
    std::cout << "Use count: " << zero.use_count() << '\n';
    
    {
    // Notice that this is a separate block to show you change in use_cout. 
    std::shared_ptr<int> suzaku;
    suzaku = zero; // Assignation is also allowed.
    std::cout << "Suzaku: " << *suzaku << '\n';

    std::cout << "Use count inside separate block: " << zero.use_count() << '\n';
    // This will be three since, zero, lelouch and suzaku are all pointing there.
    }

    std::cout << "Use count outside separate block: " << zero.use_count() << '\n';
    // Block ended and suzaku got destroyed with it.

    /* Note: in unique pointer's case, end of block means destruction of object on heap and 
    nullifing of the pointer. But, here in shared pointer's case it means decrementation of 
    use_count by one and nullifing of pointer. No, destruction of object unless use count
    gets to zero. */

    /* Note: make_unique came with C++14 wheeas, make_shared came in the prior version C++11.
    If it is not necessary to use the "new" method then always use "make", it's efficient. */

    return 0;
}
