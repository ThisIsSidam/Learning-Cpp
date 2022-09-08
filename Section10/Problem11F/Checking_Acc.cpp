#include "Checking_Acc.h"

Checking_Acc::Checking_Acc(std::string str, double num) 
    : Account{str, num} {};

void Checking_Acc::deposit(double n) {
    Account::deposit(n);
}

void Checking_Acc::withdraw(double n) {
    Account::withdraw(n+withdrawal_fee);
}

void Checking_Acc::print(std::ostream &os) const {
       os << "[ Checking: " << name << ": " << balance << " ]" << '\n';
}