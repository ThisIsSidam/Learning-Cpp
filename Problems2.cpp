// Problems2 Of Learning C++
/* 
I have commented all problems other than 1, so when you're done with 1, comment it and then uncomment 2.
Coz when all are uncommented, you can't focus on one, specially while giving input, you can't know which 
is for which. 
*/

#include<iostream>
using namespace std;

int main(){

    // We will be making patterns again this time.
    // Create an inverted half pyramid but will numbers that gets added by 1 with each
    // column but resets every row.

    int num, counter;
    cin>>num;
    counter = 0;

    for(int a= 1; a<=num; a++){
        for(int b=a; b>0; b--){
            counter += 1;
            cout<<counter<<" ";
        }
        counter = 0;
        cout<<endl;
    }

    // Now a chessboard pattern with 1 and 0, in the half pyramid style.
    // Using the previous input, so, don't comment it's declaration.

    // for(int a= 1; a<=num; a++){
    //     for(int b=1; b<=a; b++){
    //         if((a+b)%2==0){
    //             cout<<"1 ";
    //         }
    //         else{
    //             cout<<"0 ";
    //         }
            
    //     }
    //     cout<<endl;
    // }

    // Now create a Rhombus with *.
    // Still using the previous input.

    // for(int a= 1; a<=num;a++){
    //     for(int b= 1; b<=num-a; b++){
    //         cout<<"  ";
    //     }
    //     for(int b=1; b<=num; b++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // Now, how about a triangle(Not right angled.) of numbers that reset on each row.
    // Yup, again using the previous input.

    // counter = 0;  // Already declared above.

    // for(int a= 1; a<=num; a++){
    //     for(int b= 1; b<=num-a; b++){
    //         cout<<"  ";
    //     }
    //     for(int b= 1; b<=a; b++){
    //         counter += 1;
    //         cout<<counter<<"   ";
    //     }
    //     counter =0;
    //     cout<<endl;
    // }

    // Now, create a palindromic pattern, search the web for explanations.
    // counter = 0;
    // for(int a= 1; a<=num; a++){
    //     for(int b= 1; b<=num-a; b++){
    //         cout<<"   ";
    //     }
    //     counter = a;
    //     for(int b= 1; b<=a; b++){
    //         cout<<counter<<"  ";
    //         counter-=1;
    //     }
    //     counter = 2;
    //     for(int b= 1; b< a; b++){
    //         cout<<counter<<"  ";
    //         counter +=1;

    //     }
    //     cout<<endl;
    // }

    // Now, it's time to create a diamond shape with *s.
    // Did you say to use the previous input? Ok.

    // for(int a= 1; a<=num; a++){
    //     for(int b= 2*num-2*a; b>0; b--){
    //         cout<<" ";
    //     }
    //     for(int b= 1; b<=2*a-1; b++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    // for(int a=num; a>0; a--){
    //     for(int b=2*num-2*a; b>0; b--){
    //         cout<<" ";
    //     }
    //     for(int b=2*a-1; b>0; b--){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // Time for a last Zigzag pattern.
    // Not gonna say it this time.

    // for(int i = 1; i<=3; i++){
    //     for(int j=1; j<=num; j++){
    //         if(((i+j)%4==0) || (i==2 && (i+j)%2==0)){
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