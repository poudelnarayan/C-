/*
weak_ptr

.   Provides a non-owning "weak" refrence

. weak_ptr<T>
    . Points to an object of type T on the heap
    . Does not participate in owning relationship
    . Always created from a shared_ptr
    . Does NOT increment or decrement refrence use count
    . Used to prevent strong refrence cycles which could prevent objects from being deleted

*/

#include <iostream>
#include <memory>

using namespace std;

class B; // forward declaration

class A
{
    shared_ptr<B> b_ptr;

public:
    void set_B(shared_ptr<B> &b)
    {
        b_ptr = b;
    }
    A() { cout << " A Constructor" << endl; }
    ~A() { cout << "A destructor" << endl; }
};

class B
{
    // shared_ptr<A> a_ptr;  // this will not call destructor as both the class shares the pointer and use_count is never zero
    // hence there will be a memory leak . Hence use a weak pointer
    weak_ptr<A> a_ptr;

public:
    void set_A(shared_ptr<A> &a)
    {
        a_ptr = a;
    }
    B() { cout << "B constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};

int main()
{
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);
    b->set_A(a);

    return 0;
}