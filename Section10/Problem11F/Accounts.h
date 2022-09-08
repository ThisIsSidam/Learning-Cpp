#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <string>
#include <iostream>
#include "I_Printable.h"

class Account : public I_Printable{

    protected:
        std::string name;
        double balance;

    public:
        Account(std::string str, double num);

        void get_name() { std::cout << name << '\n';};
        int get_balance() { return balance;};
        void set_name(char str) { name = str; };
        
        virtual void deposit(double n) = 0;
        virtual void withdraw(double n) = 0;
        virtual void print(std::ostream &os) const override;

        virtual ~Account() = default;
};




#endif