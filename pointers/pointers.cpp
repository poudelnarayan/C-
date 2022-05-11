#include <iostream>

using namespace std;

int main()
{
    int a = 5;

    int *p{&a};
    cout << "address of a is: " << &a << endl;
    cout << "Address that is stored in P is : " << p << endl;
    cout << "Value of p is : " << *p << endl;  // value that is stored in p or value that a pointer is pointing to..
    cout << "Address of p is: " << &p << endl; // address of p
    cout << "Sizeof p is: " << sizeof p << endl;
    p = nullptr;
    cout << "value of p is: " << p << endl;
    cout << "address of p is: " << &p << endl;

    return 0;
}

// int *p ===> means that p can hold values that are the addresses of integers
// always initialize pointers
//  each pointer variables point to different types and  can hold addresses of variables of the type they point to
// there is difference between size of pointer and the size of variable it points to
// pointer has its own address too, as it an another variable.
// address of pointer is given by &pointer_name
// value of pointer( value pointed by a pointer ) is given by *pointer_name i.e deferencing a pointer.
//  address of value that a pointer is pointing to is given by pointer_name;