#include "Accounts.h"

Account::Account(std::string str, double num) 
    : name{str}, balance{num} {};

void Account::deposit(double n) {
    balance += n;
    std::cout << n << " is deposited in " << name << "'s account!" << *this;
}

void Account::withdraw(double n) {
    if(n <= balance) {
        balance -= n;
        std::cout << n << " is withdrawn from " << name << "'s account!" << *this;
    }
    else {
        std::cout << "Insufficient Balance! Withdrawal Amount: " << n << ". " << *this;
    }
}

void Account::print(std::ostream &os) const {
    os << "[ Account: " << name << ": " << balance << " ]" << '\n';
}




