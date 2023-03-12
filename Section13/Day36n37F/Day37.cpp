// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 03/03/2023
//
// Day37 Of Learning C++
// --------------------------------------



/* 
== Common Stream Manipulators ==

I have thought of a great way to show you the manipulators in action. It was 
normal when you needed to show example of only one but when you have to do it 
of different datatypes, it becomes cluttered, you want to only see manipulators
of int but you also see float and all. So, the main will run a switch case that
will start a function that shows examples of manipulators of a specific datatype 
that you want to see. The function will have the examples, so read a datatype
section, check out the function and run the file to see those manipulators. 

= Boolean Manipulators = 

This one will be short. And you've already seen this manipulators.

std::boolalpha -> Shows True/False instead of 1/0.
Default is std::noboolalpha which shows 1/0.

Method version: std::cout.setf(std::ios::boolalpha);

It may look complicated but it's not. We are accessing setf member function 
through the object cout, and are giving in an argument, which is a member function
inside th ios class. 

We can reset this flag to default by using this:

std::cout << std::resetiosflags(std::ios::boolalpha);

= Int Manipulators = 

All number systems have a base. Binary has base 2, whereas the one we normally use
has base 10, and is called DEC. There are more, for example, octal with base 8 and
hexadecimal with base 16 that even included letteres.

Manipulators:
- std::dec, std::oct, std::hex change the base of the number system being used. The 
default is dec.

- std::showbase shows the base of the number when the number is printed out. Normally
it can be impossible to identify is some cases. So, in hex "0x" is added as prefix to
the number whereas "0" is added as prefix to oct. The default for this is 
std::noshowbase that hides those prefixes.

- std::uppercase is something that only hex numbers use. It capitalizes the letters 
in the number and since only hexadecimals have letters, only they are capitalized.
The default is std::nouppercase that turns the alphabets to lowercase.

- std::showpos is for showing "+" sign in front of positive integers. The default is
std::noshowpos that hides that "+" sign. Note that this is only for dec.

One thing to note is that they affect all further outputs on the stream.

These are to reset them:
std::resetiosflags(std::ios::basefield)
std::resetiosflags(std::ios::uppercase)
std::resetiosflags(std::ios::showpos)
std::resetiosflags(std::ios::showbase)

A tip is not to memorize these as there are alot of them, you could just find them on 
C++ reference documentation.

= Floating Point Dataype Manipulators = 

Manipulators:

- std::setprecision(int) This is the number of digits displayes when printing a floating
point datatype. The default is 6. So, 1234.5678 will be displayed as 1234.57 (Rounding occurs). 
A total of six digits.

- std::fixed With this one, the count of setprecision starts after the decimal point. 
So now, 12.3456789 with setprecision 3 and active fixed manipulator will print 12.346. As 
default, fixed is not active.

- std::showpoint This is to show trailing zeroes. In default it's std::noshowpoint and no
trainling zeroes are printed. When active, 12.3 will show 12.3000 with setprecision 6.

- std::uppercase There are no hexadecimals here but scientific notation do exist.
So, in default std::nouppercase is active and the 'e' of 1.2e^5 and more will be capitalized.

- std::showpos. It's actions and default is same as it was for int.

They also affect all further outputs on stream.

= More Manipulators =

Now, we'll see some manipulators that can be used on all datatypes.


- std::setw(int) This is called Set Width. By default this is not set.
To understand this first think of an excel sheet like grid that exists 
on the console. One cell of the grid carries only one character. When 
we print something, with n number of character, n cells are given to it.
And it is printed. But we can given them more cells. Like even if we just 
have to print "a", we can set width t 10 and it will have that space as
it's. The next thing to be printed will be printed after those 10 cells of
this character, in the cells given to it.

- std::left and std::right When we give something more cells to print 
than necessary, there surely are gonna be cells that will go empty that
get filled with spaces. But, which ones will go empty? This is basically
alignation of the text. When given 10 spaces, we can print "a" on either 
side as we want. By default, when no width is given, std::left is active.
But when we give width, std::right gets active, that we can ofcourse 
change. 

- std::setfill(char) Well, we can also switch the empty cells that are getting
filled with white spaces with any other character.

Here fill is the only one manipulator that affects all other outputs on the console, 
while setw, right and left only affect the next one to the stream. But the condition
is that, that variable or object should have setw active on it. Or it won't have any
extra cells to fill character on.

*/

