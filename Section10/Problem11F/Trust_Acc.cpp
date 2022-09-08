#include "Trust_Acc.h"

Trust_Acc::Trust_Acc(std::string str, double num, int rate) 
    : Savings_Acc{str, num, rate}, withdrawal_counter{0} {};

void Trust_Acc::deposit(double n) {
    if(n>bonus_threshhold) {
        Account::deposit(withdrawal_bonus);
    }
    Savings_Acc::deposit(n);
}

void Trust_Acc::withdraw(double n) {
    if (withdrawal_counter < 3) {
        if( n < balance/100*20) {
            Account::withdraw(n);
            withdrawal_counter++;
        }
        else {
            std::cout << "Withdrawal Amount: " << n << " Withdrawal Failed! Amount Exceeds 20% of Balance!" << *this;
        }
    }
    else {
        std::cout << "Withdrawal Amount: " << n << " You have already withdrawn 3 times this year!" << *this;
    }
}

void Trust_Acc::print(std::ostream &os) const {
    os << "[ Trust: " << name << ": " << balance << ": " << int_rate << "% " << "| Withdrawals: " << withdrawal_counter << " ]" << '\n';
}

