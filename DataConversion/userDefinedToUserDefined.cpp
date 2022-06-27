/*
In this type, one class type is converted into another class type. It can be done  in 2 ways :
1.Using constructor
2.Using Overloading casting operator

1.Using constructor :
In the Destination  class we use the constructor method

Objects of different types :

  ObjectX=ObjectY;

Here ObjectX is Destination object and ObjectY is source object
*/

#include <iostream>
using namespace std;
// cgs system
class CGS
{
    int mts; // meters
    int cms; // centimeters
public:
    void showdata()
    {
        cout << "Meters and centimeters in CGS system:";
        std::cout << mts << " meters " << cms << " centimeters" << std::endl;
    }
    CGS(int x, int y) // parameterized constructor
    {
        mts = x;
        cms = y;
    }
    int getcms()
    {
        return cms;
    }
    int getmts()
    {
        return mts;
    }
};
class FPS
{
    int feet;
    int inches;

public:
    FPS() // default constructor
    {
        feet = 0;
        inches = 0;
    }
    FPS(CGS d2)
    {
        int x;
        x = d2.getcms() + d2.getmts() * 100;
        x = x / 2.5;
        feet = x / 12;
        inches = x % 12;
    }
    void showdata()
    {
        cout << "feet and inches in FPS system:";
        std::cout << feet << " feet " << inches << " inches" << std::endl;
    }
};

int main()
{
    CGS d1(9, 10);
    FPS d2;
    d2 = d1;
    d1.showdata(); // to display CGS values
    d2.showdata(); // to display FPS values
    return 0;
}
