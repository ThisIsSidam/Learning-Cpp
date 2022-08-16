#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <string>
#include <iostream>

class Account {

    friend std::ostream& operator<< (std::ostream &os, const Account &obj);

    protected:
        std::string name;
        double balance;

        static constexpr const char* null_name {"Anonymous"};
        static constexpr double null_balance {0};

    public:
        Account(std::string str = null_name, double num = null_balance);

        void get_name() { std::cout << name << '\n';};
        int get_balance() { return balance;};
        void set_name(char str) { name = str; };
        
        void deposit(double n);
        void withdraw(double n);
};

class Savings_Acc: public Account {

    protected:
        int int_rate;
        static constexpr int null_rate {0};
    
    public:
        Savings_Acc(std::string str = null_name, double num = null_balance, int rate = null_rate);

        void deposit(double n);
};

class Checking_Acc: public Account {
    public:
        Checking_Acc(std::string str = null_name, double num = null_balance);
        void withdraw(double n);
};

class Trust_Acc: public Savings_Acc {
    
    private:
        int withdrawal_counter = 0;

    public:
        Trust_Acc(std::string str = null_name, double num = null_balance, int rate= null_rate);
        void deposit(double n);
        void withdraw(double n);
};

#endif