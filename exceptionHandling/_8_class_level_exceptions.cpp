/*
Exceptions can also be thrown from within a class:

.Method
    These work the same way as they do for functions as we've seen

.Constructor
    Constructor may fail
    Constructor do not return any value
    Throw an exception in the constructor if you cannot initialize an object

. Destructor
    Do NOT throw exception from your destructor

*/

#include <iostream>
#include <memory>
using namespace std;

class IllegalBalanceException
{
public:
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;
};

class Account
{
    string name;
    double balance;

public:
    Account(string, double);
    void displayValue();
};

Account::Account(string name, double balance) : name{name}, balance{balance}
{
    if (balance < 0.0)
        throw IllegalBalanceException();
}
void Account::displayValue()
{
    cout << "(name: " << name << ", balance: " << balance << " )";
}

int main()
{
    try
    {
        unique_ptr<Account> myAccount = make_unique<Account>("Narayan", 10.0);
        myAccount->displayValue();
    }
    catch (const IllegalBalanceException &ex)
    {
        cerr << "Couldn't create account - negative balance" << endl;
    }

    return 0;
}