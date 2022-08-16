// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 13/07/2022
//
// Problem9B of Learning C++
// After Day26
// Name- Mass Overload GF
// --------------------------------------

/*
* This Problem is easy to describe, you have to overload loads of operators, all that we learnt
* and some new ones too. Like, +=, *= and pre and post increment and decrement operators. 
* And since I've never shown how incre and decre are overloaded, let me give an idea of how 
* it can be overloaded and you do it yourself. So in pre, you have to set return value as 
* reference object and just do what you wanna do in code and return it. But in post, you have 
* ask for normal return value. Create a temp, save value in it, do what you wanna do with 
* the original and  return the temp. Also, it is not fixed for what you have to do with 
* those incre and decre. For numbers, it might make sense, but we've been using strings in 
* this whole section, so, we have free will to what to do with it. 
* 
* Also, there are two ways of overloading operators, as member methods and as global functions.
* So, do those separately. Now, go overload everything.
*/

// --As Global Functions--
#include <iostream>
#include <cstring>
#include "Mystring5.h"

// Prototypes
std::istream& operator>> (std::istream &is, Mystring5 &rhs);
std::ostream& operator<< (std::ostream &os, Mystring5 &rhs);

Mystring5 operator+ (const Mystring5 &lhs, const Mystring5 &rhs);
Mystring5& operator+= (Mystring5 &lhs,const Mystring5 &rhs);
Mystring5 operator* (const Mystring5 &lhs, int n);
Mystring5& operator*= (Mystring5 &lhs, int n);
bool operator== (const Mystring5 &lhs,const Mystring5 &rhs);
bool operator!= (const Mystring5 &lhs,const Mystring5 &rhs);
bool operator> (const Mystring5 &lhs,const Mystring5 &rhs);
bool operator< (const Mystring5 &lhs,const Mystring5 &rhs);

Mystring5 operator- (Mystring5 &lhs);
Mystring5& operator++ (Mystring5 &lhs);
Mystring5 operator++ (Mystring5 &lhs, int);

int main()
{
    // We'll check all overloaded operators one by one.

    // Assignment Operator (=)
    std::cout << "-----Assignment Operator (=)---------------" << '\n';
    Mystring5 anakin {"Anakin Skywalker"};
    Mystring5 vader {};
    vader = anakin;

    std::cout << "anakin : " << anakin << '\n';
    std::cout << "vader : " << vader << '\n';

    // Concatenation Operator (+)
    std::cout << "\n-----Concatenation Operator (+)---------------" << '\n';
    Mystring5 darth {};
    darth = anakin + " is Darth Vader.";
    std::cout << "darth : " << darth << '\n';

    // Concatnate and Assign (+=)
    std::cout << "\n-----Concatnate and Assign (+=)---------------" << '\n';
    Mystring5 sidious {"Darth Sidious"};
    std::cout << "sidious : " << sidious << '\n';
    sidious += " is alive.";
    std::cout << "sidious : " << sidious << '\n';

    // Repeatition Operator (*)
    std::cout << "\n-----Repeatition Operator (*)---------------" << '\n';
    Mystring5 r2d2 {"R2D2"};
    std::cout << "r2d2 : " << r2d2 << '\n';
    r2d2 = r2d2 * 4;
    std::cout << "r2d2 : " << r2d2 << '\n';

    // Repeat and Assign (*=)
    std::cout << "\n-----Repeat and Assign (*=)---------------" << '\n';
    Mystring5 meyopapa {"No, I am your father"};
    std::cout << "meyopapa : " << meyopapa << '\n';
    meyopapa *= 7;
    std::cout << "meyopapa : " << meyopapa << '\n';

    // Equality and Inequality Operator (==, !=)
    std::cout << "\n-----Equality and Inequality Operator (==, !=)-----" << '\n';
    std::cout << std::boolalpha;
    std::cout << "r2d2 == meyopapa : " << (r2d2 == meyopapa) << '\n';
    std::cout << "r2d2 != meyopapa : " << (r2d2 != meyopapa) << '\n';

    // Greater than and Less than Operator (> , <)
    std::cout << "\n-----Greater than an Less than Operator (>, <)-----" << '\n';
    std::cout << "r2d2 > meyopapa : " << (r2d2 > meyopapa) << '\n';
    std::cout << "r2d2 < meyopapa : " << (r2d2 < meyopapa) << '\n';

    // Minus Operator (-) operator used to change string to lower case
    std::cout << "\n-----Minus Operator (-)---------------" << '\n';
    std::cout << "r2d2 : " << r2d2 << '\n';
    r2d2 = - r2d2;
    std::cout << "r2d2 : " << r2d2 << '\n';

    // Pre and Post Inrement Operator (++) used to change string to upper case
    std::cout << "\n-----Pre Increment(++)---------------" << '\n';
    std::cout << "r2d2 normally : " << r2d2 << '\n';
    Mystring5 r2d2A {};
    r2d2A = ++r2d2;
    std::cout << "pre incremented r2d2A : " << r2d2A << '\n';
    // r2d2A should become uppercase directly

    std::cout << "\n-----Post Increment(++)---------------" << '\n';
    Mystring5 r2d2B {};
    r2d2 = -r2d2; // So, we can have smaller in next expression
    r2d2B = r2d2++;
    std::cout << "post increment Phase 1 r2d2B : " << r2d2B << '\n';
    std::cout << "post increment Phase 2 r2d2 : " << r2d2 << '\n';
    // r2d2B will still contain lowercase r2d2 where r2d2 itself after
    // statement will have turned uppercase.

    // Input operator (>>)
    std::cout << "\n-----Input Operator(>>)---------------" << '\n';
    Mystring5 lastskywalker {};
    std::cout << "Write the first name of the last Skywalker." << '\n';
    std::cin >> lastskywalker;
    std::cout << "lastskywalker : " << lastskywalker << '\n';

    return 0;
}

