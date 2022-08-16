// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 03/08/2022
//
// Day28 Of Learning C++
// --------------------------------------

/* --Invoking Base Class Constructor--
We leanrt earlier that Base class constructors aren't inherited automatically. 
And we also learnt a method to inherit them but that comes with a lot of rules
so we won't be messing with that. So, this time we'll be looking at a better
way to inherit those. These classes will be pretty short so we'll be doing these
in a single file.

You see below how we call for the Base class Constructor on line 35. Which constructor
to call is upto you by giving the right arguments.
 
--Copy and Move Constuctors with Inheritence--

We've used the copy constructor in the base class on line 36 in derived class on line 52.
It is not any hard to understand if you understand how we invoke the base class' overloaded
constructor in the derived class. The same way we are just calling for the Base class' 
copy constructor. It is called and then it slices out the base part of the derived object
(this is called Slicing), does it's copying thing and then leaves the other parts of 
derieved object for the derived class' copy constructor. 

That is also true that it was not needing for me to even create a copy constructor, the 
compiler would have taken care of everything on it's own. But I had to demonstrate it.  
The move constructor works the same and I don't feel the need to show it to you, as it
would be time waste.

--Overloaded Assignment Operator with Inheritence--
After that we have this, and this is also pretty much the same thing. You call for the 
Base class overloaded assignment operator for slicing and the else is done after that.
*/


#include <iostream>

class Number {
    protected:
        int value; 

    public:
        Number() : value{0} {};
        Number(int x) : value{x} {};
        void get_value() { std::cout << "value: " << value << '\n'; };
        
        Number(const Number &other) // Copy Constructor
            : value{other.value} {};

        Number& operator=(const Number &rhs) { // Overloaded Assignment
            if (this == &rhs) {
                return *this;
            }
            value = rhs.value;
            return *this;
        }
};

class BigNumber: public Number {
    private:
        int double_value;
    
    public:
        BigNumber() : double_value{0} {};
        BigNumber(int x) : Number(x), double_value{2*x} {}; 
        void get_details() { 
            std::cout << "value: " << value << '\n'; 
            std::cout << "double_value: " << double_value << '\n';
         }

        BigNumber(const BigNumber &other) 
        : Number{other}, double_value{other.double_value} {};

        BigNumber& operator=(const BigNumber &rhs) {
            if(this == &rhs) {
                return *this;
            }
            Number::operator=(rhs);
            double_value = rhs.double_value;
            return *this;
        }
};


int main()
{
    std::cout << "-----Constructor Check-----" << '\n';
    BigNumber n{2};
    n.get_details();
    
    /* You see that we have called for the overloaded constructor, if hadn't 
    the default normal one would have been called giving the value = 0.*/

    std::cout << "\n-----Copy Constructor Check-----" << '\n';
    BigNumber s{n};
    s.get_details();

    /* We copy the data of n into s and see that the data is same, meaning the 
    copy was successful. */

    std::cout << "\n-----Overloaded Assignment Check-----" << '\n';
    BigNumber k{15};
    k.get_details();

    k = s;
    k.get_details();

    /* 
    We previously give a higher value to k but then assign the values of 
    s which are quite smaller and see the assignation was successful.

    Things to know-
    - Often you don't need to provide your own.
    - If don't declare in derived class, compiler will create it and 
    use the base version automatically.
    - If do create it in derived class, then you must explicitly invoke
    the base version.
    - Be careful when using pointers and be extra careful when both the 
    base and derived class has pointers.
    */


    return 0;
}