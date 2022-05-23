/*
.Simple smart pointer -Very efficient!

unique_ptr<T>
    . Points to an object of type T on the heap
    . It is unique - there can only be one unique_ptr<T> pointing to the object on the heap
    . Owns what it points to
    . Cannot be assigned or copied
    . CAN be moved
    . When the pointer is destroyed , what it points to is automatically destroyed

*/

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test
{
    friend ostream &operator<<(ostream &os, const Test &rhs);

private:
    int data;

public:
    Test() : data(0) { cout << "Test Constructor (" << data << " )" << endl; }
    Test(int data) : data{data} { cout << "Test Constructor (" << data << " )" << endl; }
    int getData() const { return data; }
    ~Test() { cout << "Test destructor (" << data << " )" << endl; }
};

ostream &operator<<(ostream &os, const Test &rhs)
{
    os << rhs.data;
    return os;
}

int main()
{
    // Test *t1 = new Test{1000};   // Using a raw pointer
    // delete t1;
    unique_ptr<Test> t1{new Test{100}};            // creating a unique_ptr to Test and initializing it with 100
    unique_ptr<Test> t2 = make_unique<Test>(1000); // same as above but with make_unique

    unique_ptr<Test> t3;
    t3 = move(t1); // move constructors moves the ownership to another. Here the ownership of t1 is moved to t3 and t1 points to null now.

    if (!t1)
    {
        cout << "t1 is null pointer" << endl;
    }
    vector<unique_ptr<Test>> tests;
    tests.push_back(make_unique<Test>(4));
    tests.push_back(make_unique<Test>(6));
    tests.push_back(make_unique<Test>(7));

    // for (auto test : tests)  // gives an error as it copies the pointer
    // {
    //     cout << *test << endl;
    // }

    for (const auto &test : tests)
    {
        cout << *test << endl;
    }

    return 0;
}