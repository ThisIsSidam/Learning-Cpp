// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 16/03/2022
//
// Day3 Of Learning C++
// --------------------------------------

#include <iostream>
using namespace std;


// int num6 {99};

int main()
{

    // Variables(Var)
    
    /*
    * Variable is something that stores a value, and whose value can be changed.
    * First the datatype of the var and then the name of the var, you're going to 
    * learn datatypes after this, for now just know that int means integer datatype.
    */

    // int num; // Declaration
    // num = 5; // Initialisation

    // int num2 = 55; // Declaratin and Initialisation all together.

    /*
    * Rules of naming-
    * a. Can only contain letters, numbers or underscores.
    * b. Cannot begin with num.
    * c. Shouldn't be already declared.(Are case sensitive).
    * d. Can't be a keyword.
    * 
    * One thing to know, keywords like cout, cin and else come with iostream file, if you're 
    * not using it or are using something that doesn't contain those keywords then you can use
    * those as vars.
    * 
    * One helpful thing, you should declare a var close to where you're gonna use it, not like 
    * declare all the vars that you're gonna use in the start.
    * 
    * It is not best to name variables as short forms, like naming room length as rl. Name it,
    * RoomLength or room_length, those are better understandable and self explainatory.
    * 
    * There are naming conventions that you should choose and consistently use.
    * Two famous ones are-
    * a. CamelCase, Naming with capitalizing the first letter of the word.
    * b. Underscore, All lower case with underscores used as spaces.
    * 
    * There are multiple ways of creating a var-
    */

    // int num3 = 33; // Normal method.

    // int num4 (44); // Constructer method, we'll know more about it later on.

    // int num5 {466}; // C++11 list method (preferred).

    /*
    * Scopes of Variable
    * There are two main scopes of var, Local and Global.
    * 
    * Local- Created inside a fn(function), and can only be accessed by that function.
    * 
    * Global- Created outside any fn, and can be used by any fn in the file, you won't have 
    * to use these for sometime, until you learn creating new fns.
    * 
    * One thing to know is that, if there are two vars of the same name(This is possible if 
    * created in different scopes), one local inside main, and one global var, then the 
    * system will choose the local var first, think it like if you have cold drinks in your 
    * fridge then why will you go to the market. Let's try this one, go uncomment the  
    * var creation at the top.
    */

    // int num6 {67};
    // cout << "I got " << num6 << " marks in the test." << endl;

    // Well, this is the end, we'll see datatypes after this.

    return 0;

}