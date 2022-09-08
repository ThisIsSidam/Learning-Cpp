#include "Savings_Acc.h"

Savings_Acc::Savings_Acc(std::string str, double num, int rate)
    : Account{str, num}, int_rate{rate} {};

void Savings_Acc::deposit(double n) {
    Account::deposit(n+(n/100*int_rate));
}

void Savings_Acc::withdraw(double n) {
    Account::withdraw(n);
    
}

void Savings_Acc::print(std::ostream &os) const {
       os << "[ Savings: " << name << ": " << balance << ": " << int_rate << "% ]" << '\n';
}
