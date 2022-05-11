/*
When objects are copied C++ must create a new object from an existing object.

When is a copy of an object made?
    . passing object by value as a parameter
    . returning an object from a function by value
    . constructing one object based on another of the same class

C++ must have a way of accomplishing this so it provides a compiler-defined
copy constructor if you don't

{If we dont provide a copy constructor the C++ compiler provide a compiler generated one.}
*/

/*
PASS OBJECT BY_VALUE

Player hero{"Hero" ,100, 20};

void display_player(Player p ){  -->> here p is a COPY of hero in this example.

}

display_player(hero);
*/

/*
RETURN OBJECT BY VALUE

Player enemy;

Player create_cuper_enemy(){
    Player an_enemy{"Super Enemy",1000,1000};
    return an_enemy;  --->> A copy of an_enemy is returned
}

enemy = create_super_enemy();
*/

/*
Player hero {"hero",100,100};
Player another_hero {hero}; --> A copy of hero is made
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
    string getName() { return name; }
    int getHealth() { return health; }
    int getXp() { return xp; }

    Player(string nameVal = "None", int healthVal = 0, int xpVal = 0);

    // Copy constructor
    Player(const Player &source);

    // Destructors
    ~Player() { cout << "destructor is called for : " << name << endl; }
};

Player::Player(string nameVal, int healthVal, int xpVal)
    : name(nameVal), health(healthVal), xp{xpVal}
{
    cout << "Three-args constructor for " + name << endl;
}

Player::Player(const Player &source)
    // : name{source.name}, health{source.health}, xp{source.xp}
    // or
    : Player{source.name, source.health, source.xp} // delegating

{
    cout << "Copy constructor  - Made copy of : " << source.name << endl;
}

void displayPlayer(Player p)
{
    cout << "Name: " << p.getName() << endl;
    cout << "Health: " << p.getHealth() << endl;
    cout << "XP: " << p.getXp() << endl;
}

int main()
{
    Player empty;

    displayPlayer(empty);

    Player narayan{"narayan"};
    Player hero{"Hero", 100};
    Player villian{"Villian", 100, 55};

    return 0;
}
