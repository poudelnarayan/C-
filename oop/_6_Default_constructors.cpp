/*
The Default Constructor

Does not expect any arguments
    Also called no-args constructors

If you write no constructors at all for a class
    C++ will generate a Default Constructor that does nothing

Called when you instantiate a new object with no arguments


*/

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    std ::string name;
    int health;
    int xp;

public:
    void setName(std::string nameVal)
    {
        name = nameVal;
    }
    std ::string getName()
    {
        return name;
    }
};

int main()
{
    Player narayan; // I am able to make an object here because C++ automaticaly generates an empty constructor
    narayan.setName("narayan");
    cout << narayan.getName() << endl;

    return 0;
}