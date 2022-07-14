#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring {
private:    
    char *text;

public:
    Mystring(); // No-args constructor
    Mystring(const char *str); // Overloaded constructor
    Mystring(const Mystring &source); // Copy constructor
    ~Mystring(); // Destructor
    
    // Other Methods
    void display_details (); 
    char* get_text() const;
    int get_length() const;

    // Assign Operator Overloading
    Mystring& operator= (const Mystring &rhs);
    Mystring& operator= (Mystring &&rhs);

    // Unary Operator Overloading
    Mystring operator- (); // Turns the sentence to lowercase.

    // Binary Operator Overloading
    Mystring operator+ (const Mystring &) const; // Concatanation
    bool operator== (const Mystring &) const; // Equality Check
};


#endif