/*
                POLYMORPHISM

    COMPILE TIME                    RUN-TIME

    1> Function Overloading         1> Function Overriding
    2> Operator Overloading

*/

#include <iostream>

using namespace std;

class Base
{
public:
    void sayHello() const
    {
        cout << "Hello-I'm a Base class object" << endl;
    };
};

class Derived : public Base
{
public:
    void sayHello() const
    {
        cout << " Hello- I'm A Derived class object" << endl;
    };
};

void greeting(const Base &obj)
{
    cout << "Greeting" << endl;
    obj.sayHello();
};

int main()
{
    Base b1;
    b1.sayHello(); // Okay. calss base class
    greeting(b1);  // calls base class (static binding)

    Derived d1;
    d1.sayHello(); // Okay. class derived class
    greeting(d1);  // calls base class  (static binding)

    return 0;
}
