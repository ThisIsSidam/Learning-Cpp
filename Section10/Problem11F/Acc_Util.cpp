#include "Acc_Util.h"

void display(const std::vector<Account *> &accounts) {
    
    std::cout << "\n=====Accounts Display=========================" << '\n';
    for(auto acc: accounts) {
        std::cout << *acc;
    }
}

void mass_deposit(std::vector<Account *> &accounts, double amount) {

    std::cout << "\n=====Accounts Deposits====================" << '\n';
    for(auto &acc: accounts) {
        acc->deposit(amount);
    }
}

void mass_withdraw(std::vector<Account *> &accounts, double amount) {

    std::cout << "\n=====Accounts Withdrawals==========" << '\n';
    for(auto &acc: accounts) {
        acc->withdraw(amount);
    }
}
