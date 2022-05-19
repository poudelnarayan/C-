/*
                POLYMORPHISM

    COMPILE TIME                    RUN-TIME

    1> Function Overloading         1> Function Overriding
    2> Operator Overloading

*/

#include <iostream>
#include <memory>

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
    b1.sayHello(); // Okay. base class
    greeting(b1);  // calls base class (static binding)

    Derived d1;
    d1.sayHello(); // Okay. derived class
    greeting(d1);  // calls base class  (static binding)

    Base *ptr = new Derived(); // regular pointers
    ptr->sayHello();           // static  binding

    unique_ptr<Base> ptr1 = make_unique<Derived>(); // smart pointer
    ptr1->sayHello();

    delete ptr;
    // Smart pointers are so smart that they a can handle their state themselves. i.e no need to delete manually

    return 0;
}
