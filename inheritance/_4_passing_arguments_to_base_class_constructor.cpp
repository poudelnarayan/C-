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
    // explicitly calling base class's no args constructor
    Derived() : Base{}, doubledValue{0} { cout << "Derived no-args constructor" << endl; }
    // explicitly calling base class's overloaded constructor
    Derived(int x) : Base{x}, doubledValue(x * 2) { cout << "Derived (int) overloaded constructor" << endl; }
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