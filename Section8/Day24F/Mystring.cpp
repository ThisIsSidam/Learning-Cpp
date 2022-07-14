#include "Mystring.h"
#include <cstring>
#include <iostream>

Mystring::Mystring() 
    : text{nullptr} {
    text = new char[1];
    *text = '\0';
}

Mystring::Mystring (const char *str) 
    : text{nullptr} {
    if(str == nullptr) {
        text = new char [1];
        *text = '\0';
    }
    else { 
    text = new char[std::strlen(str) + 1];
    std::strcpy(text, str);
    }
}

Mystring::Mystring (const Mystring &source) 
    : text{source.text} {};

Mystring::~Mystring () {
    delete [] text;
}

void Mystring::display_details() {
    std::cout << "=========================================" << '\n';
    std::cout << text << " : " << get_length() << '\n';
    std::cout << "=========================================" << '\n';
}

char* Mystring::get_text() const{
    return text;
}

int Mystring::get_length() const {
    return std::strlen(text);
}

// overloaded Copy Assignment
Mystring& Mystring::operator= (const Mystring &rhs) {
    if (this == &rhs){  // First check if the lhs = rhs, that will save us from trouble.
        return *this;
    }
    
    delete [] text; // If not, delete the current values of that object.
    text = new char[std::strlen(rhs.text) + 1]; // Make space for the new stuff.
    std::strcpy(text, rhs.text); // Assign it.
    return *this; // Return the objet with new stuff.
        
}

// Overloaded Move Assignment
Mystring& Mystring::operator= (Mystring &&rhs) {
    if(this == &rhs) { // Pretty much the same thing as the copy version.
        return *this;
    }

    delete [] text;
    text = rhs.text; 
    rhs.text = nullptr; // We are moving so we deallocate ths rhs occupied space.
    return *this;
    
}

// Overloading Unary Operators
Mystring Mystring::operator- () 
{
    char *buff = new char[std::strlen(text) + 1];
    std::strcpy(buff, text);

    for(size_t i {0}; i < std::strlen(buff); i++)
    {
        buff[i] = std::tolower(buff[i]);
    }

    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Overlaoding Binary Operator

Mystring Mystring::operator+ (const Mystring &rhs) const {
    char *Buff = new char [std::strlen(text) + std::strlen(rhs.text) + 1];
    std::strcpy(Buff, text);
    std::strcat(Buff, rhs.text);
    Mystring temp {Buff};
    delete [] Buff;
    return temp;
}

bool Mystring::operator== (const Mystring &rhs) const {
    if (std::strcmp(text, rhs.text) == 0) {
        return 1;
    }
    return 0;
}
