/*
Data hiding is a fundamental concept of object-oriented programming.
It restricts the access of private members from outside of the class.

Similarly, protected members can only be accessed by derived classes and are inaccessible from outside.

However, there is a feature in C++ called friend functions that break this rule and
allow us to access member functions from outside the class.

*/

#include <iostream>

using namespace std;

class Distance
{
    int meter;
    friend int addFive(Distance); // friend function
    // addFive is a friend function that can access both provate and public data members.
public:
    Distance() : meter(0) {}
};

// friend function definition
int addFive(Distance d)
{
    // accessing friend members from the friend function
    d.meter += 5;
    return d.meter;
}

int main()
{
    Distance D;
    cout << "Distance: " << addFive(D);
    return 0;
}