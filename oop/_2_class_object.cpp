#include <iostream>
using namespace std;

class Player
{
public:
    // attributes
    string name;
    int health;
    int xp;

    // methods
    void talk(string text_to_say)
    {
        cout << name << " says  " << text_to_say << endl;
    }
    bool is_dead();
};

// Encapsulation means to encapsulate the methods to the respective class. that means we can also provide methods or functions in
// the class body that is specific to the respective class.

class Account
{
public:
    // attributes
    string name;
    double balance;

    bool deposit(double bal)
    {
        balance += bal;
        cout << "In deposit" << endl;
    }
    bool withdraw(double bal)
    {
        balance -= bal;
        cout << "In withdraw" << endl;
    }
};

int main()
{
    Account narayan_account;
    narayan_account.balance = 5000.0;
    narayan_account.deposit(1000.0);
    narayan_account.withdraw(500.0);

    Player Narayan;
    Narayan.name = "Narayan";
    Narayan.health = 100;
    Narayan.xp = 12;
    Narayan.talk("Hello world");

    Player *enemy = new Player;
    // Arrow operator is used for the pointer
    enemy->name = "Enemy";
    enemy->health = 100;
    enemy->xp = 12;

    enemy->talk("I will destroy you");

    return 0;
}