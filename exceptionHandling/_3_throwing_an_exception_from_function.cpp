#include <iostream>
using namespace std;

double calculateMps(int meter, int seconds)
{
    if (seconds == 0)
        throw 0;
    return static_cast<double>(meter) / seconds;
}

int main()
{
    int meter{};
    int sec{};
    double meterPerSecond{};

    cout << "Enter the meter: ";
    cin >> meter;
    cout << "Enter seconds: ";
    cin >> sec;
    try
    {
        meterPerSecond = calculateMps(meter, sec);
        cout << "Result : " << meterPerSecond << endl;
    }
    catch (int &ex)
    {
        cerr << "Tried to divide by zero" << endl;
    }

    cout << "Bye" << endl;
}