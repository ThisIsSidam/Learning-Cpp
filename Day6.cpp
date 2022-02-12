// Day6 Of Learning C++

#include<iostream>
using namespace std;

int main(){

    //Operators
    /* This one is going to be mostly text.
    So, operators are symbols that tell the computer to perform some specific operations.
    There are various types of them.
    
    1. Arithmetic Operators
    (i). Binary- '+', '-', '*', '/'- Used on two operands and you already know how to use
    them.
    (ii). Unary- '++', '--'- Called incrementer and decrementer and are used on a single 
    operand, and if used they increase and decrease the value of operand by one. As needed
    they are used before and after the operand. Before means that, the value will be changed
    right there and if used after the operand, the value will be changed the next time that
    operand is used. Let's see examples. */

    int a, b, c, d;
    a = 1;
    b = ++a; // Here the value is changed right there to 2.
    c = a++; // Here the value is two from the previous action and will changed when used next.
    d = a; // Now, the incrementer we used on c will take action.
    cout<<b<<c<<d<<endl;  // The same happens with decrementer.

    /* 
    2. Relational Operators
    These guys define a relation between two operands, and return a boolean value. The operators 
    are, == which is for equality, != for unquality, <, >, <= and >=.

    3. Logical Operators
    Are used to connect multi-conditional expressions together or to reverse logical value.
    (i) && - AND Operator - Gives us true if both operands are true.
    (ii) || - OR Operator - Gives us true if any operand is true.
    (iii) ! - NOT Operator - Gives true for false and false for true.
     */

    cout<<!(0); // 0 means false and 1 means true.
    cout<<!(3); // Other +ve ints are also considered true.

    /*
    4. Bitwise Operator
    Operate on bits and perform bit-by-bit operations.
    (i) & - Single & not double as the Logical op. - But the explanation is same. 
    (ii) | - Again single not double - Explanation is also same as logical |. 
    (iii) ^ - XOR op. - Returns False(0) if both are same and True(1) if both are different.
    (iv) ~ - One's Compliment Op. - Like the not op., converts 1 to 0 and 0 ot 1.
    (v) << - Left Shift Op. - Left operand number is converted in binary, 4 << 1, the left
    operand 4 will be converted into binary 0100 and the 1 in 0100 will be shifted to right
    and will crete 1000 because with right operand 1 it will be shifted left once. 1000 means
    8, so a formula comes, a << n = a2^n.
    (vi) >> - Right Shift Op. - Same thing, just the shifting goes to right instead of left, and
    the formular becomes, a >> n = a/2^n.

    5. Assignment Operator
    (i) = - Assignment op. assigns values.
    (ii) += - You will write, a = 1 + b, it is to help that, you can write, a += b, will means the same.
    (iii) -= - Same thing, change of symbol. 
    (iv) *= -  Same thing, change of symbol.
    (V) /= - Same thing, change of symbol.

    6. Miscellaneous Operator
    (i) sizeof() - Returns the memory size of the operand.
    (ii) condition?x:y - Called the Ternary Op., returns value of x if the condition is true or else vaue of y.
    Yup, it's similar to if-else and hence usefull, ex- c = a>b ? a-b : b-0.
    (iii) cast() - converts one data types to another, the word cast is replaces with the data type you want the
    operand to convert in, ex- int(1.4).
    (iv) comma(,) - if a = (2,3,4), the value of a will be the last one, which is 4 here.
    (v) &() - Called the Reference Op. returns the memory location of the operand.
    (vi) * - Called the Pointer Op. returns pointer to a var. This one and some above this need explanation of 
    their own, so just know that they exist.

    After this a question may arise that what if lots of operators are used at once, they refer to the 
    Operator Precedence Table, it is like the BODMAS of operators. 
     */

    return 0;
}