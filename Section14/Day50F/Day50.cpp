// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 27/03/2023
//
// Day50 Of Learning C++
// --------------------------------------

/*
== Stack ==

- Container Adapter.
- Last-in First-out (LIFO) data structure.

- Implemented as an adapter over other STL container. Can be implemented as a vector,
list, or deque. Is supports only those three because of it's LIFO structure. It can
be accessed from only one side, which you can call the top of the stack. Hence it can
only work with vector, list or deque, becuase they have the push and pop back method.

- All operations occur on one end of the stack (Top).
- No iterators are supported, since access is only to the top.

- Needs to include <stack>

== Queue == 

- Container Adapter
- First-in First-out (FIFO) data structure.

- Implemented as an adapter over other STL containers, just like stack. It can be implemented
as a deque or list. Not a vector this time, because Queue structure is FIFO that requires 
both front and back functionality, and vector lacks front functionality.

- Elements are pushed at the back and popped from the front.
- No iterators are supported.

- Needs to include <queue>
*/

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <queue>
#include <list>

void display(std::stack<int> stk) {
    // Displaying is a hassle since we can't access anything but the top.

    // We are accessing the top then popping it, accessing the new top and
    // repeating the process. And to not alter the original stack, we are 
    // not taking it as a reference and are copying it.

    std::cout << "[ ";
    while( !stk.empty() )
    {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << "]" << '\n';
}

void display(std::queue<int> que) {
    std::cout << "[ ";
    while ( !que.empty() ) 
    {
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << "]" << '\n';

    // We access front and not back because front is the one that later gets popped.
    // If we replace it with back, the display will just have the last element repeated.
}

int main() {

    std::cout << "===== Stack ===============\n";

    // Stacks are like adapters to other containers, so we have to enter them too.
    std::stack<int, std::vector<int>> books;
    // The first is the datatype and the second is the container it adapts.

    // When we don't give it a container, the default is a deque.
    std::stack<int> books2;
    display(books2);

    // Stack has very few methods.
    // Adds element. Remember LIFO: the element is added at the top of stack.
    books2.push(10);
    display(books2);

    books2.push(30); // Now, this is the new top.
    display(books2);

    // Returns reference to current top element.
    std::cout << "Top: " << books2.top() << '\n';

    // So we can also change value of top since it is a reference to top element.
    books2.top() = 50;
    std::cout << "Top: " << books2.top() << '\n';
    display(books2);


    books2.push(40); // New top.
    std::cout << "Top: " << books2.top() << '\n';
    display(books2);

    books2.pop(); // Removes the current top.
    std::cout << "Top: " << books2.top() << '\n';
    display(books2);

    // You know these two
    std::cout << "Books2 - Empty?: " << books2.empty() << '\n';
    std::cout << "Books - Empty?: " << books.empty() << '\n';
    std::cout << "Size: " << books2.size() << '\n';

    // There isn't any method to clear the stack, so we do this.

    while ( !books2.empty() ) 
    {
        books2.pop();
    }
    display(books2);



    std::cout << "===== Queue ===============\n";

    // Implementation is same as the stack
    // Without giving a container: Deque is the default.
    std::queue<int> books3;
    display(books3);

    // With a container.
    std::queue<int, std::list<int>> books4;

    // size and empty work the same.

    books3.push(10);
    display(books3);
    books3.push(30);
    display(books3);

    books3.pop();
    display(books3);

    books3.push(100);
    books3.push(40);
    books3.push(20);
    books3.push(50);

    display(books3);

    std::cout << "Front: " << books3.front() << '\n';
    std::cout << "Back: " << books3.back() << '\n';

    // Clearing queue is also same as stack.
    while ( !books3.empty() ) 
    {
        books3.pop();
    }
    display(books3);

    return 0;
    
}