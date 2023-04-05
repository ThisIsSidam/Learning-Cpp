//----------------------------------------------
// Name- Anshu Kumar Singh a.k.a. Sidam
// Date- 15/03/23
// Purpose- Notes of C++
//
// Day45 of Learning C++
//----------------------------------------------


/*
== Array ==
Now we'll start learning pretty much all the types of containers. Starting with arrays.
It's not the normal arrays that we used to use, those are called Raw Arrays. These
are from the array class.

You have to include it with the <array> header file. 

These std::arrays have fixed sizes like normal arrays, and that size must be known as
compile time.

With this you get direct access to elements, and you can use both .at method and the
[] operator. Also that no. of elements don't matter when accessing elements. The 
accessing with take the same time if it has 10 elements or 199999 elements.

These arrays are actually wrappers around raw arrays, and their names do not point 
at the first element of the array. But we can get the address of the array which 
is the address of the first element.

It is preferred to use these instread of raw arrays as they're better.

All the kinds of iterators support std::array and do not invalidate. 
*/

#include <iostream>
#include <array>
#include <algorithm>

// This is to display any container elements
void display(std::array<int, 10> &ary) 
{
    for (auto i : ary) 
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int main() {

    // First the type and then the size.
    std::array<int, 10> arr {6, 3, 5, 2, 5, 7, 4, 7, 3, 4};
    // In c++11, we needed to cover the elements in double curlies, but not anymore.

    display(arr);

    // We can also assign whole arrays like this. 
    arr = {7, 2, 5, 7, 6, 7, 8, 5, 2, 1};

    std::cout << "Newly assigned Array: ";
    display(arr);
    
    // These are some functions that we can use with arrays.
    std::cout << "Size of array: " << arr.size() << '\n';
    std::cout << "At operator 2nd index: " << arr.at(2) << '\n';
    std::cout << "[] operator 1st index: " << arr[1] << '\n';
    std::cout << "Front element: " << arr.front() << '\n';
    std::cout << "Back element: " << arr.back() << '\n';
    // Front and back return refernce for those elements.
    std::cout << "Checking if it's empty? Bool: " << arr.empty() << '\n';
    std::cout << "Address of the raw array: " << arr.data() << '\n';
    std::cout << "Max no. of elements storable by array: " << arr.max_size() << '\n';
    // .max_size is used mainly for vector, it shows a big number, the number of how 
    // many elements can be stored. But it's fixed for arrays.

    // Now come the STL algorithms
    std::sort(arr.begin(), arr.end());
    std::cout << "Sorted Array: ";
    display(arr);

    std::reverse(arr.begin(), arr.end());
    std::cout << "Reverse Sorted Array: ";
    display(arr);

    std::cout << "7 is present "
              << std::count(arr.begin(), arr.end(), 7)
              << " times in the array.\n";

    // There's also an algorithm count_if that also asks for a function.
    // Like a function that checks for odd and even and only counts any one.

    std::array<int, 5>::iterator it1 = std::min_element(arr.begin(), arr.end());
    auto it2 = std::max_element(arr.begin(), arr.end());

    std::cout << "Min: " << *it1 << '\n';
    std::cout << "Max: " << *it2 << '\n';

    // This guy returns the first adjacent numbers found on given array.
    int *adj = std::adjacent_find(arr.begin(), arr.end());
    if (adj== arr.end()) 
    {
        std::cout << "No Adjacent Elements in the Array" << '\n';
    }
    else 
    {
        std::cout << "Adjacent Element: " << *adj << '\n';
    }

    std::array<int, 10> arr2 {6, 3, 6, 5, 6, 3, 3, 1, 2, 6};
    std::cout << "Array 2: ";
    display(arr2);

    arr2.swap(arr);
    std::cout << "Arrays are now swapped!";
    std::cout << "\nFirst Array: ";
    display(arr);
    std::cout << "\nSecond Array: ";
    display(arr2);

    return 0;
}

