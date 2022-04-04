// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 26/03/2022
//
// Problem2 Of Learning C++
// After Day10
// Name- Cash Counter
// --------------------------------------

#include <iostream>
using namespace std;

int main()
{

    /*
    * The User has an amount of cash on them, and they want to know what will be the change of it. 
    * So, take input of user's cash amount and return the number of notes and coins to change it.
    * 
    * This program uses Indian currency, and notes and coins as of 2022.
    */

    int cash {};
    cout << "How much money do you have?: ";
    cin >> cash;

    int five_hundred_notes {cash/500};
    cash %= 500;

    int two_hundred_notes {cash/200};
    cash %= 200;

    int one_hundred_notes {cash/100};
    cash %= 100;

    int fifty_notes {cash/50};
    cash %= 50;

    int twenty_notes {cash/20};
    cash %= 20;

    int ten_notes {cash/10};
    cash %= 10;

    int five_coin {cash/5};
    cash %= 5;

    int two_coin {cash/2};
    cash %= 2;

    cout << "Needed change:" << endl;
    cout << "500 Rupees Notes- " << five_hundred_notes << endl;
    cout << "200 Rupees Notes- " << two_hundred_notes <<endl;
    cout << "100 Rupees Notes- " << one_hundred_notes << endl;
    cout << "50 Rupees Notes- " << fifty_notes << endl;
    cout << "20 Rupees Notes- " << twenty_notes << endl;
    cout << "10 Rupees Notes- " << ten_notes << endl;
    cout << "5 Rupees Coins- " << five_coin << endl;
    cout << "2 Rupees Coins- " << two_coin << endl;
    cout << "1 Rupees Coins- " << cash << endl;

    return 0;

}