#include <iostream>
#include <iomanip>
#include <string>

void bool_manip();
void int_manip();
void float_manip();
void more_manip();

int main() {

    int num;
    std::cout << "1. Bool   2. Int  3. Float    4. More\nChoose your option: ";
    std::cin >> num; 

    switch (num) {

        case 1 : {
            bool_manip();
            break;
        }

        case 2 : {
            int_manip();
            break;
        }

        case 3 : {
            float_manip();
            break;
        }

        case 4 : {
            more_manip();
            break;
        }

        default : {
            std::cout << "Illegal Character Entered!" << '\n';
        }
    }

    return 0;
}

void bool_manip() {

    bool one {1}; 
    bool zero {0};

    std::cout << "Default is noboolalpha" << '\n';
    std::cout << "one: " << one << '\n';
    std::cout << "zero: " << zero << '\n';
    std::cout << "Switching to boolalpha" << '\n';
    std::cout << std::boolalpha;
    std::cout << "one: " << one << '\n';
    std::cout << "zero: " << zero << '\n';
    std::cout << "Reseting to default" << '\n';
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "one: " << one << '\n';
    std::cout << "zero: " << zero << '\n';
}

void int_manip() {
    int num {244};
    
    std::cout << "Default dec: " << num << '\n';
    std::cout << std::oct << "Ocatal: " << num << '\n';
    std::cout << std::hex << "Hexadecimal: " << num << '\n';
    std::cout << "Reseting to default" << '\n';
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << "Default dec: " << num << '\n';

    std::cout << std::showbase;
    std::cout << "Prefixes: " << '\n';
    std::cout << std::oct << "Oct: " << num << '\n'; 
    std::cout << std::hex << "Hex: " << num << '\n';
    std::cout << "Capitalizing: " << '\n';
    std::cout << std::uppercase;
    std::cout << "Hex: " << num << '\n';
    std::cout << "Showing positive sign for dec" << '\n';
    std::cout << std::showpos;
    std::cout << "Dec: " << std::dec << num << '\n';
}

void float_manip() {
    float num {1234.987654321};
    std::cout << "Def precision: " << num << '\n';
    std::cout << std::setprecision(9);
    std::cout << "Precision 9: " << num << '\n';
    std::cout << std::fixed;
    std::cout << "Fixed: " << num << '\n';

    float num2 {123.0000000000}; 
    std::cout << std::showpoint;
    std::cout << "Showpoint: " << num2 << '\n';

    std::cout << std::setprecision(3);
    std::cout << std::resetiosflags(std::ios::fixed);
    std::cout << "setprecision 3 for getting scientific notation with fixed off." << '\n';
    std::cout << num << '\n';
    std::cout << "Uppercase: " << '\n';
    std::cout << std::uppercase << num << '\n';
}

void more_manip() {
    char word {'a'};

    std::cout << std::setw(5) << word << '\n';
    std::cout << std::left << word << '\n';
    std::cout << std::setw(5) << std::setfill('=') << word << '\n';

    std::string ruler {"123456789012345678901234567890"}; // To show columns of magic grid
    int num {123};
    std::cout << ruler << '\n';
    std::cout << std::setw(5) << num << '\n';
    // Can see how cells are occupied by the first printing var. Even
    // thought they are the same var.
    std::cout << ruler << '\n';
    std::cout << std::setfill(' ');
    std::cout << std::setw(5) << std::left << num << num << '\n';

}