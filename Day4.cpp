// Day4 Of Learning C++

#include<iostream>
using namespace std;

int main(){

    // Break and Continue
    /* Are used to control the flow of loop.
    Think of a situation where a girl is allowed to go out only on even number days,
    and spends 300 every time she goes out, she gets 3000 as her monthly allowance. So, 
    till which date will she be able to go out if its the month of feb. */

    int monthly;
    monthly = 3000;
    for(int day = 1; day <= 28; day++){
        if (day % 2 != 0){   // != means not equal and == means equal, = is assignment operator.
            continue;
        }
        if (monthly <= 300){
            break;
        }
        cout << day << endl;
        monthly = monthly - 300;
    }

    /* With Continue the code is skipped to the next iteration of the loop, meaning the next body 
    code won't be run and will be skipped. But, the Break terminates the loop. */

    // Now, let's see more examples, start with taking input from user and telling if it's prime or not.

    int pr;
    cin >> pr;
    int i;
    for(i = 2; i < pr; i++){
        if(pr % i == 0){
            cout<<"Not A Prime!"<<endl;
            break;
        }
    }
    if(pr == i){
        cout<<"Yes, A Prime"<<endl;
    }

    // Now, try getting a range from the user and telling which which number among the range is a prime.

    int num1;
    cout<<"Give the first num."<<endl;
    cin>>num1;

    int num2;
    cout<<"Give the second num."<<endl;
    cin>>num2;
    
    int k;
    
    for(num1; num1< num2+ 1; num1++){  
        for(k = 2; k < num1; k++){
            if(num1%k == 0){
                cout<<num1<<" isn't a prime."<<endl;
                break;
            }
        }if(num1 == k){
            cout<<num1<<" is a prime."<<endl;
        }
    }
    
   return 0;
}
