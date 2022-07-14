// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 19/05/2004
//
// Day21 Of Learning C++
// --------------------------------------

/*
* --Constructors--
* Are special member methods invoked during and object creation. They are useful for initialization
* and have the same name as the class. They don't have any return type and they can be overloaded.
* 
* They actually lay the basic structure of a class instance. When you don't create any constructor,
* c++ automatically creates an empty one. When you have a constructor requiring a string, then you 
* can't create objects without name. You have to give it a string as argument or else you get an 
* error. Thus you don't really need to set every other attribute for the object and can just ask 
* them through constructors. 
*
* Let's think it over as an example, like you are making a doll wear cloths. The cloths are the
* attributes. So, different sets of attributes can have different constructors. Like you can have a
* constructor with attributes underwear, shirt and pants. And another constructor with attributes
* underwear, trousers and tshirt. You can leave a constructor with just underwear attribute. Just 
* know that the order of datatypes shouldn't be the same, like if there are two constructors with
* parameters int, int, char, then the compiler will get confused on which constructor to use. So,
* there should be something for the compiler to distiguish with. 
*
* Note: Once you create a constructor, the empty constructor provided by c++ in absence of any, won't
* be provided this time. So, it is a good practice to have an empty constructor for when you wanna 
* create objects without any attribute value.
* 
* --Destructors--
* These are also special, and have the same name as the class just have a tilde(~) on the front.
* These are called automatically when the scope ends. Don't have any return type or parameters. 
* Can't be overloaded, meaning only exists one per class. These are useful to release memory and
* resources stuck with a object you don't need. You can also call it by the delete keyword, we have 
* used these before with pointers.
*
* Note: When the destructor is called automatically which is when the scope ends, it deletes objects
* in the reverse order of the creation. Like if object Lion was created and then tiger and then dog, 
* then dog will be deleted first, then tiger then lion.
*
* Ex- Player is class
* player::player(std::string name, int score){
*     attribute_name = name;
*     attribute_score = score;
* }
* ~player::player(){};
*
* --Real Initialisation--
* When we use these constructors, these are for initialising the object attributes on spot. 
* But that isn't what exactly happens, the attributes are declared and then they are assigned
* the values. But we can do the real initialisation like this.
* 
* Ex- 
* player::player(std::string name, int score)
*   : attribute_name{name}, attribute_score{score}
* {}
*
* Yes, it leaves the curly braces empty but does the so called real initialisation.
*
* --Delegating Constructors--
* Suppose you have three different constructors for three different scenarios. Like, one for
* when there are three arguments, one for when there are two and one for when there aren't any.
* You'll need to write the initialisation of values for every parametre. But you can delegate 
* a constructor, where you initialise the attributes, you can just forward or say push the work
* to another constructor. Like delegate no and 2 args constructor work to the three args
* constructor and give null values as arguments while delegating.
* 
* Ex- 
* player::player{}
*   :player{0, 0, 0}{};
* player::player{int i, int j}
*   :player{5, 3, 0}{};
* player::player{int i, int j, int k}
*   : attr_1{i}, attr_2{j}, attr_3{k} {};
* 
* In the example we are delegating no args and two args constructor work on the three args 
* constructor.
*
* --Default Constructor Parametre--
* I have heard that we won't need to have defaults because we will need to explicitly get attribute
* values from the user, but sometimes we might need this. So, just like we learned defaults in
* functions. It's the same as we give default vaules in prototype of functions. Literally no differnce.
*
* Now, separate files for class is used when you have a big files and separating them helps a lot. 
* And I did that in the Day20 for demonstration, but since this time my file isn't that big, everything
* is going to be in this file.
*/

#include <iostream>
#include <string>

//Class
class Manager
{
private:
    //Attributes
    std::string name;
    int files;
    int fav_num;

public:
    //Constructer
    Manager(std::string n = "None", int i = 0, int j = 0);
    //Destructer
    ~Manager();
    //Method to print object attributes
    void print_details();
};

//Constructer
Manager::Manager(std::string n, int i, int j)
    : name{n}, files{i}, fav_num{j} {};

//Destructer
Manager::~Manager()
{}

//Method to print object attributes
void Manager::print_details()
{
    std::cout << name << '\n' << files << '\n' << fav_num << '\n';
}



int main()
{
    //Creating Class objects
    Manager Rahul{"Rahul", 34, 32};
    Manager Satya{"Satya"};
    Manager Raushan{};

    //Printing Objects attributes
    Rahul.print_details();
    Satya.print_details();
    Raushan.print_details();
    
    return 0;
}