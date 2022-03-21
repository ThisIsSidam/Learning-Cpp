// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 20/03/2022
//
// Day7 Of Learning C++
// --------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    /* --Vectors--
    * 
    * C++ is mainly an Object-Oriented Language (OOL), and when we will learn that, we'll learn what objects
    * clearly are, for now, just know that Vectors are objects.
    * 
    * Characteristics-
    * - Including the vector file through the preprocessor directive is needed for using vectors, in it,
    * vectors come from the C++ Standard Template Library, so you'll have to add std with the scope
    * resolution operator(::) to use it, unless you specify namespace std in the start.
    * - Unlike arrays, it can grow and shrink at execution time.
    * - If we want, we can have bounds checking in this.
    *
    * Syntax-
    * vector <datatype> name;
    *  
    * Let's create a couple vectors now. 
    */

    vector <int> number_list; // Creates an empty vector.

    vector <int> zeroes (5); // Creates a vector containing 5 zeroes.

    vector <int> numbers {1, 2, 3, 4, 5}; // No need to specify size if we're just gonna give all the elements.

    vector <int> five_eight (5, 8); // In the parens, we first put how many and then what, so five eights.

    // Outputing the way we outputted array elements with indexing.

    // cout << five_eight[3] << " " << five_eight[4] << endl;

    /*
    * But since vectors are objects, there are something special called methods.
    *
    * name.at(index)
    * 
    * It includes the vector name, with dot operator and "at" method and then the index in parens.
    * And this, includes bounds checking, with the previous method, no bounds checking is available and 
    * some random number can get in the program causing errors and we won't even know what the error is. 
    * But, here we get bounds checking and with it, we'll get to know where we did wrong.
    */
    
    // cout << numbers.at(3) << " " << numbers.at(1) << endl;
    // cout << zeroes.at(23) << endl; // This is to check bounds checking.

    /* 
    * --More Methods--
    * 
    * There are lots of different kinds of methods for different kinds of use.
    * 
    * name.size() tells us the size.
    * 
    * name.push_back() appends another element. 
    * We'll learn more as we progress.
    */

    // cout << numbers.size() << endl;
    // numbers.push_back(6);
    // cout << numbers.size() << " " << numbers.at(5) << endl;

    /*
    * --Multidimensional Vectors--
    *
    * We can just cover a vector by a vector to create a 2d vector, give it data as we gave to 2d arrays.
    * And can access it by using .at().at() and the normal array method is also available.
    */

    // vector <vector<int>> two_dimensional {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // };

    // cout << two_dimensional[2][2] << " " << two_dimensional.at(2).at(2) << endl;

    // This is just the start of Arrays and Vectors, we'll learn loads more as we progress.
    // Next we'll solve a problem and learn

    return 0;

}