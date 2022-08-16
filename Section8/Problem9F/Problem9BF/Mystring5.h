#ifndef MYSTRING5_H
#define MYSTRING5_H
#include <iostream>

class Mystring5
{
    friend std::istream& operator>> (std::istream &is, Mystring5 &rhs);
    friend std::ostream& operator<< (std::ostream &os, Mystring5 &rhs);

    friend Mystring5 operator+ (const Mystring5 &lhs, const Mystring5 &rhs);
    friend Mystring5& operator+= (Mystring5 &lhs, const Mystring5 &rhs);
    friend Mystring5 operator* (const Mystring5 &lhs, int n);
    friend Mystring5& operator*= (Mystring5 &lhs, int n);
    friend bool operator== (const Mystring5 &lhs, const Mystring5 &rhs);
    friend bool operator!= (const Mystring5 &lhs, const Mystring5 &rhs);
    friend bool operator> (const Mystring5 &lhs, const Mystring5 &rhs);
    friend bool operator< (const Mystring5 &lhs, const Mystring5 &rhs);

    friend Mystring5 operator- (Mystring5 &lhs);
    friend Mystring5& operator++ (Mystring5 &lhs);
    friend Mystring5 operator++ (Mystring5 &lhs, int);

private:
    char *text;
public:
    Mystring5();
    Mystring5(const char *str);
    Mystring5(const Mystring5 &source);
    Mystring5(Mystring5 &&source);
    ~Mystring5();

    Mystring5& operator= (const Mystring5 &rhs);
    Mystring5& operator= (Mystring5 &&rhs);
};

#endif