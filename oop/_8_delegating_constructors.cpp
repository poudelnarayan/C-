// Example from _7_constructors_initialization_lists.cpp

#include <iostream>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    Player();
    Player(string nameVal);
    Player(string nameVal, int healthVal, int xpVal);
};

Player ::Player() : Player{"none", 0, 0} {} // delegating constructors

// Delegating constructors helps to reduce code duplication.
// How it works is when an empty constructor is reached it calls the constructor with three args.

Player::Player(string nameVal)
    : Player{nameVal, 0, 0} {}

Player::Player(string nameVal, int healthVal, int xpVal)
    : name(nameVal), health(healthVal), xp{xpVal}
{
}

int main()
{
    Player empty;
    Player narayan{"narayan"};
    Player villian{"Villian", 100, 55};

    return 0;
}