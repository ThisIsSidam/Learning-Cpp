// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 09/04/2022
//
// Problem6 Of Learning C++
// After Day16
// Name- List Handler 2
// --------------------------------------

// You have to do exactly what you did in the List Handler problem, just use fns this time. And ya, don't
// use Globals vars/vectors in this, Okay!

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;

void show_menu ();
void print_list (const vector<int> &);
void add_num (vector<int> &);
double find_average (const vector<int> &);
int smallest_num (const vector<int> &);
int largest_num (const vector<int> &);
int search_num (const vector<int> &);
void clear_list (vector<int> &);

int main()
{

    vector <int> list {};
    int choice {};

    cout << fixed << setprecision(2);

    do{
        show_menu();
        cin >> choice;

        if (choice == 1)
            print_list(list);
        
        else if (choice == 2)
            add_num(list);

        else if (choice == 3)
            cout << find_average(list) << endl;

        else if (choice == 4)
            cout << smallest_num(list) << endl;
        
        else if (choice == 5)
            cout << largest_num(list) << endl;

        else if (choice == 6)
            cout << search_num(list) << endl;
        
        else if (choice == 7)
            clear_list(list);
        
        else if (choice == 8)
            cout << "GoodBye....." << endl;

        else 
            cout << "Undefind Input!!" << endl;
            

    } while(choice != 8);
    

    return 0;

}

void show_menu ()
{
    cout << "\n1. Print Out The List\n2. Add A Number\n3. Find The Average"
    "\n4. Find The Smallest Number\n5. Find The Largest Number\n6. Search For A Number"
    "\n7. Clear The List\n8. Quit\n\nEnter Your Choice: ";
}

void print_list (const vector<int> &the_list)
{
    if (the_list.size() == 0)
        cout << "[] - List is Empty" << endl;
    
    else 
    {
        cout << "[ ";
        for (auto list_element: the_list)
            cout << list_element << " ";
        cout << "]";
    }
}

void add_num (vector<int> &the_list)
{
    int new_num {};
    cout << "Enter The Number You Want To Add: ";
    cin >> new_num;

    bool check {1};
    for (auto i: the_list)
    {
        if (new_num == i)
            check = 0;
            break;
    }
    
    if (check == 1)
    {
        the_list.push_back(new_num);
        cout << new_num << " Is Added To The List!" << endl;
    }
    else
        cout << "The Number Is Already Present!" << endl;
}

double find_average (const vector<int> &the_list)
{   
    double total {}, average {};
    if (the_list.size() != 0)
    {
        for (auto i: the_list)
            total += i;
    
        average = total/the_list.size();
        cout << "The Average Is: ";
        return average;
    }

    else
    {
        cout << "[] - The List Is Empty! Code: ";
        return -1;
    }
}

int smallest_num (const vector<int> &the_list)
{
    int smallest {INT_MAX};
    if (the_list.size() != 0)
    {
        for (auto i: the_list)
        {
            if (smallest > i)
                smallest = i;
        }
        cout << "The Smallest Number Is: ";
        return smallest;
    }
    else
    {
        cout << "[] - The List Is Empty! Code: ";
        return -1;
    }
}

int largest_num (const vector<int> &the_list)
{
    int largest {INT_MIN};
    if (the_list.size() != 0)
    {
        for (auto i: the_list)
        {
            if (largest < i)
                largest = i;
        }
        cout << "The Largest Number Is: ";
        return largest;
    }
    else
    {
        cout << "[] - The List Is Empty! Code: ";
        return -1;
    }
}

int search_num (const vector<int> &the_list)
{
    int search {};
    cout << "Enter The Number You Want To Search: ";
    cin >> search;

    if (the_list.size() != 0)
    {
        for (size_t i {0}; i < the_list.size(); i++)    
        {
            if (search == the_list.at(i))
            {
                cout << "The Number You're Searching Is At Index: ";
                return i;
            }
        }
        cout << "The Number You're Searching For Is Not Found! Code: ";
        return -1;
    }
    else
    {
        cout << "[] - The List Is Empty! Code: ";
        return -1;
    }
}

void clear_list (vector<int> &the_list)
{
    the_list.clear();
    cout << "The List Is Now Cleared!" << endl;
}