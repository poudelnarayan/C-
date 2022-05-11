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
    void setTime();
    void getTime();
    void convertTo12HourSystem();
    void convertTo24HourSystem();
};

void Time::setTime()
{
    string msg;
    cout << "Enter hour minute and second" << endl;
    cin >> hr >> min >> sec;
    cout << "Enter 0 for am and 1 for pm" << endl;
    cin >> temp;
    if (temp == 0 || temp == 1)
    {
    }
    else
    {
        cout << "Invalid input" << endl;
        return;
    }
    if (hr > 12 && temp == 0)
    {
        cout << "Not a valid input" << endl;
        return;
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
    Time t1;
    t1.setTime();
    t1.convertTo24HourSystem();
    t1.getTime();

    return 0;
}