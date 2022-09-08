#ifndef TRUST_ACC_H
#define TRUST_ACC_H
#include "Savings_Acc.h"

class Trust_Acc: public Savings_Acc {
    
    private:
        static constexpr const char* null_name {"Anonymous Trust Account"};
        static constexpr double null_balance {0};
        static constexpr double null_rate {0};
        static constexpr double bonus_threshhold {5000};
        static constexpr double withdrawal_bonus {50};
    
    protected:
        int withdrawal_counter;

    public:
        Trust_Acc(std::string str = null_name, double num = null_balance, int rate= null_rate);
        virtual void deposit(double n) override;
        virtual void withdraw(double n) override;
        virtual void print(std::ostream &os) const override;
};

#endif