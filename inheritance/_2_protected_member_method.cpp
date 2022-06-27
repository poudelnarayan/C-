/*
The protected class member modifier

class Base {

    protected:
    //protected  Base class members...
};

. Accessible from the Base class itself
. Accessible from classes Derives from Base
. Not accessible by objects of Base or Derived


*/

#include <iostream>

using namespace std;

class Base
{
    // Note friends of base have access to all
public:
    int a{0};
    void display() { cout << a << "," << b << "," << c << endl; }

protected:
    int b{0};

private:
    int c{0};
};

class Derived : public Base
{
    // Note friend of Derive have access to only what Derived has access to

    // a will be public
    // b will be protected
    // c will not be accessible
    void accessBaseMethod()
    {
        a = 100; // okay
        b = 200; // okay
        // c = 300; // not accessible
    }
};

int main()
{
    cout << "=== Base member access from base objects ===== " << endl;
    Base base;
    base.a = 100;
    // base.b = 200;  //Compiler error since protected
    // base.c = 300;  // Compiler error since private

    cout << "=== Base member access from derived objects =======" << endl;

    Derived d;
    d.a = 100; // Okay
    // d.b = 200;   // Error
    // d.c = 300;    // Error

    return 0;
}