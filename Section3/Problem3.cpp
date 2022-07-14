// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 29/03/2022
//
// Problem3 Of Learning C++
// After Day12
// Name- List Handler
// --------------------------------------

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{

    /*
    * You have a list. You have to show the user options, for printing the list, adding numbers in the list,
    * Finding the average, finding the smallest and the largest number, Search for a number. Also, don't allow
    * duplicates, and also allow an option to clear out the list, search it how to do that. And print out the
    * list everytime in square brackets.
    * Now Go!
    */

    vector <int> list {};

    int option {};
    do {
        cout << "\n1. Print out the list\n2. Add a number\n3. Find the average"
        "\n4. Find the smallest number\n5. Find the largest number\n6. Search for a number"
        "\n7. Clear the list\n8. Quit" << endl;

        cout << "\nChoose an option(1-8): ";
        cin >> option;
        switch (option){
            case 1:
            {
                if (list.size() != 0)
                {
                    cout << "[ ";
                    for (auto lis: list)
                        cout << lis << " ";
                    cout << "]" << endl;
                } 
                else
                    cout << "[] - The List is Empty." << endl;
            } break;

            case 2:
            {
                int new_number {};
                cout << "Enter the number you want to add: ";
                cin >> new_number;

                bool check {1};
                for (auto lis: list)
                {
                    if (lis == new_number)
                    {
                        cout << new_number << " Already Exists in the List." << endl;
                        check = 0;
                        break;
                    }
                }

                if (check)
                {
                    list.push_back(new_number);
                    cout << new_number << " added!" << endl;
                }
            } break;

            case 3:
            {
                int total {};

                for (auto lis: list)
                {
                    total += lis;
                }
                cout << total/list.size() << endl;

            } break;

            case 4:
            {
                int smallest {INT_MAX};
                
                for (auto lis: list)
                {
                    if (smallest > lis)
                        smallest = lis;
                }
                cout << "The Smallest Number is " << smallest << "." << endl;
            } break;

            case 5:
            {
                int largest {INT_MIN};

                for (auto lis: list)
                {
                    if (largest < lis)
                        largest = lis;
                }
                cout << "The Largest Number is " << largest << "." << endl;
            } break;

            case 6:
            {
                int search {};
                cout << "Enter the Number You Want to Search For: ";
                cin >> search;

                bool check {0};
                for (int i {0}; i < list.size(); i++)
                {
                    if (list.at(i) == search)
                    {
                        cout << "Number " << search << " is on the index " << i << "." << endl;
                        check = 1;   
                        break;
                    }
                }
                if (!check)
                    cout << "Number " << search << " is not Present in the List." << endl;
            } break;

            case 7:
            {
                list.clear();
                cout << "List is Cleared Out!" << endl;
            } break;

            case 8:
            {
                cout << "Goodbye..." << endl;
            } break;

        }       
   
    } while (option != 8);

    return 0;

}