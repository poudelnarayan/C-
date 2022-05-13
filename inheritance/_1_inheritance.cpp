/*
What is inheritance and why is it used?

. Provides a methos for creating new classes from existing classes
. The new class contains the data and behaviours of the existing class
. Allow for reuse of existing classes
. Allows us to focus on the common attributes  among a set of classes
. Allows new classes to modifu behaviours of existing classes to make it unique
    . without actually modifying the original class


*/

/*
Public Inheritance
.   Most common
.   "is-a" relationship
        . Employee 'is-a' Person
        . Circle 'is-a' shape.

Private and Protected Inheritance
.   Establishes "derives class has a base class" relationship
.   "Is implemented in terms of " relationship
.   Different from composition

Composition
.   "has-a" relationship
        . Person "has-a " Account
        . Circle "has-a" Location


*/
#include <iostream>

using namespace std;

class Account
{
public:
    double balance;
    string name;
    void deposit(double);
    void withdraw(double);
    Account();
    ~Account();
};

class SavingsAccount : public Account
{
public:
    double interestRate;
    SavingsAccount();
    ~SavingsAccount();
    void deposit(double);
    void withdraw(double);
};

Account::Account()
    : balance{0}, name{" "}
{
}

Account::~Account()
{
}

void Account::deposit(double amount)
{
    cout << "Acount deposit called with " << amount << endl;
}

void Account::withdraw(double amount)
{
    cout << "Account withdraw called with : " << amount << endl;
}

SavingsAccount::SavingsAccount()
    : interestRate{3.0}
{
}
SavingsAccount::~SavingsAccount()
{
}

void SavingsAccount::deposit(double amount)
{
    cout << "Savings Account deposit called with " << amount << endl;
}

void SavingsAccount::withdraw(double amount)
{
    cout << "Savings Account withdraw called with  " << amount << endl;
}

int main()
{
    cout << "\n ===Account =============" << endl;
    Account acc{};
    acc.deposit(200.0);
    acc.withdraw(500.0);

    cout << endl;

    Account *pAcc{nullptr};
    pAcc = new Account();
    pAcc->deposit(1000.0);
    pAcc->withdraw(500.0);
    delete pAcc;

    cout << "\n ===Savings =============" << endl;
    SavingsAccount savAcc{};
    savAcc.deposit(2000.0);
    savAcc.withdraw(200.0);

    cout << endl;

    SavingsAccount *pSavAcc{nullptr};
    pSavAcc = new SavingsAccount();
    pSavAcc->deposit(400.0);
    pSavAcc->withdraw(200.0);
    delete pSavAcc;

    return 0;
}