/*
Write a program that will represent time measurement in 12 hour system with object oriented approach.
The program should have conversion function to convert to 12 hour and 24 hour systems.
*/

#include <iostream>
using namespace std;

class Time
{
    int hr{0}, min{0}, sec{0}, temp{0};

public:
    bool setTime();
    void getTime();
    void convertTo12HourSystem();
    void convertTo24HourSystem();
};

bool Time::setTime()
{
    string msg;
    cout << "Enter hour minute and second" << endl;
    cin >> hr >> min >> sec;
    cout << "Enter 0 for am and 1 for pm" << endl;
    cin >> temp;
    if (temp == 0 || temp == 1)
    {
        return true;
    }
    else
    {
        cout << "Invalid input" << endl;
        return false;
    }
    if (hr > 12 && temp == 0)
    {
        cout << "Not a valid input" << endl;
        return false;
    }
}
void Time::convertTo12HourSystem()
{
    if (hr > 12)
    {
        hr = hr - 12;
    }
}

void Time::convertTo24HourSystem()
{
    if (hr < 12 && temp == 1)
    {
        hr = hr + 12;
    };
}
void Time::getTime()
{
    cout << "Converted time is: " << hr << " : " << min << " : " << sec << endl;
};

int main()
{
    bool isOkay;
    Time t1;
    isOkay = t1.setTime();
    if (!isOkay)
    {
        cout << "Something error happens";
        return 0;
    }
    t1.convertTo24HourSystem();
    t1.getTime();

    return 0;
}