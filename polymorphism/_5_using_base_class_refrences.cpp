#include <iostream>
using namespace std;

class Account
{
public:
    virtual void withdraw(double amount)
    {
        cout << "In Account: withdraw" << endl;
    }
    virtual ~Account() { cout << "Account:: destructor" << endl; }
};

class Checking : public Account
{
public:
    virtual void withdraw(double amount)
    {
        cout << "In checking :: Withdraw" << endl;
    }
    virtual ~Checking() { cout << "Checking:: destructor" << endl; }
};

class Savings : public Account
{
public:
    virtual void withdraw(double amount)

    {
        cout << "In Savings:: Withdraw" << endl;
    }
    virtual ~Savings() { cout << "Savings:: destructor" << endl; }
};

class Trust : public Account
{
public:
    virtual void withdraw(double amount)

    {
        cout << "In Trust:: withdraw" << endl;
    }
    virtual ~Trust() { cout << "Trust:: destructor" << endl; }
};

void doSomething(Account &account, double amount)
{
    account.withdraw(amount);
}
int main()
{
    Account a;
    Account &ref = a;
    ref.withdraw(1000);

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000);

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    doSomething(a1, 1000);
    doSomething(a2, 1000);
    doSomething(a3, 1000);
    doSomething(a4, 1000);

    return 0;
}
