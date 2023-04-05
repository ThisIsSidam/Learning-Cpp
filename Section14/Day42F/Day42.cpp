//----------------------------------------------
// Name- Anshu Kumar Singh a.k.a. Sidam
// Date- 13/03/23
// Purpose- Notes of C++
//
// Day42 of Learning C++
//----------------------------------------------

/* 
== Templates ====================
are Blueprints of functions or classes that allow plug-in of any datatype. Meaning
we will leave a socket kind of place holder in place of datatype and will be able 
to plug-in any data type to that socket/placeholder. The compiler can generate the 
appropriate function/class from blueprint.

Note: In other languages, this happens in run-time but in C++, this happens in 
compile time.

We would be making a generic Max function. It's original systax looks something
like this:

int Max(int a, int b) {
    return (a > b) ? a : b;
}
*/

#include <iostream>
#include <string>
#include <utility>

template <typename T> 
// Here we are making a template parameter. We can switch "typename" keyword with 
// "class", but we're using "typename" here. Then the name of the template 
// parameter. "T" here. 

T Max(T a, T b) { 
    return (a > b) ? a : b;
}

template <typename Q, typename R>
// We can also make multiple template parameters.

void print(Q a, R b) {
    std::cout << a << " " << b << '\n';
}

template <typename F>
class Person {
    F points;    

public: 
    Person(F a): points{a} {};
    F get_points() { return points; };
};

// Note: You must have noticed that I have created a new template type each time
// before use. That is because, those types are associated to the function or
// class below them and you can't use them on other functions or classes. Whoosh!

// Also, when you have template classes. There will only be .h files and not .cpp
// files because template classes can't be compiled as the class is made when an
// object is being made.
int main() {

    std::cout << Max<int>(4, 5) << '\n'; 
    // Now, whenever using the template func, we can provide the type so the compiler
    // can then generate the function. It won't compiler if we don't use the 
    // template function anywhere since the actual function is generate when called.

    // Also, we can also put pretty much all types in those angular brackets, but 
    // sometimes, like in this function, we used the ">" operator. And if we put a 
    // class that doesn't have the overloaded version of that operator, it would
    // cause errors.  

    std::cout << Max(5, 9) << '\n';
    // The compiler can deduce simple types, so we can also skip it when
    // using "Not Complicated Types".

    print<std::string, int>(std::string{"Hello"}, 5);
    // We could've skipped the angular bracks here too.

    // Now let's see the template class.
    Person<float> rahul{4.3};
    // Note: In case of template classes, we can't skip the angular brackets.
    std::cout << rahul.get_points() << '\n';

    /*  
    == Pair Class ==
    There is also this class called "pair" that we can use to create objects
    with only two attributes. The attributes are called first and second. Easy,
    right. 

    Use just have to include the utility file with the preprocessor directive. 
    Make an object of class pair and use it. 
    */

    std::pair student { std::string {"Anshu"}, 18};
    std::cout << "Name: " << student.first << " Roll No.: " << student.second << '\n';

    // It is actually a generic class with public attributes or a generic struct.
    // That's why we can do what we can do.
    return 0;
}