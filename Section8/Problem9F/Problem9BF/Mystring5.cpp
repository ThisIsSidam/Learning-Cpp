#include "Mystring5.h"
#include <cstring>

Mystring5::Mystring5()
    : text{nullptr} {
        text = new char[1];
        *text = '\0';
    }

Mystring5::Mystring5(const char *str) 
    : text{nullptr} {
        if (str == nullptr) {
            text = new char [1];
            *text = '\0';
        }
        else {
            text = new char[std::strlen(str) + 1];
            std::strcpy(text, str);
        }
    }

Mystring5::Mystring5(const Mystring5 &source) 
    : text{source.text} {};

Mystring5::Mystring5(Mystring5 &&source) 
    : text{source.text} {
        source.text = nullptr;
    }

Mystring5::~Mystring5()
{
    delete [] text;
}

Mystring5& Mystring5::operator= (const Mystring5 &rhs) {
    if (text == rhs.text) {
        return *this;
    }
    else {
        text = nullptr;
        text = new char[std::strlen(rhs.text) + 1];
        std::strcpy(text, rhs.text);
        return *this;
    }
}

Mystring5& Mystring5::operator= (Mystring5 &&rhs) {
    if (text == rhs.text) {
        return *this;
    }
    else {
        text = nullptr;
        text = rhs.text;
        rhs.text = nullptr;
        return *this;
    }
}