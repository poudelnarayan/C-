#include <iostream>

using namespace std;

class Meter
{
private:
    float length;

public:
    Meter() : length{0} {}
    operator float()
    {
        float l;
        l = length * 100.0;
        return l;
    }
    

    void getLength()
    {
        cout << "Enter length in (meters): ";
        cin >> length;
    }
};

int main()
{
    Meter m1;
    float l1;
    m1.getLength();
    l1 = m1;
    cout << "Length in cms = " << l1;
    return 0;
}