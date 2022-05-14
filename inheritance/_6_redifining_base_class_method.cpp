/*
Using and redifining Base class methods

.   Derived class can directly invoke Base class methods.
.   Derived clas cna override or redifine Base class methods

.   Very powerful in the context of polymorphism

*/

/*

static binding of methods call

Base b;     // static binding
b.deposit(1000.0);    // Base::deposit

Derived d;       // static binding
d.deposit(1000.0);     // Derived:: deposit

Base *ptr = new Derived();   // dynamic binding
ptr-> deposit(1000.0);    //Base::deposit ??? (which? confused)


*/

#include <iostream>

using namespace std;

class Account
{
    friend ostream &operator<<(ostream &os, const Account &account);

protected:
    double balance;

public:
    Account();
    Account(double balance);
    void deposit(double amount);
    void withdraw(double amount);
};

class SavingsAccount : public Account
{
    friend ostream &operator<<(ostream &os, const SavingsAccount &account);

protected:
    double intRate;

public:
    SavingsAccount();
    SavingsAccount(double balance, double intRate);
    void deposit(double amount);
    // Withdraw is inherited
};

Account ::Account() : Account(0.0){}; // delegating constructor

Account ::Account(double balance) : balance(balance) {}

void Account::deposit(double amount) { balance += amount; }

void Account::withdraw(double amount)
{
    if ((balance - amount) >= 0)
    {
        balance -= amount;
    }
    else
    {
        cout << "Insufficient funds" << endl;
    }
}

ostream &operator<<(ostream &os, const Account &account)
{
    os << "Account balance: " << account.balance;
    return os;
}

SavingsAccount::SavingsAccount(double balance, double intRate) : Account(balance), intRate{intRate} {}
SavingsAccount::SavingsAccount() : SavingsAccount{0.0, 0.0} {}

void SavingsAccount::deposit(double amount)
{
    amount = amount + (amount * intRate / 100);
    Account::deposit(amount);
}

ostream &operator<<(ostream &os, const SavingsAccount &account)
{
    os << "Savings Account Balance: " << account.balance << " Interest rate: " << account.intRate;
    return os;
}

int main()
{
    cout << "\n ==== Account class ========" << endl;
    Account a1{100.0};
    cout << a1 << endl;

    a1.deposit(500.0);
    cout << a1 << endl;

    a1.withdraw(100.0);
    cout << a1 << endl;

    a1.withdraw(5000.0);
    cout << a1 << endl;

    cout << "\n ======= Savings Account class =======" << endl;

    SavingsAccount s1{100, 5.0};
    cout << s1 << endl;

    s1.deposit(1000);
    cout << s1 << endl;

    s1.withdraw(2000);
    cout << s1 << endl;

    s1.withdraw(1000);
    cout << s1 << endl;

    return 0;
}
