#ifndef MYSTRING2_H
#define MYSTRING2_H


class Mystring2
{
    friend Mystring2 operator- (const Mystring2 &);
    friend Mystring2 operator+ (const Mystring2 &lhs, const Mystring2 &rhs);
    friend bool operator== (const Mystring2 &lhs, const Mystring2 &rhs);

private:
    char *text;

public:
    // Constructors and Destructor
    Mystring2 ();
    Mystring2 (const char *);
    Mystring2 (const Mystring2 &source);
    ~Mystring2 ();

    Mystring2& operator=(const Mystring2 &rhs);
    Mystring2& operator=(Mystring2 &&rhs);
    
    void display_details ();
    char* get_text() const;


};

#endif