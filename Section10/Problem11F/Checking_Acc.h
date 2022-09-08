#ifndef CHECKING_ACC_H
#define CHECKING_ACC_H
#include "Accounts.h"

class Checking_Acc: public Account {
    
    private:
        static constexpr const char* null_name {"Anonymous Checking Account"};
        static constexpr double null_balance {0};
        static constexpr double withdrawal_fee {1.5};

    public:
        Checking_Acc(std::string str = null_name, double num = null_balance);
        virtual void deposit(double n) override;
        virtual void withdraw(double n) override;
        virtual void print(std::ostream &os) const override;
};

#endif