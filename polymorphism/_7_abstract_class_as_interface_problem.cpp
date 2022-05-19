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

class Account
{
    friend ostream &operator<<(ostream &os, const Account &acc);

public:
    virtual void withdraw(double amount)
    {
        cout << "In Account::Withdraw" << endl;
    }
    virtual ~Account(){};
};

ostream &operator<<(ostream &os, const Account &acc)
{
    os << "Account display";
    return os;
};

class Checking : public Account
{
    friend ostream &operator<<(ostream &os, const Checking &acc);

public:
    virtual void withdraw(double amount)
    {
        cout << "In Checking::Withdraw" << endl;
    }
    virtual ~Checking(){};
};

ostream &operator<<(ostream &os, const Checking &acc)
{
    os << "Checking display";
    return os;
}

class Savings : public Account
{
    friend ostream &operator<<(ostream &os, const Savings &acc);

public:
    virtual void withdraw(double amount)
    {
        cout << "In Savings::Withdraw" << endl;
    }
    virtual ~Savings(){};
};

ostream &operator<<(ostream &os, const Savings &acc)
{
    os << "Savings display";
    return os;
}

class Trust : public Account
{
    friend ostream &operator<<(ostream &os, const Trust &acc);

public:
    virtual void withdraw(double amount)
    {
        cout << "In Trust::Withdraw" << endl;
    }
    virtual ~Trust(){};
};

ostream &operator<<(ostream &os, const Trust &acc)
{
    os << "Trust display";
    return os;
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
    cout << *p2 << endl; // Account display   (solved this problem in _8_abstract_problem_solved.cpp)

    return 0;
}