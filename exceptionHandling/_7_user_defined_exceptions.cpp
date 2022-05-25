#include <iostream>
using namespace std;

class DivideByZeroException
{
};

class NegativeValueException
{
};

double calculateMps(int meter, int seconds)
{
    if (seconds == 0)
        throw DivideByZeroException();
    if (meter < 0 || seconds < 0)
        throw NegativeValueException();
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
    catch (const DivideByZeroException &ex)
    {
        cerr << "Tried to divide by zero" << endl;
    }
    catch (const NegativeValueException &ex)
    {
        cerr << "Sorry, one of your parameter is negative" << endl;
    }
    catch (...)
    {
        cout << "unknown error" << endl;
    }

    cout << "Bye" << endl;
}