// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 11/06/2022
//
// Day25 Of Learning C++
// --------------------------------------

/*
* --Overloading Operators as Global Functions--
* In last file we overlaoded Assginment op. and some other ops. as Member Methods and this time 
* we'll overload those same ops. but as Global Funcitons. This functions are then used as friends 
* of the class.
* Note: You can overload operators as either Member methods or Global functions. Using both at the
* same time will cause errors since they both have same arguments and the compiler will get confused
* over which one to use.  
*/


#include <iostream>
#include <cstring>
#include "Mystring2.h"

Mystring2 operator- (const Mystring2 &);
Mystring2 operator+ (const Mystring2 &,const Mystring2 &);
bool operator== (const Mystring2 &,const Mystring2 &);

int main()
{
    Mystring2 hello_spanish {"Hola"};
    hello_spanish.display_details();

    Mystring2 hello_spanish2 {};
    hello_spanish2 = -hello_spanish;
    hello_spanish2.display_details();

    Mystring2 hello_japanese {"Konichiwa"};
    Mystring2 hello_vegeta {};
    hello_vegeta = hello_japanese + " Vegeta";
    hello_vegeta.display_details();

    std::cout << std::boolalpha;
    std::cout << (hello_japanese == hello_spanish) << '\n';
    
    return 0;
}

Mystring2 operator- (const Mystring2 &obj) {
    char *buff = new char [std::strlen(obj.text) + 1];
    std::strcpy(buff, obj.text);

    for (size_t i {0}; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring2 temp {buff};
    delete [] buff;
    return temp;
}

Mystring2 operator+ (const Mystring2 &lhs, const Mystring2 &rhs) {
    char *buff = new char [std::strlen(lhs.text) + std::strlen(rhs.text) +1];
    std::strcpy(buff, lhs.text);
    std::strcat(buff, rhs.text);
    Mystring2 temp {buff};
    delete [] buff;
    return temp;
}

bool operator== (const Mystring2 &lhs, const Mystring2 &rhs) {
    if (std::strcmp(lhs.text, rhs.text) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}
