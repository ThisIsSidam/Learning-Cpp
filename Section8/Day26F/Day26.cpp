// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 29/06/2022
//
// Day26 Of Learning C++
// --------------------------------------

/*
* --Overloading Stream Operators--
* We use two Stream Operators, Input Stream Insertion (>>) and Output Stream Extraction (<<). First thing to know
* is that they are used only as Global Functions and not as Member Methods because in it the left operand must be 
* a user defined class and while using cin and cout, we right them on the left and the other operand on right. This
* way it will look like this - name >> cin, which is literally not the way we use it. So, we'll just be doing this 
* as Global Functions.
* Also, since we are doing input and output, there return types and parameter type won't be some normal type. It
* will be std::ostream for output and std::istream for input. So, let's do this now.
*/

#include <iostream>
#include "Mystring3.h"

std::istream& operator>> (std::istream &is, Mystring3 &rhs);
std::ostream& operator<< (std::ostream &os,const Mystring3 &rhs);
int main()
{
    Mystring3 greeting {"Konichiwa, "};
    Mystring3 db_characters {"Goku, Shenron, Beerus, Vegeta, Whis, Gohan, and Goten."};

    std::cout << greeting << db_characters << '\n'; // No need to have a getter.
    
    return 0;
}

std::istream& operator>> (std::istream &is, Mystring3 &rhs) {
    
    char *buff = new char[1000];
    is >> buff;
    rhs = Mystring3{buff};
    delete buff;
    return is;
}

std::ostream& operator<< (std::ostream &os, const Mystring3 &rhs) {
    os << rhs.text;
    // Can also use rhs.getter();
    return os;
}