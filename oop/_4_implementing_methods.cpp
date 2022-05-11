#include <iostream>

using namespace std;

class Account
{
private:
    string name;
    double balance;

public:
    void setBalance(double bal) { balance = bal; }
    double getBalance() { return balance; }
    void setName(string);
    string getName();
    bool deposit(double);
    bool withdraw(double);
};

void Account::setName(string acName)
{
    name = acName;
}

string Account::getName()
{
    return name;
}

bool Account::deposit(double amount)
{
    // if verify amount
    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if (balance - amount >= 0)
    {
        balance -= amount;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    Account myAccount;
    myAccount.setName("Narayan");
    myAccount.setBalance(1000.0);

    if (myAccount.deposit(200.0))
        cout << "Deposit Success" << endl;
    else
        cout << "Deposit Not Allowed" << endl;

    if (myAccount.withdraw(500.0))
        cout << "Withtdrawl success" << endl;
    else
        cout << "Not Sufficient funds" << endl;

    if (myAccount.withdraw(1500.0))
        cout << "Withdrawl Success";
    else
        cout << "Not Sufficient Funds" << endl;

    return 0;
}
