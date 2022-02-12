// Day8 Of Learning C++

#include<iostream>
using namespace std;

// Functions
/*
First, why are we not inside int main, well, functions are created outside int main so.

Functions are a piece of code that performs specific tasks.
Syntax(The way a certain kind of code/keyword is written or used.)-
*/

int add(int num1, int num2){
    int sum = num1 + num2;
    return sum;
}

/* 
We just created a funtion, first comes the return types, the data type of the value you'll return,
if you don't want to return anything, type void, after that comes the name. Then parameters, these are
data that you'll take while running the funcion, so, a substitute for it with its data type. Then, 
comes the body and end with returning the thing you want the function to return. 
*/

// Now, let's create one more simple functions and then we'll learn the Concept of Call Stack.

int average(int a, int b){
    int added = add(a, b);
    int average = added/2;
    return average;
}   

int main(){
    cout<<average(3, 7);

    /*
    Now, let's see what happened, Concept of Call Stack is about which function is executed first and
    which is executed after that. Think of stacked books, if you want to add a book in the stack your only
    choice if you don't want other books to be distured is to put it on top, and if you want to take a book 
    out of the stack is to remove upper ones first and then take out the one you want, if you take book out 
    from the middle, the books above that one will fall over. Just like that, when a function is executed, it 
    is like putting a book on stack and it's called that the function is Pushed onto the Stack and when a 
    function returns something, it is like removing a book from the stack and is called that the function 
    popped out of the stack. 
    
    Now, let's see the Concept of Call Stack in the example we created. Currently the stack is empty, the main 
    function is then pushed onto the stack and it runs line 35, then the average fn is pushed onto the stack.
    The average fn uses the add fn so, add fn is pushed onto the stack after. Now, the add fn returns the sum and
    pops out of the stack and average fn returns average and pops out of the stack and in the end main function
    returns 0 and pops out of the stack. 
    */

    return 0;
}