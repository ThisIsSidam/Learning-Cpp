// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 22/04/2022
//
// Day18 Of Learning C++
// --------------------------------------

#include <iostream>
using namespace std;

int main()
{

    /*
    * --Pointer Arithmetic--
    *
    * Increment and Decrement operators can be used to change the addresses of the pointers, just know
    * the incrementationi and decrementation may vary with different datatype, like in case of ints. 
    * The size of one int is 4 so the address will change by 4 and in case of char, the size of one
    * char is 1, so the address will change by 1. 
    * 
    * pointer++ and pointer--
    * 
    * We also have compound operators, like += and -=. Like when we do pointer += n, where n is an 
    * integer, it is pointer = pointer + n, and the n is actually n * sizeof(datatype of pointer).
    * 
    * We can also, subtract two pointers, it is a bit complicated, but when in case of array, if we 
    * subtract the pointer of let's take the 5th element of the array, to the pointer of let's say
    * 2nd element of the array. Then the result will be the number of elements between them, in this 
    * case it is 3, because there are 3 elements between 5th and 2nd element of the array.
    * Note: Both the operands should point to the same datatype.
    * 
    * Equality operators also work here, but know that when we normally use pointer with equality 
    * operators, the operator will operate on the addresses and not the data their are pointing to.
    * You'll see that in the examples.
    */

    int table25[] {5, 10, 15, 20, 5};
    int *table25_ptr {table25};

    cout << "First element of the array: " << *table25_ptr << endl;
    cout << "After incrementation(Should be 2nd element of the array): " << *(++table25_ptr) << endl;
    cout << "After decrementation(Should be 1st element of the array again): " << *(--table25_ptr) << endl;

    cout << "\n===========================================================\n" << endl;

    table25_ptr += 2;
    cout << "After += 2(Should be 3rd element of the array): " << *table25_ptr << endl;

    cout << "\n===========================================================\n" << endl;

    int *table25_ptr2 {table25 + 4};
    cout << "Table5 5th element - 3rd element with pointers: " << table25_ptr2 - table25_ptr << endl;

    cout << "\n==========================================================\n" << endl;

    cout << boolalpha;

    table25_ptr = table25; // Resetting to index 0;
    cout << "Pointer of index 0 equal to pointer of index 4: " << (table25_ptr == table25_ptr2) << endl;
    cout << "Value of index 0 equal to value of index 4: " << (*table25_ptr == *table25_ptr2) << endl; 

    /*
    * As I said, when we operate on operators, the compiler looks at addresses and not it's value.
    *
    * --Const Pointers--
    * 
    * There are three types-
    * 
    * 1. Pointers to Const- These are normal pointers that point to const data.
    * Ex- int_ptr = new const int;
    * 
    * 2. Const Pointers- These are Constant pointers whose address can't be changed.
    * Ex- int *const int_ptr {var};
    * Yes, the '*' comes before const this time.
    * 
    * 3. Const Pointers to Const- This is the mix of previous two. This is a constant pointer that 
    * points to constant data.
    * Ex- const int var {9}; int *const var_ptr {var};
    * 
    * If you get confused with those consts, I have a trick up my sleeve. Divide the statement with
    * '8' as the breakpoint. If the pointer has the const, it is const. If the var has the const, it
    * is the const. If both have consts, then both are const. Just remember to put the const keyword
    * after the asterisk when creating a const pointer. Also, you might see codes with interchanged
    * locations of const keyword and the datatype, that is also Ok. 
    * 
    * 
    * --Passing Pointers in Functions--
    * 
    * One way is to give a reference as argument and take it as a pointer. There won't be any
    * syntactical change in parameter. It's as you declare a pointer. 
    * Another way is to give a pointer directly as argument.
    * 
    * --Returning a Pointer from a Function--
    * 
    * This is also easy-
    * 
    * datatype *ptr (parameters);
    * 
    * Done. 
    * Note: Never return a pointer to a local var. Meaning, don't return a pointer that pointer that 
    * points to a var that you created inside the function. Because that var is temperory, it gets 
    * deleted right after the function finishes.
    * 
    * 
    * --Pointer Pitfalls--
    * 
    * 1. Uninitialized Pointer- I have told you this before, you shouldn't have uninit pointers, they 
    * point towards garbage that only messes shit up, nothing else, so you should always use nullptr if 
    * you don't know where to make it point.
    * 
    * 2. Dangling Pointer- This happens when there are two pointers pointing at the same data, and one 
    * of them deletes the data. Now the other pointer is pointing at data that doesn't exist anymore.
    * 
    * 3. Not checking if new(keyword) failed- If new fails, an exception is thrown. Can use exception
    * handing(You'll learn it later on) to catch the exception. And since you don't know it yet, you 
    * might use a data that is not created(since new failed) and that will cause program crash.
    * 
    * 4. Memory Leak- I have also told you this before, you must delete the data you created with new, 
    * because if you change the location of the pointer that previous data will be left alone in 
    * darkness and that will make me sad.
    * 
    * 
    * --References--
    * 
    * All this time we have been using the reference operator to use the address of the var. Now we'll 
    * learn to really use references. They are called alias for vars.
    * 
    * datatype &ref_name {var};
    * 
    * Now, that var's address is in the reference named ref_name. There are some key things to know 
    * about refereces.
    * 
    * 1. It must be intialized to a var when declared.
    * 2. Can't be null. Should contain something.
    * 3. Value, which is an address, can't be changed. Meaning, it will always contain the var's address 
    * it was initialized with.
    * 4. You can call it a pointer which is automatically dereferenced.
    * 
    * --L-values and R-values--
    * 
    * L-values have names and are addressable. Whereas, R-values are non-addressable and non-assignable.
    * Kind of anything which is not L-value. A literal or a temperory thing which is inteded to be 
    * non-modifiable.
    * 
    * Ex- int x = 34; Here x is a L-value and 34 is a R-value(A literal).
    * int y = max(x, z); Here y is an L-value and max(x,z) is a R-value(A temperory num).
    * 
    * Next- A Problem and then Procedural Programming Summary, OOP, Classes, Objects, Default 
    * Attributes, Accessing Class Data, Access Modifiers, Methods, Setters and Getters.
    */

    return 0;

}