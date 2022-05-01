// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 25/04/2022
//
// Day19 Of Learning C++
// --------------------------------------

#include <iostream>
#include <string>

/*
* Yup, I'm gonna start from here this time and also we will stop using the namespace directive from 
* now on and we'll use the 'std::' wherever needed. 
*
* --Procedural Programming--
* - This type of pragramming focuses mainly on the actions that program takes, typically are collection of
* functions. All data is declared separately and is passes into functions as arguments and we make stuff
* happen with the help of that. It can be quickly learned. 
*
* - One of the main disadvantage of using this type of programming is that the functions need to know the
* structure of data and if the structure has to be changed because of some reason we have to change all
* of the functions too. Also, as the program gets larger it becomes difficult to understand, maintain, 
* extend, debud and reuse. And become fragile and easy to break. 
*
* -And we've been doing this all this time. So, now we'll learn Object Oriented Programming(OOP).
*/

/*
* --OOP--
* 
* - You know the full form. This type of programming models software in terms of Classes and Objects.
* They are better in many ways like they hide data because not everyone needs to know that, they are
* better in reusability and it brings lots of different topics like Abstraction, Encapsulation,
* Polymorphism and Inheritence that we'll learn as we progress.
*
* - Some things to know about it are that it's better but not always. There are some types of programs
* that just aren't suitable and procedurable programming would be a better choice for them. It has a 
* steeper learning curve and is larger in size than procedural.
*
*
* Now, let's see what are Classes and Objects.
*
* --Classes--
* are like blueprints to create objects. And are userdefined Datatype. Has attributes which is it's 
* data and methods that are functions. 
* Think it like int, int is a datatype that carries a value. So, you can also create datatypes of your
* own. int contains a single value that you use with functions. But your class which is your own datatype
* can contain lots of kinds of values and those are called it's attributes. You can also create functions
* specially for them that are called methods.
*
* --Objects--
* are created from classes. Like you create a variable of a datatype. Just like that, the variable kind of
* thing that you create from your userdefined datatype is called an object. Represents a specific instance
* of a class. Like you create a var from a datatype, that specific var is called that datatype's instance.
* We can create many objects and each one has its own identity. And each can use the defined class methods.
*
* Syntax- 
* class Player
* {
*    //Attributes
*    std::string name;
*    std::health;
*
*    //Methods
*    void talk(std::string);
*    bood is_dead();
* };
*
* Here "Player" is the class name. "name" and "health" are it's attributes. In normal datatypes, there is 
* is a single piece of data so you can just access it by name but since here are multiple, the assignation
* of the data and also accessing it is different.
* Methods are just the prototypes there, if you know that your methods are short then it'll be ok to 
* write in inline functions but not the big ones. They have a different procedure.
*
* Note: Classes are created outside the main fn usually, but you'll learn the proper way.
*
* --Default Attributes--
* If you want you can give values to the Attributes that will work as defaults in case that data is not 
* assigned. You can type it out as you normally intialize data.
*
* --Accessing Data--
* There are two ways, first is using the dot '.' operator, we have previously used it when learning vectors
* and strings. Second is arrow "->" operator. If we have a normal object then we can just easily use the
* dot, but if you have a pointer, then you'll have to first dereference it and then use dot operator. 
* Or you can just use the arrow operator. 
* 
* Syntax-
* object_name.attribute_name;
* (*pointer_name).attribute_name;
* pointer_name->attribute_name;
*
* Note: Precedence of dot operator is higher than dereference operator so we use paranthesis to increase 
* the precedence towards dereference it first.
*
* Accessing Methods is the same, you just need to give the arguments or leave the parens empty if there
* isn't anything to give.
* 
* --Access Modifiers--
* OOP is pretty strict about data. And only gives access to what's needed. Like if you don't want anyone
* or anything to mess with the attributes, then you should private it out. And no one will be able to even
* touch it.
* 
* There are three types- Public, Private and Protected.
* 
* Public- Easily Accessible.
* Private- This is the default, and is only accessible by members of class and friends of class(You will
* learn about it later).
* Protected- Pretty much the same as private, the only difference comes when using inheritence(You will
* learn this later too).
*
* Syntax-
* class name
* {
* public: 
*   //data
* };
*
* It's not like you can only use one modifier at a time. You can use different for different parts of the
* class. As of I've seen people private out the attributes and publicize(Is that a word?) the methods and
* use methods just to change the attributes. Take Bank accounts for example, money is that account is an
* attribute, so you really don't want even by mistake to change it just without reason, right. 
*
* When I say that private access modifier prevents access to the data, I don't mean just altering it.
* I mean you literally can't access it, meaning you can't even cout it. Methods are members of classes 
* and can access and alter the attributes. Also, it doesn't mean any method. Only methods defined under
* that specific class. 
*
* --Methods--
* are literally like functions. Just that you don't have to ask for objects details because they already 
* have access to them. If your functions are short you can just define them inside the class, but if it's 
* long you'll have to do that outside. And not just ordinarily, like this-
* 
* return_type Class_name: Method_name(Parameters).....
*
* Note: It is good to give the class name a capital touch to make it stand out from the crowd of vars.
*
* --Setters and Getters--
* Privatizing the attributes is a normal thing so methods are created to set and get the attributes, and 
* they are called setters and getters. They do noting else usually, just set value and get value.
*
* Now let's create a class. 
*/ 

class Account{
    private:
        std::string name;
        int balance;
    public:
        // Inline Fns defined inside class
        void set_balance(int amount)
        {
            balance = amount;
        };
        int get_balance()
        {
            return balance;
        };
        // Prototype of fn defined outside
        void multiply_balance(int num);
};

void Account::multiply_balance(int num)
{
    balance *= num;
};


int main()
{
    Account sidam;
    sidam.set_balance(100);
    std::cout << sidam.get_balance() << std::endl;

    sidam.multiply_balance(5);
    std::cout << sidam.get_balance() << std::endl;
    return 0;
};