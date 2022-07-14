#include "Mystring3.h"
#include <cstring>

Mystring3::Mystring3() 
    : text{nullptr} {};


Mystring3::Mystring3(const char *obj) 
    : text{nullptr} {
        if (obj == nullptr) {
            text = new char [1];
            *text = '\0';
        }
        else {
            text = new char [std::strlen(obj) + 1];
            std::strcpy(text, obj);
        }
    }

// Copy Constructor
Mystring3::Mystring3(const Mystring3 &source) 
    : text{source.text} {};


// Move Constructor
Mystring3::Mystring3(Mystring3 &&source) 
    : text{source.text} {
        source.text = nullptr;
    }


Mystring3::~Mystring3()
{
    delete [] text;
}

// Copy Assignment
Mystring3& Mystring3::operator= (const Mystring3 &rhs) {
    if (this == &rhs) {
        return *this;
    }
    else {
        delete [] text;
        text = new char [std::strlen(rhs.text) + 1];
        std::strcpy(text, rhs.text);
        return *this;
    }
}

// Move Assignment
Mystring3& Mystring3::operator= (Mystring3 &&rhs) {
    if (this == &rhs) {
        return *this;
    }
    else {
        delete [] text;
        text = rhs.text;
        rhs.text = nullptr;
        return *this;
    }
}