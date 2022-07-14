#include "Mystring2.h"
#include <cstring>
#include <iostream>

// No-Args Constructor
Mystring2::Mystring2()
    : text{nullptr} {
        text = new char [1];
        *text = '\0';
}

// Overloaded Constructor
Mystring2::Mystring2(const char *str)
    : text{nullptr} {
        if (str == nullptr){
            text = new char [1];
            *text = '\0';
        }
        else {
            text = new char [std::strlen(str) + 1];
            std::strcpy(text, str);
        }
}

// Copy constructor
Mystring2::Mystring2 (const Mystring2 &source) 
    : text{source.text} {};

// Destructor
Mystring2::~Mystring2()
{
    delete [] text;
}

// Assignment Operator (Copy)
Mystring2& Mystring2::operator= (const Mystring2 &rhs) {
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

// Assgnment Operator (Move)
Mystring2& Mystring2::operator= (Mystring2 &&rhs) {
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

void Mystring2::display_details () {
    std::cout << "========================================" << '\n';
    std::cout << text << " : " << std::strlen(text) << '\n';
    std::cout << "========================================" << '\n';
}

char* Mystring2::get_text () const {
    return text;
}