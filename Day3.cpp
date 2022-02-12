// Day3 Of Learning C++

#include<iostream>
using namespace std;

int main(){

    // Loops
    // For Loop-
    /* for(initialisation; condition; update){
        body
    }  */

    for( int i = 1; i < 11; i ++){
        cout << i << endl;
    }

    /* The code above creates a var i and prints it and adds 1 to it then again prints it,
    this goes on until it breaks the condition which is i to be >= 11. */

    // While Loop-
    /* while(condition){
        body
    }  */

    int j;
    j = 1;
    while(j < 11){
        cout << j << endl;
        j ++;
    }

    /* This time we did the same thing but we had to initialize var and assign value to it separately,
    also to update its value. */

    // Do While Loop-
    /* do{
        body
    } while(condition);  */

    int z;
    cin >> z;
    do{
        cout << z << endl;
        cin >> z;
    } while( z%2 == 0);  // % is the modulus operator, it gives off the reminder.

    /* The body is executed once first then the condition is checked and it is decided that the loop will 
    go on or not. Here, the loop should break if the number is odd, but the body will aleast be executed 
    once no matter the condition. Let's try the same thing in while.  */

    int s;
    cin >> s;
    while(s % 2 == 0){
        cout << s << endl;
        cin >> s;
    }

    return 0;
}