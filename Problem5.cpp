// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 04/03/2022
//
// Problem5 Of Learning C++
// After Day14
// Name- Letter Pyramid
// --------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main()
{

    /* Get Input from the user, and make a pyramid out of it. Something like this-
    * Input = ABC
    * PYramid-
    * 
    *   A
    *  BAB
    * CBABC
    * 
    * Isn't that nice. YOU can alter it a bit, but don't make it look like it's something other than
    * a Pyramid.
    */


    string letters;
    cout << "Enter the letters for the Pyramid: ";
    cin >> letters;

    for (int i {0}; i < letters.size(); i++)
    {
        // Spaces In The Start
        for (int j {i + 1}; j < letters.size(); j++)
        {
            cout << "   ";
        }

        // Printing Letters Backwards
        for (int j {i}; j >= 0; j--)
        {
            cout << " " << letters.at(j) << " ";
        }

        // Printing Letters Onwards From the Second Element
        for (int j {1}; j <= i; j++)
        {
            cout << " " << letters.at(j) << " ";
        }
        
        cout << endl;
    }  

    return 0;

}