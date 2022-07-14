// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 18/03/2022
//
// Problem1 Of Learning C++
// After Day5
// Name - Frank Room Cleaning Service
// --------------------------------------

#include <iostream>
using namespace std;

int main()
{

    /*
    * Problem - Create a program for a room cleaning service, take input of how many rooms are to be cleaned.
    * Show prices, which are, 35$ for large room, and 25$ for small ones. Tax is 2%, also tell the total 
    * estimate will be valid for a 30days. Name of the service is - Frank Room Cleaning Service.
    */

    cout << "-------Welcome to Frank Room Cleaning Service-------" << endl;
    cout << "How many large rooms would you like cleaned: ";

    int LargeRoomNum;
    cin >> LargeRoomNum;

    cout << "How many small rooms would you like cleaned: ";

    int SmallRoomNum;
    cin >> SmallRoomNum;

    const float LargeRoomPrice {35.00};
    const float SmallRoomPrice {25.00};
    const float Tax {0.02};

    cout << "\nPrice of large room cleanup: $" << LargeRoomPrice << endl;
    cout << "Price of small room cleanup: $" << SmallRoomPrice << endl;
    cout << "Tax: " << Tax * 100 << "%" << endl;

    cout << "=========================================" << endl;

    float TotalTax {((SmallRoomNum * SmallRoomPrice) + (LargeRoomNum * LargeRoomPrice)) * Tax};    
    cout << "Total Estimate: $" << (SmallRoomNum * SmallRoomPrice) + (LargeRoomNum * LargeRoomPrice) + TotalTax << endl;
    cout << "Total Tax: $" << TotalTax << endl;

    cout << "This estimate is valid for only 30 days." << endl;
    

    return 0;

}