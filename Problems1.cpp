// Problemss1 Of Learning C++
/* 
I have commented all problems other than 1, so when you're done with 1, comment it and then uncomment 2.
Coz when all are uncommented, you can't focus on one, specially while giving input, you can't know which 
is for which. 
*/

#include<iostream>
using namespace std;

int main(){

    // Take rows and column numbers from the user and create a rectangle with it.
    int row, col;
    cin>> row>> col;
    
    for(int a = 1; a<=row; a++){
        for(int b = 1; b<=col; b++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // Now, let's make a rectangle again but hollow this time.
    // Let's keep the previous row and column inputs.

    // for(int j=1; j<=row; j++){
    //     for(int k=1; k<=col; k++){
    //         if(j == 1 || j == row || k == 1 || k == col){
    //                 cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // Now, create an inverted half pyramid.
    // int n;
    // cin>>n;

    // for(int x = n; x>0; x--){
    //     for(int y = 1; y<=x; y++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // Now, create a half pyramid.
    // Using the previous n input.

    // for(int u = 1; u<=n; u++){
    //     for(int v= n; v>0; v--){
    //         if(v<=u){
    //             cout<<"* ";
    //         } 
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // Now, create a hald pyramid but with numbers.
    // Again using the previously inputted n.

    // for(int e= 1; e<=n; e++){
    //     for(int f= e; f>0; f--){
    //         cout<<e<<" ";
    //     }
    //     cout<<endl;
    // }   

    // Now, create something which is called a Floyd'd Triangle, it is similar to the previuos
    // one just the numbers keeps getting increased by one each time.
    // int t, counter;
    // cin>>t;
    // counter = 0;

    // for(int a = 1; a<=t; a++){
    //     for(int b = a; b>0; b--){
    //         counter += 1;
    //         cout<<counter<<" ";
    //     }
    //     cout<<endl;
    // }

    // Now, comes the last question, which is to create a butterfly pattern.

    // int s;
    // cin>>s;

    // for(int a= 1; a<=s; a++){
    //     for(int b=1; b<=2*s; b++){
    //         if(b<=a || b >2*s-a){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }
    // for(int a= s; a>0; a--){
    //     for(int b=1; b<=2*s; b++){
    //         if(b<=a || b >2*s-a){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }




    return 0;
}