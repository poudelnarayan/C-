/*
Custom deleters

. Sometimes when we destroy a smart pointer  we need more than just to destroy the onject on the heap.
. These are special use-cases
. C++ smart pointers allow you to provide custom deleters
. Lots of way to achieve this
    .Functions
    .Lambdas
    .Others ...

*/

#include <iostream>
#include <memory>

using namespace std;

class Test
{
private:
    int data;

public:
    Test() : data(0) { cout << "Test Constructor (" << data << " )" << endl; }
    Test(int data) : data{data} { cout << "Test Constructor (" << data << " )" << endl; }
    int getData() const { return data; }
    ~Test() { cout << "Test destructor (" << data << " )" << endl; }
};

void my_deleter(Test *ptr)
{
    cout << "\tUsing my custom function deleter" << endl;
    delete ptr;
}

int main()
{
    {
        // Using a function
        shared_ptr<Test> ptr1{new Test{100}, my_deleter};
    }

    cout << "==========" << endl;

    {
        // Using a Lambda expression
        shared_ptr<Test> ptr2(new Test{100},
                              [](Test *ptr)
                              {
                                  cout << "\tusing my custom lamda deleter" << endl;
                                  delete ptr;
                              });
    }

    return 0;
}