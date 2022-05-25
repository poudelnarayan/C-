#include <iostream>
using namespace std;

double calculateMps(int meter, int seconds)
{
    if (seconds == 0)
        throw 0;
    if (meter < 0 || seconds < 0)
        throw string{"Negative value error"};
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
    catch (string &ex)
    {
        cerr << ex << endl;
    }
    catch (...)
    {
        cout << "unknown error" << endl;
    }

    cout << "Bye" << endl;
}