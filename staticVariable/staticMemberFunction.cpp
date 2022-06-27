/*
Like static member varibale, we can also have static member functions . A member function that is declared static has the following properties:

    A static function can have access to only other static members(functions or variables) declared in the same class.
    A static member function can be called using the class name(instead of it's object) as follows:

    class-name::function-name;

*/

#include <iostream>

using namespace std;

class Test
{
    int code;
    static int count;

public:
    void setCode()
    {
        code = ++count;
    }
    void showCode()
    {
        cout << "object number: " << code << endl;
    }
    static void showCount()
    {
        cout << "Count: " << count << endl;
    }
};

int Test::count = 1;

int main()
{
    Test t1, t2;

    t1.setCode();
    t2.setCode();

    Test::showCount();
    Test t3;
    t3.setCode();

    Test::showCount();

    t1.showCode();
    t2.showCode();
    t3.showCode();

    return 0;
}