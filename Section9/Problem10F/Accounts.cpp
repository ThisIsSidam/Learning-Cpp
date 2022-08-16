#include "Accounts.h"

std::ostream& operator<<(std::ostream &os, const Account &obj) {
    os << "Name: " << obj.name << " Balance: " << obj.balance;
    return os;
}

Account::Account(std::string str, double num) 
    : name{str}, balance{num} {};

void Account::deposit(double n) {
    balance += n;
    std::cout << n << " is deposited in " << name << "'s account! Balance: " << balance << '\n';
}

void Account::withdraw(double n) {
    if(n <= balance) {
        balance -= n;
        std::cout << n << " is withdrawn from " << name << "'s account! Balance: " << balance << '\n';
    }
    else {
        std::cout << "Insufficient Balance! Withdrawal Amount: " << n << " Balance: " << balance << '\n';
    }
}

Savings_Acc::Savings_Acc(std::string str, double num, int rate)
    : Account{str, num}, int_rate{rate} {};

void Savings_Acc::deposit(double n) {
    Account::deposit(n+(n/100*int_rate));
}

Checking_Acc::Checking_Acc(std::string str, double num) 
    : Account{str, num} {};

void Checking_Acc::withdraw(double n) {
    Account::withdraw(n+1.5);
}

Trust_Acc::Trust_Acc(std::string str, double num, int rate) 
    : Savings_Acc{str, num, rate} {};

void Trust_Acc::deposit(double n) {
    if(n>5000.00) {
        Account::deposit(50.00);
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
            std::cout << "Withdrawal Amount: " << n << " Withdrawal Failed! Amount Exceeds 20% of Balance!" << '\n';
        }
    }
    else {
        std::cout << "Withdrawal Amount: " << n << " You have already withdrawn 3 times this year!" << '\n';
    }
}

