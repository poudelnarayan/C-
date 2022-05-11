// CLASS MEMBER ACCESS MODIFIERS
/*
    Public : accessible everywhere
    private: accessible only by members or friends of the class
    protected: used with inheritance


    BY DEFAULT EVERY MEMBER IN THE CLASS WITH BE PRIVATE

*/
#include <iostream>

using namespace std;

class Player
{
private:
    string name{"Player"};
    int health;
    int xp;

public:
    void talk(string text_to_say)
    {
        cout << name << " says " << text_to_say << endl;
    }
    bool is_dead();
};

int main()
{
    Player Narayan;
    Narayan.talk("Hello there");

    return 0;
}