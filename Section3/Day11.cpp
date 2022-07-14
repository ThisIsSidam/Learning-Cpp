// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 27/03/2022
//
// Day11 Of Learning C++
// --------------------------------------

#include <iostream>
using namespace std;

int main()
{

    /* 
    * We can control the flow of the program with three methods-
    * a) Sequence- We type what we wanna do and it happens sequelly. That's what we've been doing until now.
    * b) Selection- We make the program make decisions, either this to run or that. That's what we'll study
    * now.
    * c) Iteration- We type code once, make it run for a number of times as we want. This is something we'll
    * study just a little bit later.
    * 
    * --If-Else--
    * 
    * It is like, If this is true, do this, or do that.
    * 
    * syntax-
    * if (condition)
    * {
    *   expr1;
    * }
    * 
    * The expr1 statement will only run when the given condition is true, or will be skipped.
    * Tip: If you know you're just gonna have one statement, then you don't have to add the curly braces.
    * They are used for a block of statements and are called block statment.
    * 
    * One more thing, Indentation is used to show which lines of code are under which lines. This is not for 
    * the compiler, it doesn't need that, but for us and other programmers, because without it the code
    * will become messy and ununderstandable.
    * 
    * If you want to add something for when the condition is false, then you can use Else
    * 
    * syntax-
    * else
    * {
    *   expr2;
    * }
    * 
    * And if you want to add more conditions, then you can do this.
    * 
    * if (condition1)
    * {
    *   expr1;
    * }
    * else if (condition2)
    * {
    *   expr2;
    * }
    * else if (condition3)
    * {
    *   expr3;
    * }
    * else
    * {
    *   expr4;
    * }
    * 
    * This is something called an if-else ladder. And the compiler checks it one by one, if the condition
    * of any one is true, the ladder then breaks. 'else' never has a condition, it is for 
    * when none of the conditions are true.
    * You can also have if-else statements inside if-else statements, these are called nested statements.
    * And indentation plays a big role in it, without them you will get confused on whose statement is what
    * and more. 
    * And not knowing which else is of which if is called DANGLING ELSE PROBLEM. The solution of it is 
    * that the else is of the nearest if.
    * Let's see an example of this.
    */

    // int marks {};
    // cout << "How many % marks did you get in the last year exams kid?" << endl;
    // cin >> marks;

    // if (marks > 90)
    //     cout << "Damn kid! You are super smart." << endl;
    // else if (marks > 80)
    //     cout << "Bravo! Brilliant!" << endl;
    // else if (marks > 70)
    //     cout << "Not Bad! Not Bad!" << endl;
    // else if (marks > 50)
    //     cout << "Oh! You should study kid." << endl; 
    // else if (marks < 50)
    // {
    //     char confirm {};
    //     cout << "You really scored this bad kid?(Yes/No)" << endl;
    //     cin >> confirm;

    //     if (confirm == 'Y' || confirm == 'y')
    //         cout << "Kid, if you want to have a good and happy future, you should study." << endl;
    //     else if (confirm == 'N' || confirm == 'n')
    //         cout << "Oh, I knew that!" << endl;
    //     else
    //         cout << "I guess you types something other than Y, y, N or n." << endl;
    // }


    /*
    * One more thing you should know about is that, vars created inside the curly braces of the statements 
    * can only be used inside those curly braces, because that's their scope.
    * 
    * --Switch-Case--
    * 
    * Switch case method uses an integral value, and checks it in each case.
    * 
    * syntax-
    * 
    * switch (condition)
    * {
    *   case exp1:
    *       statement;
    *       break;
    *   case exp2;
    *       statement;
    *       break;
    *   default:
    *       statement;
    * }
    * 
    * exp1 and exp2 are checks for the integral condition given in switch, if any is true, the statement 
    * under is executed and cases should always have breaks, or you will encounter something called 
    * FALL THROUGH, it happens when there isn't any break statement to break the selection, in it, every 
    * case including that one and following will be executed until it meets a break statement or the end.
    * 
    * Default is for when none of the cases are executed, it doesn't need a break statement.
    * You'll get to know more of break another day.
    * 
    * Let's see an example.
    */

    // int profession {};
    // cout << "Kid, what do you want to become when you grow up? Type the number." << endl;
    // cout << "1. Engineer\n2. Doctor\n3. Lawyer\n4. Something else" << endl;
    // cin >> profession;

    // switch (profession)
    // {
    //     case 1 :
    //         cout << "You have got to study hard for this." << endl;
    //         break;
    //     case 2 :
    //         cout << "It is to help people or for the money." << endl;
    //         break;
    //     case 3:
    //         cout << "You better help me get out of jail if I do something inappropriate." << endl;
    //         break;
    //     case 4:
    //         cout << "Every profession is good as gold." << endl;
    //         break;
    //     default:
    //         cout << "I guess you misstyped." << endl;
    // }

    /*
    * --Conditional Operator--
    *
    * (?:) It is a ternary oper. and it's use is very very helpful.
    * It's like a oneliner if-else.
    * 
    * syntax-
    * (condition) ? expr1 : expr2;
    * 
    * If condition is true, expr1 is used and if it's false, expr2 is used.
    * Isn't it neat.
    * 
    * Let's use it a bit.
    */

    // int x {}, y {};
    // cout << "Give two different integers with a space: ";
    // cin >> x >> y;

    // cout << "Larger: " << ((x > y) ? x : y) << endl;
    // cout << "Smaller: " << ((x < y) ? x : y) << endl;

    // Next- For, While and Do-While Loops, along with Break, Continue and Infinite Loops.
    
    return 0;

}