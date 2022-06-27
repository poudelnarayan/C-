#include <iostream>

using namespace std;

class Meter
{
private:
    float length;

public:
    Meter() : Meter(0.0) {}

    Meter(float l)
    {
        length = l / 100.0;
    }
    void showLength()
    {
        cout << "Length in meter = " << length;
    }
};

int main()
{
    Meter m1;
    float l1;
    cout << "Enter length (in cms) : ";
    cin >> l1;
    // m1 is user-defined and l1 is basic
    m1 = l1;
    m1.showLength();
}