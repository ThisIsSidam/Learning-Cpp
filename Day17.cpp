// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 18/04/2022
//
// Day17 Of Learning C++
// --------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    /* 
    * --Pointers--
    * 
    * are nothing but a bit specail vars that store addresses of different vars.
    * Like you create a var, num1, it has the value 100, it will have an address which is nothing 
    * but a Hexadecimal number or Hex code. Pointers store those hex codes in them.
    * 
    * To create a var, we first give it the datatype of the var whose address it will save.
    * Know that you can't store a double type var in an int type pointer, it is not made for it, you'll
    * just get an error.
    * 
    * After the datatype we give it a name, pretty much same as a var, right. The only diffrence is that 
    * it will have an '*' as a prefix of the name. Then comes the value it will have. There you give a 
    * var but not as it is. You use the reference operator '&' as the perfix of var like we did in 
    * functions. And if you haven't yet decided which var's address you'll save, then never leave it.
    * Or it will be filled with garbage. Instead you should give it the "Null pointer", which is written 
    * as "nullptr". Because it is better to point nowhere instead of pointing at garbage.
    * 
    * Let's try it.
    */

    int num1 {100}; // Creating a var

    int *num1_ptr {&num1}; // Creating a pointer
    cout << "This is the address of num1: " << &num1 << endl;
    cout << "This is the address num1_ptr is pointing at: " << num1_ptr << endl;

    int *null_ptr {nullptr}; // Creatng a pointer that points nowhere
    cout << "This is where null_ptr is pointing at: " << null_ptr << endl;

    int num2 {200};
    num1_ptr = &num2; // Changing address saved in the num1_ptr
    cout << "This is where num1_ptr points now: " << num1_ptr << endl;

    /*
    * --Dereferencing--
    * 
    * Getting a value using an address is called dereferencing.
    * It might be a bit confusing to know that '*' is used for both creating a pointer and 
    * also dereferencing. But it is what it is. 
    * 
    */

    cout << "\n=====================================================\n" << endl;
    int num3 {300};
    int *num3_ptr {&num3};

    cout << "Value of num3: " << num3 << endl;
    cout << "Dereferenced value of num3_ptr: " << *num3_ptr << endl;

    num3 = 600; 
    cout << "Derefernced value of num3_ptr after changing value: " << *num3_ptr << endl;

    *num3_ptr = 900; 
    cout << "Derefernced value of num3_ptr after again changing value: " << *num3_ptr << endl;

    /*
    * --Heap Memory Allocation--
    * 
    * We have learnt Call Stack Memory Allocation, but now it is Heap Memory Allocation which 
    * is also called Dynamic Memory Allocation, In this we don't need a create vars with the normal
    * method, but can directly create it on the go, which won't even have names and can only be 
    * accessed by the pointers we will attach it too. Just know that there is a great risk to it.
    * After use, we must delete the var we created for temprory use or it will cause memory leak. 
    * Like if we created it and changed the address of the pointer, then that value will be left 
    * alone, can be said that it will be orphaned. That will be a memory leak.
    * 
    * We use the 'new' keyword for allocating memory from the heap and 'delete' keyword for deallocating
    * memory from the heap.
    * 
    * And since we know that we are going to allocate memory, we should create a nullpointer first.
    */

    cout << "\n========================================================\n" << endl;
    int *int_ptr {nullptr};
    int_ptr = new int;

    cout << "int_ptr's address: " << int_ptr << endl;
    cout << "int_ptr's value before value assignation: " << *int_ptr << endl;
    
    *int_ptr = 77;
    cout << "int_ptr's value after value assignation: " << *int_ptr << endl;

    delete int_ptr; // Most crucial thing.

    /* Now let's allocate a literal array with this. */

    int *array_ptr {nullptr};

    array_ptr = new int[7]; // Size in the bracks

    cout << "Location of the array: " << array_ptr << endl;
    array_ptr[0] = 9;
    array_ptr[1] = 992;
    cout << "The first element of the array: " << array_ptr[0] << endl;
    cout << "The second and last element of the array: " << array_ptr[1] << endl;

    delete [] array_ptr; // Thats how you delete an array pointer.

    /*
    * --Notation--
    *
    * Using arrays, we can use different kinds of notation, as per our needs. First is Subset Notation,
    * it is simple since we have been using this for quite some time.
    * 
    * array[index]; This is Array Subset notation, since we are using this on a simple array.
    * array_ptr[index]; This is Pointer Subset notation, since we are using this on a pointer.
    * 
    * Know that an array name is like a pointer that points to the memory address of the first element 
    * of the array, and an array pointer does the same.
    * 
    * Second is, Offset notation.
    * 
    * *(array + n); This leads to index n. Remember that the array name points to the location of its 
    * first element. And that n means, n * sizeof(datatype of array). So, suppose it's an int array.
    * The first element is at address 1000(Just suppose), and you want to access 4th index element. 
    * you write, *(array + 4), size of 1 int is 4, then 4*4 is 16 and since array elements are stored
    * contigously in memory, the 4th index element will be at address 1016 and you'll get it.
    * 
    * Note: Size of same datatypes may vary on different systems.
    * 
    * That was Array Offset Notation, you can also use Pointer Offset Notation.
    * *(array_ptr + n); Literally the same right.
    * 
    */
    
    cout << "\n======================================================================\n" << endl;

    int arr[] {1, 4, 5, 7, 34};
    int *arr_ptr {arr};

    cout << "First element of array with Array Subset Notation: " << arr[0] << endl;
    cout << "First element of array with Array Offset Notation: " << *(arr + 0) << endl;
    cout << "First element of array with Pointer Subset Notation: " << arr_ptr[0] << endl;
    cout << "First element of array with Pointer Offset Notation: " << *(arr_ptr + 0) << endl; 

    cout << "Second element of array with Array Subset Notation: " << arr[1] << endl;
    cout << "Second element of array with Array Offset Notation: " << *(arr + 1) << endl;
    cout << "Second element of array with Pointer Subset Notation: " << arr_ptr[1] << endl;
    cout << "Second element of array with Pointer Offset Notation: " << *(arr_ptr + 1) << endl;

    // All this was pretty much repetition of code but I used it as typing practice.
    // Next- Pointer Arithmetic, Const Pointers, Passing Pointers in functions, Returning pointers 
    // from a function, Pointer Pitfalls, Reference and L-values and R-values.
    return 0;

}