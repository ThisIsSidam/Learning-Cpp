//----------------------------------------------
// Name- Anshu Kumar Singh a.k.a. Sidam
// Date- 15/03/23
// Purpose- Notes of C++
//
// Day46 of Learning C++
//----------------------------------------------

/*
== Vectors == 
We have previosly studied vector but there's a little more. 

Vectors have dynamic size which is automatically handled. It can expand and contract as
needed on it's own. Elements of an array are stored in continous memory like arrays.

Like, if index 1, 2 and else will be stored right after each other.

Direct element eccess at constant time. Meaning it doesn't matter how many elements there
are in the vector. Accessing will be quick.

This is same for insertion and deletion of elements on the back, with push_back and 
pop_back.

Although this isn't the case with insertion and deletion of elements in the middle. 
It happens in Linear time, because the compiler has too go through the whole vector
or atleast parts of vector to do the job. 

All iterators are supported by vector but they may become invalid. 

Now let's get to practical work.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void display(std::vector<int> &vec) 
{
    std::cout << "[ ";
    for (auto i: vec) 
    {
        std::cout << i << " ";
    }
    std::cout << "]\n";
}

int main() {

    // Basic Declaration and Initialisation
    std::vector<int> vec1 {1, 4, 6, 2, 6};
    std::cout << "Vec1: ";
    display(vec1);

    // Full vector Assignation
    vec1 = {7, 2, 6, 4, 7};
    // Dynamic size, hence size can be different.
    std::cout << "Vec1: ";
    display(vec1);

    // Now, some functions
    std::cout << "Front element: " << vec1.front() << '\n';
    std::cout << "Back element: " << vec1.back() << '\n';
    std::cout << "Max Size of vector: " << vec1.max_size() << '\n';
    std::cout << ".at method on index 2: " << vec1.at(2) << '\n';
    std::cout << "[] operator on index 2: " << vec1[2] << '\n';
    std::cout << "Size: " << vec1.size() << '\n';
    std::cout << "Empty? Bool: " << vec1.empty() << '\n';
    
    // There's lots more that we have previously seen like, sort, reverse sort,
    // swap that also work here. Just check cpp reference website for all
    // kinds of functions.

    // Capacity is the number of space already alloted to the vector. It can be
    // greater than size. When capacity is exceeded, more memory space is alloted 
    // to the vector, and capacity doubles up.
    std::cout << "Capacity: " << vec1.capacity() << '\n';

    // Adding element
    vec1.push_back(3);
    std::cout << "Vec1: ";
    display(vec1);
    std::cout << "Capacity: " << vec1.capacity() << '\n';
    // Capacity has doubled up. And now this many elements can 
    // be fitted in without increasing allocated memory space.

    vec1.pop_back();
    //removing one element.
    std::cout << "Vec1: ";
    display(vec1);

    vec1.shrink_to_fit();
    // Decreases capacity to only fit the current elements.
    std::cout << "Capacity: " << vec1.capacity() << '\n';

    vec1.reserve(100);
    // This is to beforehand allocate space for the vector.
    std::cout << "Capacity: " << vec1.capacity() << '\n';

    /*
    There's also a function called .emplace_back() which is used with 
    class vectors. We have to create a literal class object or an object
    is copied when using push_back. But we just have to give constructor
    arguments to the emplace_back and it will create and add the object 
    for us.

    Ex- 
    Person class.
    Making object: person name {"name", age};

    With emplace back: vector.emplace_back("another hero", 35)'
    */

    // Using find algorithm to get iterator to a number and then inserting
    // a new element at it's position. 
    auto it = std::find(vec1.begin(), vec1.end(), 6);
    if (it != vec1.end()) 
    {
        vec1.insert(it, 15);
        std::cout << "Vec1: ";
        display(vec1);
    }
    else 
    {
        std::cout << "5 not found in array" << '\n';
    }

    // We can also insert entire arrays or parts of arrays
    std::vector<int> vec2 {7, 3, 7, 4, 3, 4, 6, 3};
    std::cout << "Vec2: ";
    display(vec2);
    vec1.insert(it, vec2.begin() + 2, vec2.end() - 2);
    std::cout << "Vec1: ";
    display(vec1);
    // That +2 and -2 is for selecting ony a specific part of 2nd vector.

    // Next we have copy algorithm
    std::copy(vec2.begin(), vec2.end(), std::back_inserter(vec1));
    // First and second arguments are for where to where we have to copy and 
    // the third actually asks for an iterator pointing at the place we want to 
    // paste the copied things. We have given it a funciton that returns an 
    // iterator to the back of a vector. Hence everything is then copied there.
    std::cout << "Vec1: "; 
    display(vec1);

    // There's also this function called copy_if that asks for a function in the
    // end and does the copy according to it.

/*
== Deque ==
Time for another data structer/ container. This one is very similar to vectors
with a slight change.

You first need to have <deque> header file included. 

Deques are double ended queues and are same as vectors so all description text 
in the top apply to this except:

- In deques, elements are devided in groups/blocks in which elements are stored 
in contiguous manner but those blocks themeselves aren't contiguously stored.
They are linked together but not stored one after another. 

- Other difference is that rapid insertion and deletion in the back of a vector
is done via push_back and pop_back in constant time. But deques can do this with
the front too. Deques support rapid insertion and deletion even from the front
of the container with push_front and pop_front.

There maybe more differences that I may not be aware off. But for now, this is all.

Use, functions and declaration and all are pretty much same. So, I won't be repeating
things.

One new function to note is that, deques support a function called, front_inserter.
It is similar to the back_inserter we used. Since vectors only support push_back, 
they only support back_inserter while deques that support push_front can use
front_inserter. The function is same, it returns an iterator to the front of
the deque.
*/
    return 0;
}
