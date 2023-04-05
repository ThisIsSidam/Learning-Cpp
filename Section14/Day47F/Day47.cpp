// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 21/03/2023
//
// Day47 Of Learning C++
// --------------------------------------

/*
== List and Forward List ==
- Sequence containers 
- Store data in non-contiguous memory. 
- Can't directly access the elements with the .at() method or the index operator. 
- Very efficient for inserting and deleting elements once they're found.

= List =
- Need to include <list>

- Dynamic Size
- Bidirectional (Doubly Linked)
- Rapid insertion and deletion of elements anywhere in the container (constant time), 
once we get an iterator to an element.
- All iterators available and invalidate when corresponding element is deleted.

- Referred to as doubly linked list because elements stored in lists are stored in 
non-continuous memory but one element is linked to the next one and the next one 
is linked to the prior one and this goes on. 

Like this: 1 >< 2 >< 3
Suppose the (><) are arrows aiming at eachother.

- Since it is a doubly linked list, if we take an iterator to a list element, we can
increment the iterator as well as decrement it.

- first and last elements can be accessed by .front and .back.
- Also support assignaton via initialiser list.

= Forward List = 
- Need to include <forward_list>

- Dynamic Size
- uni-directional (Singly-linked)
- Rapid insertion and deletion of elements anywhere in the container (contant time), 
once we get an iterator to an element.
- Reverse iterators are not available as it is uni-directional.
- Iterators invalidate when corresponding element is deleted.

- Referred to as singly-linked list because elements stored in lists are stored in
non-continuos memory and one element is linked to the next one but not the other way
around. 

Like this: 1 > 2 > 3
Think of the symbols as arrows.

- Only first element is accessible with .front, and .back doesn't work.
*/

#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>

// To display both list and f_list
template <typename T>
void display(T &l) {

    // Traversing the list is a bit different as we can't directly access the elements.
    // We take an iterator and dereference it, then increase it, then dereference it
    // again. And keep it going until we reach the end.

    std::cout << "[ ";
    for ( auto it = l.begin(); it != l.end(); it++) 
    {   
        std::cout << *it << " ";
    }
    std::cout << "]\n";
}

int main() {

    std::cout << "===== List ===================\n";

    std::list<int> ls {1, 2, 3, 4};
    display(ls);

    std::cout << "Size: " << ls.size() << '\n';
    std::cout << "Max Size: " << ls.max_size() << '\n';
    std::cout << "Front element: " << ls.front() << '\n';
    std::cout << "Back element: " << ls.back() << '\n';

    ls.push_back(5); // 1 2 3 4 5
    ls.push_front(0); // 0 1 2 3 4 5 
    display(ls);

    ls.pop_back(); // 0 1 2 3 4 
    ls.pop_front(); // 1 2 3 4 
    display(ls);

    // emplace_back and emplace_front also work

    // insert works a little differently with lists.
    
    auto it = std::find(ls.begin(), ls.end(), 4);

    // Adds an element before the element pointed by the iterator.
    ls.insert(it, 6); // 1 2 3 6 4
    display(ls);
    ls.erase(it); // 1 2 3 6 The iterator becomes invalid now.
    display(ls);
    ls.resize(3); // 1 2 3
    display(ls);
    ls.resize(10); // 1 2 3 0 0 0 0 0 0 0 
    display(ls);
    // When adding new elements, compiler uses the default initialisers, 0 in int's case.
    // This isn't the end. There are loads more. Even some that we used before but not
    // with this. Like, clear. There's also




    std::cout << "===== Forward List ===============\n";

    std::forward_list<int> fls {1, 2, 3, 4};
    display(fls);

    // Size method is not supported.
    std::cout << "Max Size: " << fls.max_size() << '\n';
    std::cout << "Front element: " << fls.front() << '\n';
    // Back method is not suppported.

    fls.push_front(0); // 0 1 2 3 4 
    // push_back is not supported
    display(fls);

    fls.pop_front(); // 1 2 3 4 
    // pop_back is not supported
    display(fls);

    // emplace front is supported but emplace back is not.

    // But we have these new methods.

    auto it2 = std::find(fls.begin(), fls.end(), 3);

    fls.insert_after(it2, 10);
    // emplace_after also exist to directly insert element with constructor parameters.
    display(fls);

    fls.erase_after(it2);
    display(fls);
    // Erases the element after it, meaning the one we added, so this doesn't invalidate
    // the iterator.

    // Resize works the same as list.

    return 0;
}
