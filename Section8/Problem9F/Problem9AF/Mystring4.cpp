#include "Mystring4.h"
#include <cstring>
#include <iostream>

// Constructors and Destructors

// No-Args Constructor
Mystring4::Mystring4()
    : text{nullptr} {
        text = new char[1];
        *text = '\0';
    }

// Overloaded Constructor
Mystring4::Mystring4(const char *str)
    : text{nullptr} {
        if (str == nullptr) {
            text = new char[1];
            *text = '\0';
        }
        else {
            text = new char[std::strlen(str) + 1];
            std::strcpy(text, str);
        }

    }

// Copy Constructor
Mystring4::Mystring4(const Mystring4 &source)
    : text{source.text} {};


// Move Constructor
Mystring4::Mystring4(Mystring4 &&source) 
    : text{source.text} {
        source.text = nullptr;
    }

// Destructor
Mystring4::~Mystring4()
{
    delete [] text;
}

Mystring4& Mystring4::operator=(const Mystring4 &rhs) {
    if (this == &rhs) {
        return *this;
    }
    else {
        text = nullptr;
        text = new char[std::strlen(rhs.text) +1];
        std::strcpy(text, rhs.text);
        return *this;
    }
}

Mystring4& Mystring4::operator=(Mystring4 &&rhs) {
    if (this == &rhs) {
        return *this;
    }
    else {
        text = nullptr;
        text = rhs.text;
        rhs.text = nullptr;
        return *this;

    }
}

Mystring4 Mystring4::operator+(const Mystring4 &rhs) {
    char *buff = new char[std::strlen(text) + std::strlen(rhs.text) + 1];
    std::strcpy(buff, text);
    std::strcat(buff, rhs.text);
    Mystring4 temp {buff};
    delete [] buff;
    return temp;
}

Mystring4& Mystring4::operator+=(const Mystring4 &rhs) {
    *this = *this + rhs;
    return *this;
}

Mystring4 Mystring4::operator*(int rhs) {
    char *buff = new char[std::strlen(text) * rhs + 1];
    std::strcpy(buff, text);
    for(int i = 0; i < rhs - 1; i++) {
        std::strcat(buff, text);
    }
    Mystring4 temp {buff};
    delete [] buff; 
    return temp;
}

Mystring4& Mystring4::operator*=(int rhs) {
    *this = *this * rhs;
    return *this;
}

bool Mystring4::operator==(const Mystring4 &rhs) {
    return (std::strcmp(text, rhs.text) == 0);
}

bool Mystring4::operator!=(const Mystring4 &rhs) {
    return (std::strcmp(text, rhs.text) != 0);
}

bool Mystring4::operator>(const Mystring4 &rhs) {
    return (std::strcmp(text, rhs.text) > 0);
}

bool Mystring4::operator<(const Mystring4 &rhs) {
    return (std::strcmp(text, rhs.text) < 0);
}

Mystring4 Mystring4::operator-() {
    char *buff = new char[std::strlen(text) +1];
    std::strcpy(buff, text);

    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    
    Mystring4 temp {buff};
    delete [] buff; 
    return temp;
}

Mystring4& Mystring4::operator++() {
    char *buff = new char[std::strlen(text) + 1];
    std::strcpy(buff, text);

    for(size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::toupper(buff[i]);
    }
    text = buff;
    buff = nullptr;
    return *this;
}

Mystring4 Mystring4::operator++(int) {
    char *buff = new char[std::strlen(text) + 1];
    std::strcpy(buff, text);

    for(size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::toupper(buff[i]);
    }
    Mystring4 temp {text};
    text = buff;
    buff = nullptr;
    return temp;
}

