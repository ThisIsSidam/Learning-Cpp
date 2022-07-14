#ifndef MYSTRING3_H
#define MYSTRING3_H
#include <iostream>

class Mystring3
{
    friend std::istream& operator>> (std::istream &is, Mystring3 &rhs);
    friend std::ostream& operator<< (std::ostream &os, const Mystring3 &rhs);
private:
    char *text;

public:
    // Constructors and Destructors
    Mystring3();
    Mystring3(const char *obj);
    Mystring3(const Mystring3 &source); // Copy Constructor
    Mystring3(Mystring3 &&source); // Move Constructor
    ~Mystring3();

    Mystring3& operator= (const Mystring3 &rhs); // Copy Assignment
    Mystring3& operator= (Mystring3 &&rhs); // Move Assignment

};

#endif