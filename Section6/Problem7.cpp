// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 24/04/2022
//
// Problem7 Of Learning C++
// After Day18
// Name- List Multiplier
// --------------------------------------

/*
* This time you have to create a program that asks the user for two lists and gives back the
* multiplication of both the lists. Do it the way we multiply (3, 5)*(5, 3, 3). Also, the lists should be
* arrays and not vectors. Do it all using Arrays and what you learned in Day17 and Day18.
*/

#include <iostream>
using namespace std;

void element_collector(int[], const int&);
void print_list(const int[], const int&);
int *list_multiplier(const int[], const int[], const int&, const int&);

int main()
{
    int listA_size {}, listB_size {};
    cout << "Enter the Size of Both the Lists Separated by a Space: ";
    cin >> listA_size >> listB_size;

    int listA[listA_size] {};
    int listB[listB_size] {};

    cout << "Enter the Elements of First List Separated by a Space: ";
    element_collector(listA, listA_size);
    cout << "Enter the Elements of Second List Separated by a Space: ";
    element_collector(listB, listB_size);    

    cout << "First List: ";
    print_list(listA, listA_size);
    cout << "Second List: ";
    print_list(listB, listB_size);

    int *listC {nullptr};
    listC = new int[listA_size*listB_size];
    listC = list_multiplier(listA, listB, listA_size, listB_size);

    cout << "Product List: ";
    print_list(listC, listA_size*listB_size);

    delete [] listC;
}

void element_collector(int list[], const int &size)
{
    for(size_t i {0}; i< size; i++)
    {
        cin >> list[i];
    }
} 

void print_list(const int list[], const int &size)
{   
    cout << "[ ";
    for(size_t i {0}; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << "]" << endl;
}

int *list_multiplier(const int list1[], const int list2[], const int &size1, const int &size2)
{
    int *list3_ptr {nullptr};
    list3_ptr = new int[size1 * size2];

    int x {0};

    for (size_t i {0}; i < size1; i++)
    {
        for (size_t j {0}; j < size2; j++)
        {
            list3_ptr[x] = list1[i] * list2[j];
            x++;
        }
    }

    return list3_ptr;
}