std::istream& operator>> (std::istream &is, Mystring5 &rhs) {
    char *buff = new char[1000];
    is >> buff;
    std::strcpy(rhs.text, buff);
    return is;
}

std::ostream& operator<< (std::ostream &os, Mystring5 &rhs) {
    os << rhs.text << '\n';
    return os;
}

Mystring5 operator+ (const Mystring5 &lhs, const Mystring5 &rhs) {
    char *buff = new char[std::strlen(lhs.text) + std::strlen(rhs.text) + 1];
    std::strcpy(buff, lhs.text);
    std::strcat(buff, rhs.text);
    Mystring5 temp {buff};
    delete [] buff;
    return temp;
}

Mystring5& operator+= (Mystring5 &lhs, const Mystring5 &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

Mystring5 operator* (const Mystring5 &lhs, int n) {
    char *buff = new char[std::strlen(lhs.text) * n + 1];
    std::strcpy(buff, lhs.text);

    for(int i = 0; i < n - 1; i++) {
        std::strcat(buff, lhs.text);
    }
    Mystring5 temp {buff};
    delete [] buff;
    return temp;
}

Mystring5& operator*= (Mystring5 &lhs, int n) {
    lhs = lhs * n;
    return lhs;
}

bool operator== (const Mystring5 &lhs, const Mystring5 &rhs) {
    return (std::strcmp(lhs.text, rhs.text)  == 0);
}

bool operator!= (const Mystring5 &lhs, const Mystring5 &rhs) {
    return (std::strcmp(lhs.text, rhs.text) != 0);
}

bool operator> (const Mystring5 &lhs, const Mystring5 &rhs) {
    return (std::strcmp(lhs.text, rhs.text) > 0);
}

bool operator< (const Mystring5 &lhs, const Mystring5 &rhs) {
    return (std::strcmp(lhs.text, rhs.text) < 0);
}

Mystring5 operator- (Mystring5 &lhs) {
    char *buff = new char[std::strlen(lhs.text) + 1];
    std::strcpy(buff, lhs.text);

    for(size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring5 temp {buff};
    delete [] buff;
    return temp;
}

Mystring5& operator++ (Mystring5 &lhs) {
    char *buff = new char[std::strlen(lhs.text) + 1];
    std::strcpy(buff, lhs.text);

    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::toupper(buff[i]);
    }
    lhs.text = buff;
    buff = nullptr;
    return lhs;
}

Mystring5 operator++ (Mystring5 &lhs, int) {
    char *buff = new char[std::strlen(lhs.text) + 1];
    std::strcpy(buff, lhs.text);

    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::toupper(buff[i]);
    }
    Mystring5 temp {lhs.text};
    lhs.text = buff;
    buff = nullptr;
    return temp;
}
