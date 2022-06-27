/*
2.Using Overloading casting operator

Objects of different types
objectX = objectY;

Here we use Overloading casting operator in source class i.e. overloading destination class in source class
See the below example in which we have two classes Time and Minute respectively and will convert one class Time to another Minute class.
In the below example minute class is destination class and time class is source class
so we need to overload the destination class in the source class
Here we should not tell the return type but we returns the overloaded class object

i.e. returning value without specifying return type

*/

// C++ program to illustrate the
// above conversion
#include <iostream>
using namespace std;
// minutes class
class Minute
{

public:
    int mins;
    // Constructors
    Minute()
    {
        mins = 0;
    }

    // Function to print the value of
    // hours and minutes
    void show()
    {
        cout << "\nTotal Minute : " << mins << endl;
    }
};

// Time Class
class Time
{
    int hr, mins;

public:
    // Constructors
    Time(int h, int m)
    {
        hr = h;
        mins = m;
    }
    Time()
    {
        cout << "\nTime's Object Created";
    }
    operator Minute() // overloading minute class
    {
        Minute m;
        m.mins = (hr * 60) + mins;
        return m;
    } // driver code

    // Function to print the value of
    // hours and minutes
    void show()
    {
        cout << "Hour: " << hr << endl;
        cout << "Minute : " << mins << endl;
    }
};

// Minutes Class
int main()
{
    Time T1(3, 40);
    Minute m;
    m = T1; // minute class is destination and Time class is source class
    T1.show();
    m.show();
    return 0;
}
