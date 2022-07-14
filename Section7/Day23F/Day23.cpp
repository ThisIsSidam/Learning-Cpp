// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 27/05/2022
//
// Day23 Of Learning C++
// --------------------------------------

/*
* --The "this" Keyword--
* "this" is a reserved keyword, it contains address to the current object. You would have seen this in 
* the debugger or in some error. We can say that it's a pointer to an object. It can only be used in 
* the class scope. All members access is done via this pointer.
* 
* You may think what the current object means. Well, suppose you use a member method, you used an 
* object to access that method, like this- chris.show_scores();, in this chris is an object and 
* show_scores is the method, here this pointer points to chris object.
*
* Now, it can be used in situations like this-
* class_name::class_name(int balance) Here the attribute name is also balance.
* { 
*     balance = balance;
* };
* Here compiler will get confused on which is the attribute balance and which is function variable 
* balance. Does it need to assign attribute value balance into the function variable balance or 
* the other way. We can change it like this and it will work-
* class_name::class_name(int balance)
* {
*     this-> balance = balance;
* };
* Now don't ask what is that arrow shit. You should know that if you read the Day19 file. There are 
* more ways you can use the "this" keyword, and you can find them, just search the fking net.
* 
* --Const Correctness--
* We can have a const objects, there is nothing else to talk in that, you know how to use it, just the
* old simple way, just put it on the front. The problem is, if you have a const object, you can't use
* methods on it anymore. Take the setter and getter methods. The setter does changes so the const won't 
* allow it, but it won't allow getter either. Const will think that the getter may change stuff and on 
* that mere possibility the access is denied. You can use const on methods for that- 
* 
* return_type method_name(attr) const;
* 
* That was the example of what const correctness looks like. Now this method will be allowed to be used 
* with const objects. It will still give errors if you try to change stuff inside the method but allows
* it. 
* 
* --Static Class Members--
* Sometimes there are stuff that don't change according to objects. Those are same for every other 
* object, and hence statics are used for those. 
*
* Static Attributes/Data members- An static attribute belongs to the whole class and not just the o
* objects. And are used for class wide information.
*
* Static Methods- Are called using the class like this- class_name::static_method(); and are
* independent of any object. And can only access static data members and not normal ones.
*
* Note: Since static attributes are for whole class, you may want to initialize them at the start, 
* but that would just give off error. 
*
* --Structs VS Classes--
* Structs are a C language thing, and are pretty much identical to classes. The most important 
* difference between the two is that, normally class members are private but in structs, normally
* class members are public.
* 
* Yuu should use Structs when you want to use Passive Objects with Public access and don't need to
* declare methods.
* 
* You should use Classes when you want to use Active Objects with Private access and want to 
* implement methods as needed.
* 
* --Friends of a Class--
* A function or a class that has access to private class members. And that function or class is
* member of that class.
* 
* Function- Can be a regular non-member function. Can be a member method of another class.
* Class- Another Class.
*
* Friendship is granted not taken. Friendship is declared explicitely is class that is granting
* friendship. For functions, a prototype is given in the start of the class with "friend" keyword
* on the beginning.
* 
* Friendship is not Symmetric. If A has granted friendship to B, it means B can access A's data, 
* but this doesn't happen in the reverse way. A can't access B's data. Yup, it is a one way
* friendship. And it is not transitive either. If A has granted friendship to B, and B has
* granted frienship to C, it doesn't mean that C can access A's data. For that A will have to
* explicitely grant friendship to C.
*
* Ex- 
* class player
* {
*    private:
*       friend return_type func_name (attr);
*       friend void other_class::method_name (attr);
*       friend class class_name;
* };
*
* For statics practice, write code for a program that keeps record of how many objects are there 
* of that class.
*/
#include <iostream>
#include <string>

class Player
{
private:
    static int current_players;
    std::string name;
    int score;
public:
    //Constructor
    Player(std::string = "Nobody", int = 0);
    //Copy Constructor
    Player(const Player &);
    //Static Method
    static int num_current_players();
    //Normal Methods
    std::string get_name(){return name;};
    int get_score(){return score;};
    //Destructor
    ~Player();
};

int Player::current_players {0}; 

Player::Player(std::string str, int n)
    : name{str}, score{n}
    {
    current_players++;
};

Player::Player(const Player &ply)
    : Player{ply.name, ply.score}{};

int Player::num_current_players()
{
    return current_players;
};

Player::~Player()
{
    current_players--;
};

int main()
{
    std::cout << Player::num_current_players() << '\n';
    Player ronaldo("Chris", 235);
    std::cout << Player::num_current_players() << '\n';
    Player Messi("Messi", 199);
    std::cout << Player::num_current_players() << '\n';
    
    // Below is a local block, object inside should get deleted after block end.
    {
        Player Dhoni("Mahendra", 1000);
        std::cout << Player::num_current_players() << '\n';
    }
    std::cout << Player::num_current_players() << '\n';

    // Creating a pointer pointing player and then deleting it.
    Player *plyptr;
    plyptr = new Player("Sachin", 10000);
    std::cout << Player::num_current_players() << '\n';
    delete plyptr;
    std::cout << Player::num_current_players() << '\n';
    return 0;
}