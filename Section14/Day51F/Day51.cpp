// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 27/03/2023
//
// Day51 Of Learning C++
// --------------------------------------

/*
== Priority_Queue ==

- Allows insertions and removal of elements in order from the front of the container.

- Elements are stored internally as a vector by default. But a data structure called
Heap is used behind the scenes. (This Heap is different front Heap data structure).

- Elements are inserted in priority order. Largest value is always at the top.
- No iterators are supported.

- Needs to include <queue>
- Uses Lessthan (<) operator to sort elements, so any class that we are gonna use 
with this, needs to have this.
*/

#include <iostream>
#include <queue>

void display(std::priority_queue<int> p) {

    std::cout << "[ ";
    while (!p.empty() ) 
    {
        std::cout << p.top() << " ";
        p.pop();
    }
    std::cout << "]\n";
}

int main() {

    std::priority_queue<int> pq;
    display(pq);

    // Push inserts elements in sorted order. 
    pq.push(10);
    display(pq);

    pq.push(20);
    pq.push(5);
    pq.push(5); // Priority Queue can have duplicates.
    pq.push(2);
    display(pq);

    // Top shows the topmost element, and since they are all sorted, top shows greatest 
    // value element.
    std::cout << "Top: " << pq.top() << '\n';
    
    // Pop removes the topmost/largest value.
    pq.pop();
    std::cout << "Top: " << pq.top() << '\n';
    display(pq);

    std::cout << "Size: " << pq.size() << '\n';


    // Cleraing is also same as stack and queue.
    while ( !pq.empty() )
    {
        pq.pop();
    }
    display(pq);


    return 0;
}