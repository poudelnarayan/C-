/*
CONSTRUCTORS:

1> Special member method
2> Invoked during object vreation
3> Useful for initialization
4> Same name as the class
5> No return type is specified
6> Can be overloaded


DESTRUCTORS

1> Special member method
2> Same name as the class proceeded wiith tilde (~)
3> Invoked automatically when an object is destroyed
4> No return type and no parameters
5> Only 1 destructor is allowed per class
5> Cannot be overloaded
6> Useful to release memory and other resources.


If we provide no constructors and no destructors  C++ will
automatically provide a default constructors and a default destructors
that are empty.


*/

#include <iostream>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    void setName(string nameVal)
    {
        name = nameVal;
    }
    // Overloaded Constructors
    Player()
    {
        cout << "No args Constructors called" << endl;
    }
    Player(string name)
    {
        cout << "String arg constructor called" << endl;
    }
    Player(string name, int health, int xp)
    {
        cout << "Three args constructors called" << endl;
    }
    // Destructor
    ~Player()
    {
        cout << "Destructor called for " << name << endl;
    }
};

int main()
{
    {
        Player narayan;
        narayan.setName("Narayan");
    }
    {
        Player poudel;
        poudel.setName("Poudel");
        Player android;
        android.setName("Android");
        Player villain("Villian", 100, 12);
    }
    Player *enemy = new Player;
    enemy->setName("Enemy");

    delete enemy;

    return 0;
}