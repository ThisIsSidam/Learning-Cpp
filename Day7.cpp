// Day7 Of Learning C++

#include<iostream>
#include<cmath> 
#include<math.h>
using namespace std;

int main(){
     
     // Binary Numbers

     /* In decimal number system, numbers come as powers of 10, take 1233 as an example number, 
    we can write it as-  1 * 10^3 + 2 * 10^ 2 + 3 * 10^1 + 3 * 10^0.

    Just like that, in binary, numbers come as powers of 2. with 45 as example, we can write-
    45= 1*2^5+ 0*2^4+ 1*2^3+ 1*2^2+ 0*2^1+ 1*2^0
    45= 1*32+ 0*16+  1*8+ 1*4+ 0*2+ 1

    We just have to select which which powers of 2 to select and add and we'll get any number we want.
    Now, selecting the 1s and 0s from line 15 we'll get 101101 which is 454 in binary, we just converted
    a number into binary.

    Now, let's see of another way.

    N       Quotient(n/2)       Remainder(n%2)
    45          22                  1
    22          11                  0
    11          5                   1
    5           2                   1
    2           1                   0
    1           0                   1

    I think the chart won't need an explanation. Here, if you see the remainder line from bottom to top, you'll 
    get the binary of 45. It is also true that the number is same from top to bottom but it's a palindrome, we 
    can't do anything about and it won't be like this always, so, read the remainder list from bottom to top.

    Now, let's convert binary to number.
                        101101
    1*10^5 + 0*10^4 + 1*10^3 + 1*10^2 + 0*10^1 + 1*10^0
    Just multiply the 0s and 1s with powers of 10 according to their position and you'll get the number. Also, 
    mulplying 0s is not necessary since everyone knows that they are gonna give a 0.
     */

    // Now, write a code that tells if a number is prime or not. 

    int n;
    cin>>n;
    bool flag= 0;

    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            cout<<"No, It's Not A Prime!"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Yes, It's A Prime!"<<endl;
    }


    // Now, write a code to reverse a number.
    
    int s, last; 
    cin>>s;
    int reverse =0;

    while(s>0){
        last= s%10;
        reverse= reverse*10 +last;
        s= s/10; 
    }
    cout<<reverse;

    // Let's take a number 153, if we take cube of each number, which is of 1, 5 and 3 and add
    // them up, we'll get the original num. Such numbers are called armstrong numbes.
    // So, write a code to check if a number is armstrong or not.

    int a, arms, orig; 
    cin>>a;
    orig=a;

    while(a>0){
        last= a%10;
        arms= arms + pow(last,3);
        a=a/10;
    }
    if(orig==arms){
        cout<<"It's an Armstrong Number."<<endl;
    
    }
    else{
        cout<<"It's Not an Armstrong Number."<<endl;
    }
    

    return 0;
}