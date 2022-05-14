/*
Copy/MOve constructors and overloaded operator=

.    Not onherited from the Base class
.    You may not need to provide you own
.       .Compiler-provided versions may be just fine
.    We can explicitly invoke the Base class versions from the Derived class

*/

#include <iostream>

using namespace std;

class Base
{
private:
    int value;

public:
    Base() : value{0} { cout << "Base no-args constructor" << endl; }
    Base(int x) : value{x} { cout << "Int base constructor" << endl; }
    Base(const Base &other) : value{other.value} { cout << "Base copy constructor" << endl; }
    Base &operator=(const Base &rhs)
    {
        cout << "Base Opeartor=" << endl;
        if (this == &rhs)
        {
            return;
        }
        value = rhs.value;
        return *this;
    }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base
{
private:
    int doubleValue;

public:
    Derived() : Base{} { cout << "Derived no-args constructor" << endl; }
    Derived(int x) : Base{x} { cout << "Int derived constructor" << endl; }
    Derived(const Derived &other) : Base(other), doubleValue{other.doubleValue} { cout << "Derived copy constructor" << endl; }
    Derived &operator=(const Derived &rhs)
    {
        cout << "Derived operator" << endl;
        if (this == &rhs)
        {
            return *this;
        }
        Base::operator=(rhs);
        doubleValue = rhs.doubleValue;
        return *this;
    }
    ~Derived() { cout << "Derived destructor" << endl; } 
};

int main()
{
    Base b{100}; // Overloaded constructor
    Base b1{b};  // copy constructor
    b = b1;      // copy assignment

    Derived d{100};
    Derived d1{d};
    d = d1;

    return 0;
}