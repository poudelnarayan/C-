#include <iostream>

using namespace std;

class Item
{
    static int count;
    int number;

public:
    void getData(int a)
    {
        number = a;
        count++;
    }
    void getCount()
    {
        cout << "Count: " << count << endl;
    }
};

int Item::count;
/*
Note that the type and scope of each static member variable must be defined outside the class definition.
This is necessary because the static data members are stored separately rather than as a part of an object. Since they
are associated with the class itself rather than as a  part of an object. Since they are associated with the class itself rather than with any class object , they are also known as class variables.
*/

int main()
{
    Item a, b, c;
    a.getCount();
    b.getCount();
    c.getCount();

    a.getData(100);
    b.getData(20);
    c.getData(45);

    a.getCount();
    b.getCount();
    c.getCount();

    return 0;
}