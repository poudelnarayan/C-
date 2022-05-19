#include <iostream>

using namespace std;

class Base
{
public:
    virtual void sayHello() const
    {
        cout << "Hello - i\'m a base class " << endl;
    }
    virtual ~Base(){};
};

class Derived : public Base
{
public:
    virtual void sayHello() const override
    {
        cout << "Hello - i'm a derived class" << endl;
    }
    virtual ~Derived(){};
};

int main()
{

    Base *p1 = new Base();
    p1->sayHello();

    Derived *p2 = new Derived();
    p2->sayHello();

    Base *p3 = new Derived();
    p3->sayHello();

    return 0;
}