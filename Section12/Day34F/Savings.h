#ifndef SAVINGS_H
#define SAVINGS_H

// Exception Classes
class IllegalBalanceException {};
class NegativeBalanceException {};
class TooMuchMoneyException {}; // As a joke, don't name like this.

class Savings_Acc {
    int balance;
    public:
        Savings_Acc(int num) : balance{num} {
            if(balance == 0) {
                throw IllegalBalanceException();
            }
            if(balance < 0) {
                throw NegativeBalanceException();
            }
            if(balance > 990000000) {
                throw TooMuchMoneyException(); // Too test out the Catch All Handler.
            }
        }
        ~Savings_Acc() = default;

        void display_balance() { std::cout << "Balance: " << balance << '\n'; }
};






#endif