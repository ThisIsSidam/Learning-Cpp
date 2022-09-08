#ifndef SAVINGS_ACC_H
#define SAVINGS_ACC_H
#include "Accounts.h"

class Savings_Acc: public Account {

    private:
        static constexpr const char* null_name {"Anonymous Savings Account"};
        static constexpr double null_balance {0};
        static constexpr double null_rate{0};
    protected:
        int int_rate;
    
    public:
        Savings_Acc(std::string str = null_name, double num = null_balance, int rate = null_rate);

        virtual void deposit(double n) override;
        virtual void withdraw(double n) override;
        virtual ~Savings_Acc() = default;
        virtual void print(std::ostream &os) const override;
};

#endif