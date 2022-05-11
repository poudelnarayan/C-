// pass by reference
#include <iostream>
using namespace std;

void scale_number(int &num); // Prototype
// location of number is passed into the function

int main()
{
    int number(1000);
    scale_number(number); // call
    cout << number << endl;
    return 0;
}

void scale_number(int &num) // definition
{
    if (num > 100)
    {
        num = 100;
    }
}