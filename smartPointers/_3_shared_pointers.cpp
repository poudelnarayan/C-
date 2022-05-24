/*
shared_ptr

. Provides shared ownership of heap objects

. shared_ptr<T>
    . Points to an object of type T on the heap
    . It is not unique - there can  be many shared_ptrs pointing to the smae object on the heap
    . Establishes shared ownership relationship
    . CAN be assigned and copied
    . CAN be moved
    . Does'nt support managing arrays by default
    . When the use count is Zero, the managed object on the heap is destroyed

*/

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // use_count gives the number of shared_ptr objects managing the heap object
    shared_ptr<int> p1{new int{100}};
    cout << "Use count" << p1.use_count() << endl;

    shared_ptr<int> p2{p1}; // Shared ownership
    cout << "Use count" << p1.use_count() << endl;

    p1.reset(); // decrement the use_count ; p1 is nulled out
    cout << "Use count" << p1.use_count() << endl;
    cout << "Use count" << p2.use_count() << endl;

    return 0;
}