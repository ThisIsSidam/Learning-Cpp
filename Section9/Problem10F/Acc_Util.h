#ifndef ACC_UTIL_H
#define ACC_UTIL_H
#include <vector>
#include "Accounts.h"

// Account class Utility Functions

void display(const std::vector<Account> &accounts);
void mass_deposit(std::vector<Account> &accounts, double amount);
void mass_withdraw(std::vector<Account> &accounts, double amount);

// Savings_Acc class Utility Functions

void display(const std::vector<Savings_Acc> &accounts);
void mass_deposit(std::vector<Savings_Acc> &accounts, double amount);
void mass_withdraw(std::vector<Savings_Acc> &accounts, double amount);

// Checking_Acc class Utility Functions

void display(const std::vector<Checking_Acc> &accounts);
void mass_deposit(std::vector<Checking_Acc> &accounts, double amount);
void mass_withdraw(std::vector<Checking_Acc> &accounts, double amount);

// Trust_Acc class Utility Functions

void display(const std::vector<Trust_Acc> &accounts);
void mass_deposit(std::vector<Trust_Acc> &accounts, double amount);
void mass_withdraw(std::vector<Trust_Acc> &accounts, double amount);

#endif