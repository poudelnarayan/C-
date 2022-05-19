/*
What is using a class as an interface?

.   An abstract class that has only pure virtual functions
.   These functions provide a general set of services to the user of the class
.   Provided as public
.   Each subclass is frree to implement these services as needed
.   Every service(method) must be implemented
.   The service type information is strictly enforced
*/

#include <iostream>
using namespace std;

class I_Printable
{
    friend ostream &operator<<(ostream &os, const I_Printable &obj);

public:
    virtual void print(ostream &os) const = 0;
};

ostream &operator<<(ostream &os, const I_Printable &obj)
{
    obj.print(os);
    return os;
}

class Account : public I_Printable
{
public:
    virtual void withdraw(double amount)
    {
        cout << "In Account::Withdraw" << endl;
    }
    virtual void print(ostream &os) const override
    {
        os << "Account display";
    }
    virtual ~Account(){};
};

class Checking : public Account
{

public:
    virtual void withdraw(double amount)
    {
        cout << "In Checking::Withdraw" << endl;
    }
    virtual void print(ostream &os) const override
    {
        os << "Checking display";
    }
    virtual ~Checking(){};
};

class Savings : public Account
{

public:
    virtual void withdraw(double amount)
    {
        cout << "In Savings::Withdraw" << endl;
    }
    virtual void print(ostream &os) const override
    {
        os << "Savings display";
    }
    virtual ~Savings(){};
};

class Trust : public Account
{
public:
    virtual void withdraw(double amount)
    {
        cout << "In Trust::Withdraw" << endl;
    }
    virtual void print(ostream &os) const override
    {
        os << "Trust display";
    }
    virtual ~Trust(){};
};

class Dog : public I_Printable
{
public:
    virtual void print(ostream &os) const override
    {
        os << "Bhow bhow";
    }
};

void print(const I_Printable &obj)
{
    cout << obj << endl;
}

int main()
{
    Account a;
    cout << a << endl;

    Checking c;
    cout << c << endl;

    Savings s;
    cout << s << endl;

    Trust t;
    cout << t << endl;

    Account *p1 = new Account();
    cout << *p1 << endl; // Account display

    Account *p2 = new Checking();
    cout << *p2 << endl; // Checking display

    Dog *p3 = new Dog();
    cout << *p3 << endl;
    print(*p3);

    return 0;
}