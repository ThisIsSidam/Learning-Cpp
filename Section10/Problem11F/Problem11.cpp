// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 21/08/2022
//
// Problem11 of Learning C++
// After Day31
// Name- Lots Of Accounts 2
// --------------------------------------


/*
There isn't much that we have to do this time, we just have to do some changes in the 
Problem10 file. It doesn't mean we can just copy, paste and edit, that should have been
done if this were some work thing, you'd have to save as much time as you can but here, 
it's training so do it from the start. There are just 4 things that you have to do-

1. Make Accounts an abstract class.
2. Add Printable Interface class.
3. Shorten the Utility functin with the help of dynamic polymorphism.
4. Test your code with both base class pointers and local objects.

Tip- Make virtual destructor like this-
virtual ~Class_name() = default; 

It tells the compiler to just generate a simple destructor. Now go.
*/
#include <iostream>
#include "Accounts.h"
#include "Savings_Acc.h"
#include "Checking_Acc.h"
#include "Trust_Acc.h"
#include <vector>
#include "Acc_Util.h"

int main()
{   
    std::vector<Account *> pokemon;
    
    Account *bulba = new Savings_Acc{"Bulbasaur", 20000, 7};
    bulba->deposit(2000);
    bulba->withdraw(30000);
    bulba->withdraw(20000);
    pokemon.push_back(bulba);
    Savings_Acc *drago = new Savings_Acc{"Dragonite", 25000};
    pokemon.push_back(drago);
    Account *doom = new Checking_Acc{"Houndoom", 50000};
    pokemon.push_back(doom);
    Checking_Acc *m_swamp = new Checking_Acc{"Mega Swampert", 40000};
    pokemon.push_back(m_swamp);
    Account *swine = new Trust_Acc{"Mamoswine", 45000, 5};
    pokemon.push_back(swine);
    Trust_Acc *vern = new Trust_Acc{"Noivern", 75000, 10};
    pokemon.push_back(vern);

    display(pokemon);
    mass_deposit(pokemon, 2000);

    for(size_t i {0}; i < 5; i++) {
        mass_withdraw(pokemon, 500);
    }

    delete bulba;
    delete drago;
    delete doom;
    delete m_swamp;
    delete swine;
    delete vern;
    

    return 0;
}