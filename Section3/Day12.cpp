// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 28/03/2022
//
// Day12 Of Learning C++
// --------------------------------------

#include <iostream>
using namespace std;

int main()
{

    /*
    * Time for the third basic thing used for controlling the flow of the programs.
    *  
    * Iteration
    * 
    * To iterate a piece of code, there are mainly three ways-
    * a) For Loops
    * b) While Loops 
    * c) Do-While Loops
    * 
    * --For Loops--
    * 
    * syntax-
    * 
    * for (intialisation; condition; increment/decrement)
    * {
    *     statement;
    * }
    * 
    * If you know it beforehand that, you're gonna have a single statement, you can just remove the block
    * statement and have just a single line, but it is preferred to have the block since, who knows when 
    * you might want to add something.
    * 
    * You have to put three different expressins divided by the ';' in the for loop. You first initialize 
    * and int, you can do it inside or outside the loop. It's preffered to do it inside so it can't be 
    * affected by outside forcessince the it will have a different scope. After that you have to put a 
    * condition with which the loop will break when it is false. Then comes the increment/decrement stage
    * where you have to increment or decrement the value of the var you created so that it changes and 
    * eventually the condition can turn false and break the loop.
    * 
    * Let's see an example.
    */

    // for (int i {1}; i<6; i++)
    // {
    //     cout << i << endl;
    // }

    /*
    * So, we printed out 1 to 5, we first initialized a var i, it is the most common var to be initialized 
    * inside for loops. Then we put a condition to break the loop when i becomes >= six and then we increment 
    * it. 
    * The var is checked, condition is checked, statements are executed and then var is incremented and then 
    * condition is checked again. And this goes on and on and on and on and on and on and on, till the
    * condition becomes false.
    * 
    * Note: preincrementer and postincrementer mean the same when they are used alone in an expression, and 
    * that's exactly what's happening here.
    * 
    * And you can also you the comma ',' operator to have multiple vars in the loop.
    */

    // for (int i {1}, j{10}; i<10; i++, j--)
    // {
    //     cout << i << "*" << j << "=" << i*j << endl;
    // }

    /*
    * See, wasn't that great.
    * 
    * --Ranged Based For Loops--
    * 
    * This feature was introduced in C++11, with It we can easily iterate over a range like, an array or 
    * a vector.
    * 
    * syntax-
    * for (datatype var: range)
    * {
    *   statement;
    * }
    *
    * Let's see an example.
    */

    // int five_numbers[] {1, 2, 3, 4, 5};

    // for (int numbers: five_numbers)
    // {
    //     cout << numbers << endl;
    // }

    /*
    * Wasn't it as easy as pooping! ;)
    * 
    * Tip: In Ranged based for loops, you can use 'auto' as the datatype, it will itself determine which
    * dataype the range belongs to. This doesn't look that helpful here, but when you will be writing
    * complex codes it will come in handy.
    * 
    * --While Loop--
    * 
    * syntax-
    * while (condition)
    * {
    *   statement;
    * }
    * 
    * It means that for the time the given condition is true, execute the statement.
    * 
    * --Do-While Loop--
    * 
    * syntax-
    * do {
    *   statement;
    * } while (condition);
    * 
    * It means that first execute the statement once, then check the condition, If true, execute it again and
    * if false, break it.
    * 
    * Note: While loop is called Pretest loop because it first tests the condition and Do-While loop is 
    * called the posttest loop because it first executes the statements once and then checks the condition.
    */

    
    // char confirm {}; 

    // do {
    //     cout << "=======Rectangle Area Calculater=======" << endl;
    //     int length {}, width {};
    //     cout << "Type the length and width in Cm separated by a space: ";
    //     cin >> length >> width;

    //     cout << "\nArea = " << length * width << "cm^2" << endl;

    //     cout << "\nWanna Calculate another?(Y/n): "; 
    //     cin >> confirm;

    //     if (confirm != 'Y' && confirm != 'y')
    //     {
    //         cout << "Goodbye...";
    //     }
    // } while (confirm == 'Y' || confirm =='y');

    /*
    * If you are thinking why I didn't initializee confirm inside the block statement, then let me tell 
    * you that I had to use it in while, I can't use a var whose scope is local to that block only.
    * 
    * --Continue--
    * 
    * If you use this statement in a loop, No further statements in the body of the loop will be executed, 
    * control immediately goes to the beginning of the loop for next iteration. 
    *
    * --Break--
    * 
    * If you use this statement in a loop, no further statements in the body of the loop will be executed.
    * The loop will immediately be terminated, and the control immediately goes to the statements following 
    * the loop construct.
    * 
    * Let's see an example that has both of these.
    */

    // int temperature[] {1, 53, 3, 34, 4, 3, 6, -34, 33};

    // for (auto temp: temperature)
    // {
    //     if (temp < 30 && temp > 0)
    //         continue;
    //     else if (temp < 0)
    //         break;
            
    //     cout << temp << endl;
    }

    /* 
    * The loop continues to the next iteration when the temp is less than 30 but breaks when meeting a
    * negative temperature.
    * 
    * --Infinite Loops--
    * 
    * Loops whose conditional expression is always evaluate true, and are broken with break statements.
    * 
    * You may think why will anyone use it. Well, it is used for programs who sit back and wait for a certain 
    * action to happen. Like an Operating system, it is actually in an endless loop of being on, until that 
    * loop is broken with the shut down option. Also, your mouse, it is always waiting for the click response.
    * 
    * Syntax of Infinite loops-
    * 
    * for (;;)  and  while (True)
    * 
    * and you can put anything that won't change and will remain true.
    * 
    * Next- Character Funcitons, C Style Strings and Some of its Functions.
    */

    return 0;

}