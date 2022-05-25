#include <iostream>
using namespace std;

int main()
{
    int meter{};
    int sec{};
    double meterPerSecond{};

    cout << "Enter the meter: ";
    cin >> meter;
    cout << "Enter seconds: ";
    cin >> sec;
    // handling by standard exception

    try
    {
        if (sec == 0)
            throw 0;

        meterPerSecond = static_cast<double>(meter) / sec;
        cout << "Result: " << meterPerSecond << endl;
    }
    catch (int &e)
    {
        cerr << "Sorry cant divide by zero" << endl;
    }

    cout << "Bye" << endl;
}