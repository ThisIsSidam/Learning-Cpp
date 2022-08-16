#include "Acc_Util.h"

void display(const std::vector<Account> &accounts) {
    
    std::cout << "\n=====Accounts Display=========================" << '\n';
    for(auto &acc: accounts) {
        std::cout << acc << '\n';
    }
}

void mass_deposit(std::vector<Account> &accounts, double amount) {

    std::cout << "\n=====Account Class Deposits====================" << '\n';
    for(auto &acc: accounts) {
        acc.deposit(amount);
    }
}

void mass_withdraw(std::vector<Account> &accounts, double amount) {

    std::cout << "\n=====Account Class Withdrawals==========" << '\n';
    for(auto &acc: accounts) {
        acc.withdraw(amount);
    }
}

void display(const std::vector<Savings_Acc> &accounts) {
    
    std::cout << "\n=====Savings Accounts Display===============" << '\n';
    for(auto &acc: accounts) {
        std::cout << acc << '\n';
    }
}

void mass_deposit(std::vector<Savings_Acc> &accounts, double amount) {

    std::cout << "\n=====Savings Accounts Deposits===============" << '\n';
    for(auto &acc: accounts) {
        acc.deposit(amount);
    }
}

void mass_withdraw(std::vector<Savings_Acc> &accounts, double amount) {

    std::cout << "\n=====Savings Accounts Withdrawals==========" << '\n';
    for(auto &acc: accounts) {
        acc.withdraw(amount);
    }
}

void display(const std::vector<Checking_Acc> &accounts) {
    
    std::cout << "\n=====Checking Accounts Display===============" << '\n';
    for(auto &acc: accounts) {
        std::cout << acc << '\n';
    }
}

void mass_deposit(std::vector<Checking_Acc> &accounts, double amount) {

    std::cout << "\n=====Checking Accounts Deposits===============" << '\n';
    for(auto &acc: accounts) {
        acc.deposit(amount);
    }
}

void mass_withdraw(std::vector<Checking_Acc> &accounts, double amount) {

    std::cout << "\n=====Checking Accounts Withdrawals==========" << '\n';
    for(auto &acc: accounts) {
        acc.withdraw(amount);
    }
}

void display(const std::vector<Trust_Acc> &accounts) {
    
    std::cout << "\n=====Trust Accounts Display===============" << '\n';
    for(auto &acc: accounts) {
        std::cout << acc << '\n';
    }
}

void mass_deposit(std::vector<Trust_Acc> &accounts, double amount) {

    std::cout << "\n=====Trust Accounts Deposits===============" << '\n';
    for(auto &acc: accounts) {
        acc.deposit(amount);
    }
}

void mass_withdraw(std::vector<Trust_Acc> &accounts, double amount) {

    std::cout << "\n=====Trust Accounts Withdrawals==========" << '\n';
    for(auto &acc: accounts) {
        acc.withdraw(amount);
    }
}