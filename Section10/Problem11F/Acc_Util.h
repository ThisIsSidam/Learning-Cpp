#ifndef ACC_UTIL_H
#define ACC_UTIL_H
#include <vector>
#include "Accounts.h"
#include "I_Printable.h"

void display(const std::vector<Account *> &accounts);
void mass_deposit(std::vector<Account *> &accounts, double amount);
void mass_withdraw(std::vector<Account *> &accounts, double amount);


#endif