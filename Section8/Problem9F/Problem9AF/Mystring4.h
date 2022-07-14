#ifndef MYSTRING4_H
#define MYSTRING4_H
#include <iostream>

class Mystring4
{
    friend std::istream& operator>>(std::istream &is, Mystring4 &rhs);
    friend std::ostream& operator<<(std::ostream &os, Mystring4 &rhs);
private:
    char *text;
public:
    // Constructors and Destructors
    Mystring4(); // No-Args Constructor
    Mystring4(const char *str); // Overloaded Constructor
    Mystring4(const Mystring4 &source); // Copy Constructor
    Mystring4(Mystring4 &&source); // Move Constructor
    ~Mystring4(); // 

    //Overloads
    Mystring4& operator=(const Mystring4 &rhs);
    Mystring4& operator=(Mystring4 &&rhs);
    Mystring4 operator+(const Mystring4 &rhs);
    Mystring4 operator+=(const Mystring4 &rhs);
    Mystring4 operator*(int rhs);
    Mystring4 operator*=(int rhs);
    bool operator== (const Mystring4 &rhs);
    bool operator!=(const Mystring4 &rhs);
    bool operator>(const Mystring4 &rhs);
    bool operator<(const Mystring4 &rhs);
    Mystring4 operator-(); // Turns string to lowercase.
    Mystring4& operator++(); // Turns string to uppercase(Pre).
    Mystring4 operator++(int); // Turns string to uppercase(Post).




};

#endif