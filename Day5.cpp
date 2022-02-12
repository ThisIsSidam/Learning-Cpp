// Day5 Of Learing C++

#include<iostream>
using namespace std;

int main(){
     // Switch
     /* Unlike Python, ther isn't elif in c++, so you have to write else if. Let's see 
     it with a code that has 4 choices.*/

    char word;
    cout<<"Water in different languages!\nChoose a/b/c/d"<<endl;
    cin>>word;

    if(word == 'a'){
        cout<<"Pani In Hindi.\n";
    }
    else if(word == 'b'){
        cout<<"Water In Enlish.\n";
    }
    else if(word == 'c'){
        cout<<"Agua In Spanish.\n";
    }
    else if(word == 'd'){
        cout<<"Mizo In Japanese.\n";
    }
    else{
        cout<<"Maybe you typed something other than the options.\n";
    }

    // Now, let's try something similar but this time we'll use Switch.

    char jap;
    cout<<"You will get to learn Japanese.\nChoose a/b/c";
    cin>>jap;

    switch(jap){
        case 'a':
            cout<<"Arigato is Thank You.\n";
            break;
        
        case 'b':
            cout<<"Daijobu is Are You Ok.\n";
            break;

        case 'c':
            cout<<"Neesan is Big Brother.\n";
            break;

        default:
            cout<<"Options are just a,b and c.\n";
        
    }
    /* You give a variable as argument in switch and it is checked if the argument you give after case 
    is a value of the var you gave, if yes the code will run, if not the code under default will run.
    Also, it is important to use break in every case so, that only one runs, if you don't use break the 
    others will also be executed. */

    return 0;
}