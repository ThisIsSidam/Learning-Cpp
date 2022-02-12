// Problems3 Of Learning C++
/* 
I have commented all problems other than 1, so when you're done with 1, comment it and then uncomment 2.
Coz when all are uncommented, you can't focus on one, specially while giving input, you can't know which 
is for which. 
*/

#include <iostream>
#include <cmath>
using namespace std;

// P1- Let's start with writing a code that requires two numbers and gives off all prime numbers between them.
bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// P2- Write a code that gives off input number of terms of the Fibonacci sequence.
// It is a sequence created from adding two previous numbers. First two are 0 and 1.

// void fibo(int n){
//     int f1= 0;
//     int f2= 1;
//     for(int i= 1; i <=n; i++){
//         cout<<f1<<endl;
//         int f3= f1+f2;
//         f1= f2;
//         f2= f3;
//     }
//     return;
// }

// P3- Now, write a code to give off the factorial of a number. Suppose the number is 4, then
// 4! = 4 * 3* 2* 1  ( ! denotes factorial)

// int fact(int n){
//     int fac=1;
//     for(int i= 2; i<=n; i++){
//         fac= fac*i;
//     }
//     return fac;
// }

// P4- Now, a code to calculate combination, it's formula is nCr = n!/(n-1)!r! .
// You can use the previosly made factorial fn for this, so, don't comment it after use.

int main()
{
    // P1 - This is because some part is inside main fn and some is outside.

    int n1, n2;
    cin >> n1 >> n2;
    for (int i = n1; i <= n2; i++)
    {
        if (isPrime(i))
        {
            cout << i << endl;
        }
    }

    // P2

    // int num;
    // cin>>num;
    // fibo(num);

    // P3

    // int s;
    // cin>>s;
    // cout<<fact(s)<<endl;

    // P4- Yup, No fn created for this.

    // int n, r;
    // cin>>n>>r;
    // int ncr = fact(n)/(fact(n-r)*fact(r));
    // cout<<ncr<<endl;

    // P5- This time, we have to print the pascal triangle, so what we have to do is, take a number
    // start row and column from 0 and every cell(intersection of row and column) will be the
    // nCr of the row and column.

    // int z;
    // cin>>z;

    // for(int i=0; i<z; i++){
    //     for(int j= 0; j<=i; j++){
    //         int Cr= fact(i)/(fact(i-j)*fact(j));
    //         cout<<Cr<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}