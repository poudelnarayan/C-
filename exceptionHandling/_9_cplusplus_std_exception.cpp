#include <iostream>
#include <memory>
using namespace std;

class IllegalBalanceException : public exception
{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
    virtual const char *what() const noexcept
    {
        return " Illegal balance exception";
    }
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
        unique_ptr<Account> myAccount = make_unique<Account>("Narayan", -10.0);
        myAccount->displayValue();
    }
    catch (const IllegalBalanceException &ex)
    {
        cerr << ex.what() << endl;
    }

    return 0;
}