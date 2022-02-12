// Day2 Of Learning C++

#include<iostream>
using namespace std;


int main(){

    // This is how you create and give value to a var.
    int a; // This is Declaration, first comes the data type and then the name.
    a = 34; // This is Initialisation, we assign value to that var.
    

    // Now we'll learn about Input
    int amount1;
    cin >> amount1; // For output we used cout, for input we use cin.
    
    // Let's try getting another var and adding it to the previous one.
    int amount2;
    cin >> amount2;

    int sum = amount1 + amount2;
    cout << sum << endl; // endl means end line, so that the next thing will appear on next line.


    // If-Else
    // Are used to create a fork in the road.
    // If will run if the condition is true and else will run if the condition is false.
    int money;
    cin >> money;
    if(money > 1000){
        cout << "I have lots of money." << endl;
    } 
    else{
        cout << "I don\'t have much." << endl;
    }
        
    // Note- Use of single and double quotes is different.
    // Now, let's try if-else inside of if-else.

    int x, y, z;
    cin >> x, y, z;

    if(x > y){
        if (x > z){
            cout << "X is the biggest number.\n";
        }
        else{
            cout << "Z is the biggest number.\n";
        }
    }
    else{
        if (y > z){
            cout << "Y is the biggest number.\n";
        }
        else{
            cout << "Z is the biggest number.\n";
        }
    }

    return 0;
}
