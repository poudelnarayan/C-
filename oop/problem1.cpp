/*
Write a program that illustrate object concept to add and subtract time units (a time
unit has hr,min and sec member)
*/

#include <iostream>

using namespace std;

class Time
{
    int hr{0}, min{0}, sec{0};

public:
    void setTime();
    void getTime();
    void addTime(Time, Time);
    void subtractTime(Time, Time);
};

void Time::setTime()
{
    cout << "Enter hour, minutes and seconds: ";
    cin >> hr >> min >> sec;
}

void Time::getTime()
{
    cout << hr << " hour, " << min << " min and " << sec << " seconds";
}

void Time::addTime(Time t1, Time t2)
{
    sec = t1.sec + t2.sec;
    min = t1.min + t2.min + sec / 60;
    sec = sec % 60;
    hr = t1.hr + t2.hr + min / 60;
    min = min % 60;
}
void Time::subtractTime(Time t1, Time t2)
{

    sec = t2.sec - t1.sec;
    if (sec < 0)
    {
        sec += 60;
        min--;
    }
    min = min + t2.min - t1.min;
    if (min < 0)
    {
        min += 60;
        hr--;
    }
    hr = hr + t2.hr - t1.hr;

    min = min % 60;
    sec = sec % 60;
}

int main()
{
    Time time1, time2, time3, time4;
    time1.setTime();
    time2.setTime();
    time3.addTime(time1, time2);
    cout << endl
         << "The addition of two time is: " << endl;
    time3.getTime();
    time4.subtractTime(time1, time2);
    cout << endl
         << "The subtraction of time is: " << endl;
    time4.getTime();

    return 0;
}