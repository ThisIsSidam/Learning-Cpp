// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 04/09/2022
//
// Day33 Of Learning C++
// --------------------------------------

/* 
--Weak Pointer--
This one provied a non-owning weak reference.

Goes like this: weak_ptr<T>

Points to an object of type T on heap, doesn't participate in owning relationship. Always 
created from a shared pointer. Doesn't increment or decrement the use_count.

It is used to prevent strong reference cycles which could prevent object being deleted.

-Reference Cycle-
Suppose we have two classes A and B, each having an attribute which is a shared pointer of 
the opposite type, meaning A has shared pointer of B and B has that of A. 
we make a shared pointer that points to a Class A object c and a Class B object d, where 
d has c as it's value. 

Now, if we delete c, or d, the compiler thinks that the other object is still using the 
object and just deletes the pointer and not the object and then we delete d and again the
pointer is destroyed but the data is not and it causes the issue where the data is pointing
at each other and the pointers to the objects are destroyed.

The resolution is that we replace Class B's shared pointer attribute to a weak pointer. I
may have been unable to explain this but I hope the code below explains it.
*/

#include <iostream>
#include <memory>

class B; // A prototype thingy for class, telling compiler that is exists.

class A {
    std::shared_ptr<B> ptr;
    public:
        void set_A(std::shared_ptr<B> &b) {
            ptr = b;
        }
        A() { std::cout << "A's Constructor" << '\n'; }
        ~A() { std::cout << "A's Destructor" << '\n'; }
};

class B {
    std::weak_ptr<A> ptr;
    public:
        void set_B(std::shared_ptr<A> &a) {
            ptr = a;
        }
        B() { std::cout << "B's Constructor" << '\n'; }
        ~B() { std::cout << "B's Destructor" << '\n'; }
};

// Custom deleted prototype
void my_deleter(int*);


int main()
{
    std::cout << "===== Weak Pointer Section =====================" << '\n';

   { // Separate block so it deleted right away
    std::shared_ptr<A> c = std::make_shared<A>();
    std::shared_ptr<B> d = std::make_shared<B>();
    c->set_A(d);
    d->set_B(c);
    }
    
    /* You see the whole thing here, they point to each other and the use_count isn't 
    able to go zero to delete the object on heap, and only the pointer gets deleted. 

    Currently the B's attribute is a weak pointer and upon running the program you can 
    see both the constructor and destructor running but if you change the weak pointer
    to shared one, then you'll only see constuctors and no destructor.

    --Custom Deleters--
    Sometimes when we destroy a smart pointer we need more than to just destroy the object of
    heap, there might be things connected to it that you may want to alter. 

    These are special use cases, and there are multiple ways to do this, two of which are:
    - Functions  - Lambdas

    We haven't studied Lambdas yet but in short they are anonymous functions that have no name
    and can be defined in line right where you expect to use it.

    Let's see all this in action.
    */


    std::cout << "===== Custom Deleter Section =====================" << '\n';

    {
    std::shared_ptr<int> cc {new int{1000001}, my_deleter};
    std::cout << "C.C. : " << *cc << '\n';
    } // Keeping it in separate block so it deletes right away.
    
    
    return 0;
}


void my_deleter(int* point) {
    // Other stuff
    std::cout << "This is the custom deleter of CC!" << '\n';
    delete point;
}