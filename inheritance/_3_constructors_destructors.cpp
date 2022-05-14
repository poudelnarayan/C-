/*
Constructors and Destructors in inheritance

. A derived class inherits from its Base class

. The Base part of the Derived class MUST be initialized Before the Derived class is initialized.

. When a Derived object is created
    . Base class constructor executed then
    . Derived class constructor executes

*/

/*
Destructor

.   Class destructors are invoked in the reverse order as constructors
.   The derived part of the Derived class MUST be destroyed BEFORE the Base class destructor is invoked

. When a Derived object is destroyed
    . Derived class destructor executed then
    . Base class destructor executes
    . Each destructor should free resources allocated in it's own constructor

*/

/*
A Derived class does NOT inherit
    . Base class constructors
    . Base class destructor
    . Base class overloaded assignment operators
    . Base class friend function

However, the base class constructors,destructors, and overloaded assignment operators
can invoke the base-class versions

C++11 allows explicit inheritance of base 'non-special' constructors with
        . using Base::Base;  anywhere in the derived class declaration
        . Lots of rule involved, often better to define constructors yourself


*/

#include <iostream>

using namespace std;

class Base
{
private:
    int value;

public:
    Base() : value{0} { cout << "Base no-args constructors " << endl; }
    Base(int x) : value{x} { cout << "Base (int) overloaded constructor " << endl; }
    ~Base() { cout << "bBase destructor" << endl; }
};

class Derived : public Base
{
private:
    int doubledValue;

public:
    Derived() : doubledValue{0} { cout << "Derived no-args constructor" << endl; }
    Derived(int x) : doubledValue(x * 2) { cout << "Derived (int) overloaded constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};

int main()
{
    // Base b;
    // Base b{100};
    // Derived d;
    Derived d{1000};

    return 0;
}

/*
If i comment line 66 (overloaded constructor of derived class) and add "using Base:Base " above the member declaration
then the base's overloaded constructor will be called. And it will put the value of "value" to 1000 but doubled value will left unintialized.

*/