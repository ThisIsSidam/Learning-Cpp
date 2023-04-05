// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 23/03/2023
//
// Day48 Of Learning C++
// --------------------------------------

/*
== Associative Container ==

- Collection of stored objects that allow fast retrieval using a key.
- STL provides Sets and Maps.
- Usually implemented as a balanced binary tree or hastsets.
- Most operations are very efficient.

= Types of sets =
- std::set
- std::unordered_set
- std::multiset
- std::unordered_multiset

= std::set = 

- Need to include <set>
- Similar to mathematical set.
- Ordered by key.
- No duplicate elements. 
- All iterators are available and invalidate when corresponding element is deleted.
- Supports assignment via initialisation list.
- Elements are ordered by default. 
- Direct element access is not allowed.

- Uses less-than "<" operator for ordering elements. So, if you make a 
set of a certain class, it should have the overloaded < operator. 

= std::multi_set =

- Include <set>
- Sorted by key.
- Allows duplicate elements.
- All iterators are available.

= std::unordered_set =

- Include <unordered_set>
- Elements are unordered.
- No duplicate element allowed.
- Elements can't be modified, you need to erase it and insert a new one.
- Reverse iterators are not allowed.

= std::unordered_multiset =

- Include <unordered_set>
- Elements are unordered.
- Allow duplicate elements
- No reverse iterators are allowed.

*/

#include <iostream>
#include <set>

void display(std::set<int> &st) {
    auto it = st.begin();

    std::cout << "[ ";
    while ( it != st.end() )
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "]\n";
}

int main() {

    std::set<int> s {2, 5, 3, 6, 7, 4, 3, 1, 2, 3};
    display(s); 
    // Elements are unorderd and contains duplicates but the actual set contains 
    // something different.

    std::cout << "Size: " << s.size() << '\n';
    std::cout << "Max Size: " << s.max_size() << '\n';
    std::cout << "Empty? : " << s.empty() << '\n';
    
    // Sets don't allow direct access to elements. So no .at method, index 
    // operator, not even .front or .back method. Hence we can't use
    // push/pop_front/back() method. We just have insert and also emplace.

    s.insert(8);
    // Insert doesn't require any iterators as the set will automatically place
    // it into appropriate position.
    display(s);

    // Insert comes with a lot of features. We can normally insert elements as 
    // we did above and we can also do this.

    auto result = s.insert(9);
    display(s);
    
    // The insert method returns a std::pair object. If you don't remember, pair
    // is an public class with two attributes, first and second. 
    
    // The first attribute of the pair object returned by insert is an iterator 
    // to the inserted element. 
    
    std::cout << "Inserted element: " << *(result.first) << '\n';

    // While the other is a bool telling us if the element was inserted 
    // successfully or not.  

    std::cout << "Element insertion: " << result.second << '\n';

    // Note: If element is already present, iterator to old version is returned 
    // as the new version is not added. Then we can say that the insertion failed,
    // hence the iterator will point to a value but the bool will return false.

    // Erasing doesn't require any iterators either
    s.erase(9);
    display(s);

    // We can also find and delete

    auto five = s.find(5);
    if ( five != s.end() ) 
    {
        s.erase(5);
    }    
    else 
    {
        std::cout << "Five not found\n"; 
    }
    display(s);

    // Find method of set class is different from the find function and it is 
    // preferred to use it as it knows the internals of the class. 

    std::cout << "Count 5: " << s.count(5) << '\n';
    // count returns the number of occurences of parameter but can only have 0 o 1
    // as a set can't have duplicate value. Hence, it is used to check presence of
    // element in set. Is used normally to count occurences in multiset as they 
    // can have multiple occurences.

    s.clear();
    // As usual, this one deletes all elements in set.
    display(s);


    return 0;
}