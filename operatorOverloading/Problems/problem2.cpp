/*
Write a program that will add objects of data class (with members: day,month,year) using operator overloading. Make another function
to find no of days in between two dates by overloading operator.
*/

#include <iostream>
using namespace std;

class Date
{
    int year, month, day;

public:
    Date() : Date(0, 0, 0){};
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    // Date public
};
