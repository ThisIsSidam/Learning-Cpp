// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 31/03/2022
//
// Problem Of Learning C++
// After Day14
// Name- Substition Cipher
// --------------------------------------

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    /*
    * You have to first ask if the user wants to encrypt or decrypt a substitute. Then do so.
    * Have two strings, first of normal abc letters, and second of the replacement of those letters.
    * And switch them for encrypting and decrypting.
    */

    string alphabets {" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
    string substitute {"zyxwvustrpqonmlkjihgfedcba0987654321ZYXWVUTSRQPONMLKJIHGFEDCBA "};

    int choice {};

    do{
        cout << "\nWhat do you want to do?\n1. Encrypt message\n2. Decrypt message\n3. Quit" << endl;
        cout << "\nChoose your option(1/2/3): ";
        cin >> choice;
        cin.ignore();

        string secret_message;

        if (choice == 1)
        {
            cout << "Enter the message to Encrypt: ";
            getline(cin, secret_message);

            string encrypted;

            for (size_t i {0}; i < secret_message.size(); i++)
            {
                for (size_t j {0}; j < alphabets.size(); j++)   
                {
                    if (secret_message.at(i) == alphabets.at(j))
                        encrypted += substitute.at(j);
                }
            }
            cout << "Encrypted message: " << encrypted << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter the message to decrypt: ";
            getline(cin, secret_message);

            string decrypted;

            for (size_t i {0}; i < secret_message.size(); i++)
            {
                for (size_t j {0}; j < substitute.size(); j++)
                {
                    if (secret_message.at(i) == substitute.at(j))
                        decrypted += alphabets.at(j);
                }
            }
            cout << "Decrypted message: " << decrypted << endl;
        }
        else if (choice == 3)
        {
            cout << "Goodbye...." << endl;
        }
        else 
        {
            cout << "You sure you entered 1, 2 or 3. Check again!" << endl;
        }
    } while (choice != 3);
    
    return 0;

}