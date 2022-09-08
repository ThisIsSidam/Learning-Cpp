// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 09/08/2022
//
// Problem10 of Learning C++
// After Day29
// Name- Lots Of Accounts
// --------------------------------------

/*
This time we have to create four types of account classes, one the Account Class,
Savings Account, Checking Account and Trust Account. Which  class will be derived by 
which class is up to you to decid
e. Things that you have to add in the classes are-

Account- Name, Balance

Savings Acc- Name, Balance, Interest Rate (That much interest gets added per deposit)

Checking Acc- Name, Balance and a withdrawal fee of 1.50$ per withdrawal

Trust Acc- Name, Balance, Interest Rate, Any deposit of $5000.00 or more gets flat $50 
Bonus, the deposit function works just like of savings account, and only 3 withdrawal 
of less than 20% of balance is allowed per year.

Also, you have to create another file that will be the utility file that has functions 
by which we can see all the accounts at once. What you have to do is add all the objects
created into a vector and just show that vector. Now Go!
*/

#include <iostream>
#include "Accounts.h"
#include "Acc_Util.h"
#include <vector>

int main()
{
    std::cout << "=====Account Section=========================" << '\n';
    std::vector<Account> thor_villains;
    thor_villains.push_back(Account{});
    thor_villains.push_back(Account{"Hela", 200});
    thor_villains.push_back(Account{"Surtur", 5500});

    display(thor_villains);
    mass_deposit(thor_villains, 1000);
    mass_withdraw(thor_villains, 1200);

    std::cout << "\n=====Savings Account Section===============" << '\n';
    std::vector<Savings_Acc> ironman_villains;
    ironman_villains.push_back(Savings_Acc{});
    ironman_villains.push_back(Savings_Acc{"Mandarin", 4000});
    ironman_villains.push_back(Savings_Acc{"Iron Monger", 10000, 5});

    display(ironman_villains);
    mass_deposit(ironman_villains, 1000);
    mass_withdraw(ironman_villains, 5000);

    std::cout << "\n=====Checking Accout Section====================" << '\n';
    std::vector<Checking_Acc> capamerica_villains;
    capamerica_villains.push_back(Checking_Acc{});
    capamerica_villains.push_back(Checking_Acc{"Red Skull", 2000});
    capamerica_villains.push_back(Checking_Acc{"Zemo", 8000});

    display(capamerica_villains);
    mass_deposit(capamerica_villains, 2000);
    mass_withdraw(capamerica_villains, 4000);

    std::cout << "\n=====Trust Account Section=========================" << '\n';
    std::vector<Trust_Acc> hulk_villains;
    hulk_villains.push_back(Trust_Acc{});
    hulk_villains.push_back(Trust_Acc{"Abomination", 3000});
    hulk_villains.push_back(Trust_Acc{"The Leader", 9000, 6});

    display(hulk_villains);
    mass_deposit(hulk_villains, 1500);
    mass_withdraw(hulk_villains, 500);
    mass_withdraw(hulk_villains, 100);
    mass_withdraw(hulk_villains, 100);
    mass_withdraw(hulk_villains, 100);
    
    return 0;
}