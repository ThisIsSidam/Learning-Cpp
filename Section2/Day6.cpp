// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 19/03/2022
//
// Day6 Of Learning C++
// --------------------------------------

#include <iostream>
using namespace std;

int main()
{

    /*
    * --Compound Datatypes/ Derived Datatypes--
    * Are datatypes made up of datatypes, like a list of scores, it has multiple ints in it.
    *
    * --Arrays--
    * Come in the catagory of compound datatypes. Take the example of a list of marks of 20 students in school.
    * We'll use that example to explain all the characterisctics of arrays.
    * 
    * Characteristics-
    * - Fixed size- Liked there are fixed number of students which is 20. One more student can't just jump in.
    * - All elements are of the same datatype- All the marks of the students are ints, one can't just be a char.
    * - Contiguous in memory- The values are stored in the memory close to eachother, like the marks of 
    * students of a certain class are stored in a specific file all together, as a chunk.
    * - Individual access- If we want we can find the value of a specific elements, here say if we want to 
    * know the marks of a specific student, we can just search with his roll number, in arrays that roll no.
    * is called index.
    * - No bounds- What if you mistakingly searched for 21st roll no. that doesn't exist, you won't find it, 
    * right. Here, you won't get an error because there is no checking if the given index is in the boundaries
    * or not and may cause and error.
    * - Start with 0- The indexing doesn't start with 1, but with 0. So, if you have 5 elements, the index of
    * the last element will be 4.
    * 
    * 
    * Syntax-
    * datatype name [size] {elements}; You can also just use "=", but will still have to use "{}" for this.
    */

    // int roll_num [5] {1,2,3,4,5};

    /*
    * - If you don't fill the size but all the elements, then it will automatically check the number of 
    * elements and that will be ok too.
    * - If you fill the size but not all the elements, then the remaining will be equal to 0.
    * - If you fill just give 1 elements, then it will only be value for 1st elements and others will be 0.
    * - If you don't fill any elements, all will be 0.
    * 
    * --Indexing/Subscripting--
    * "[]" is called indexing operator. 
    * Write it like "name[index]" undex cout and you will get the element on that index printed out.
    * 
    * If you just use the name of the array, you will just get the memory address of the array.
    */

    // cout << roll_num[2] << " " << roll_num << endl; 

    // Can also assign or overright values.

    // roll_num[4] = 10;
    // cout << roll_num[4] << endl;

    // Run below one to just know that it doesn't give any errors if you go out the walls of shiganshina, I 
    // mean Bounds and replaces it with a random(At least for me) value.

    // cout << roll_num[234] << endl;

    /*
    * --Multilevel/Multidimensional Arrays--
    * 
    * You just gotta put another value in a square brackets near the previous square brackets and you'll
    * have a 2D array, increase the number of bracks for increasing the dimension. For now, just be happy 
    * with 2 Dimensions.
    * 
    * An array is like a line, take number line. And 2D Array is like a Graph or an Excel sheet, you have to
    * know both the column and row number if you want to know the value. After that, initialisation, and stuff
    * is pretty much the same.
    */

    // int second_array [3][4] { // First comes, row number and then column number.
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // I just did it so I don't have to write it in a single line.

    // cout << second_array[1][3] << endl;
    // second_array[1][3] = 444;
    // cout << second_array[1][3] << endl;

    // This is the end for now, we'll learn Vectors next.

    return 0;

}