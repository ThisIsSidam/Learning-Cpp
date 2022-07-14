// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 22/05/2022
//
// Day22 Of Learning C++
// --------------------------------------

/*
* --Copy Constructor--
* Before we know about the copy constructor, let's first know how an object can be copied. There
* are three ways. 
* First, we can ask for an object as an argument of a method or function and it's 
* copy will be made and sent there because when given as argument, a copy is made and it's directly 
* sent when we use pointers and references.
* Second, when we create an object inside a function and return it, it's copy is made unless we use 
* pointers or references.
* Third, When we create an object, we give arguments that are taken by the constructors. We can also
* just give any other object of the same class, and the constructor will copy all the datails of that
* object into the new object, basically, that object is copied.
*
* We don't quite need to create a copy constructor since we already get one by C++. But, we need one 
* if we are gonna use pointers. Using pointers, only the address is copied and not the data, this is 
* called Shallow Copy that will cause problems for us. We'll know how to counter that, but first let's 
* see what a normal copy constructor looks like.
*
* Ex- It's basically a constructor, so there won't be any big differences.
* class_name::class_name(const class_name &source)
*   : attr1{source.attr1}, attr2{source.attr2} {};
* 
* --Shallow Copy and Deep copy--
* When we copy something, it's copy is made which is good enough for us. But while copying pointers, a new 
* pointer is created as a copy that points to the same memory address in heap. And as we know if a pointer's
* scope ends, it is deleted automatically. The same thing happens here. But there are two pointers currently
* pointing at that piece of data in heap. This causes the problem of Dangling Pointer. I hope you get it, I'd 
* told what that is previously. This was Shallow Copy.
*
* Now, in Deep copy, a new pointer is made as the copy of that pointer but it also copies the data pointed by 
* that pointer and also copies it into the new pointer. Preventing the problem of the Dangling Pointer. Let's 
* see what it's code looks like. We'll be seeing the example from the perspective of having a pointer attribute
* otherwise things just will be the same.
*
* Ex-
*
* Constructor-
* class_name::class_name(int d)
8 {
*     data = new int;
*      *data = d;
* }
* 
* Shallow Copy 
* class_name::class_name(const class_name &source)
*    : pointer_attr{source.pointer_attr} {};
*
* Deep Copy 
* class_name::class_name(const class_name &source)
*   : pointer_attr{*source.pointer_attr} {};
* 
* Destructor-
* class_name::class_name()
* {
*    delete data;
* }
* 
* I also gave the example of how a constructor and destructor while having a pointer would look like.
* And did you catch the difference between the codes of Shallow and Deep copy. In shallow, the constructor
* will make a copy of the pointer and the location the pointer is pointing is copied. In deep, the
* constructor will make a copy of the pointer and the data pointed by the original pointer will be copied
* and saved in the new pointer. And changes made to the second pointer pointed data will not occur to the
* original one. But changes made to the second pointer pointed data would occur to the original one if 
* shallow copy is used.
*
* --Move Constructors--
* When we do copying, whichever it is, shallow or deep. It is computationaly expensive. You have to make an
* object and then copy the original one's data to this one and then keep both. In moving, we create, 
* copy one's data and delete the original.
*
* Also, moving is used with R-values and not L-values. Hope you remember those. You can check out Day18 for
* revision. Like, you are working with back accounts, there each account is the class objects, so it's not
* right to delete an object's data since it might just cause serious trouble. So, moving is used with R-values
* only.
*
* It is totally optional, and if not provided copy constructor is used, but using move constructors can be very
* useful.
*
* Sometimes while using debugger, you might not be able to see the actions done by either copy or move constructor.
* It is because the compiler uses an optimization technique to eliminate unnecessary copying, it is called
* COPY ELLISION.
*
* Like in copy constructor, we gave reference to the source object, here we do the same. But since in copy constr.
* L-values were used, their reference operator which is '&' was used. Here, we'll be using R-values and their 
* reference operator is "&&", yup just double it. Now, you may be thinking R-values are temporary values, and 
* how can you create temporary objects. Well, like this- class_name{attr_according_to_any_constr}
* 
* Note: Giving R-value reference a L-value causes errors and giving L-value reference a R-value also causes errors.
*
* These are mainly used in giving objects as function parameter, and you can do it this way-
* function_name(class_name{attr});
* 
* Now let's see how the code of move constructor looks like-
* class_name::class_name(class_name &&source)
*       : data{*source.data} 
* {
*       *source.data = nullptr;      
* }
* 
* There are multiple things to note, first there isn't any const since we have to delete the data. Second the data 
* pointed by the pointer is deleted and not the pointer itself, deletion will be handled by the destructor.

*/
#include <iostream>

class Music_Artists
{
private:
    int *songs;

public:
    //Constructor
    Music_Artists(int n);
    //Methods
    void setter (int n) {*songs = n;};
    int getter () { return *songs;};
    //Copy Constructor
    Music_Artists(const Music_Artists &);
    //Move Constructor
    Music_Artists(Music_Artists &&);
    //Destructor
    ~Music_Artists();
};

//Constructor
Music_Artists::Music_Artists(int n)
{
    songs = new int;
    *songs = n;
}

//Copy Constructor
Music_Artists::Music_Artists(const Music_Artists &source)
    : Music_Artists{*source.songs} {};

//Move Constructor
Music_Artists::Music_Artists(Music_Artists &&source)
    : songs{source.songs}
    {
        source.songs = nullptr;
    };

//Destructor
Music_Artists::~Music_Artists()
{
    delete songs;
}

// A Normal Function
int getter_as_a_func(Music_Artists tist)
{
    return tist.getter();
};

int main()
{
    Music_Artists Me {0};

    std::cout << Me.getter() << '\n';

    // A copy of 'Me' object will be made and sent to func.
    std::cout << getter_as_a_func(Me) << '\n'; 

    // Creating an R-value for the usage of the Move constructor.
    std::cout << getter_as_a_func(Music_Artists{4}) << '\n';
    
    return 0;
}