/*
Player() <-- clas

PREVIOUS WAY:

Player::Player(){  -> overriding a default constructor
    name = "None"; -> Assignment not initialization
    health = 0;
    xp = 0;
}
How it works is name with empty string , health with garbage vlaue
and xp with another garbage value is created first and then is assigned
the value given when the constructor body is reached.


BETTER WAY:

Player::Player()
    : name{"None"},health{0},xp{0}{}  -> initialization



This is different from the previous way as no new variable is created and assigned.
This is a direct initialization of the constructor.



FOR Player(string,int,int)  constructor

Previous way:

Player::Player(string name_val  , int health_val,int xp_val){
    name = name_val;
    health= health_val;
    xp = xp_val;
}

Better Way:

Player::Player(string name_val , int health_val , int xp_val)
    : name{name_val} , health{health_val} , xp{xp_val}{

    }

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
    Player();
    Player(string nameVal);
    Player(string nameVal, int healthVal, int xpVal);
};

Player ::Player() : name{"None"}, health{0}, xp{0} {}

Player::Player(string nameVal)
    : name{nameVal}, health{0}, xp{0} {}

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