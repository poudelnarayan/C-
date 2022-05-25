/*
. Exception Handling
    . dealing  with extraordinary situation
    . indicated that an extraordinary situation has been detected or has occured
    . program can deal with the extraordinary sitautions in a suitable manner

. What causes exceptions?
    . insufficient resources
    . missing resources
    . invalid operations
    . range violations
    . underflows and overflows
    . illegal data and many others

. Exception safe
    . when your code handles exception

*/

/*
Terminology

. Exception
    . an object or primitive type that signals that an error has occured

. Throwing an exception (raising an exception)
    . your code detects that an error has occured or will occur
    . the place where the error occured may not know how to handle the error
    . code can throw an exception describing the error to another part of the program that knows how to handle the error

. Catching an exceptioon(handle the exception)
    . code that handles the exception
    . may or may not cause the program to terminate

*/

/*
C++ syntax for Exception handling

. throw
    . throws an exception
    . followed by an argument

. try { code that may throw an exception }
    . you place code that may throw an exception in a try block
    . if the code throws an exception the try block is existed
    . the thrown exception is handled by a catch handler
    . if no catch handler exists the program terminates


. catch (Exception ex) {code to handle the exception}
    . code that handles the exception
    . can have multiple catch handlers
    . may or may not cause the program to terminates

*/

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
    // handling by if else check
    if (sec != 0)
    {
        meterPerSecond = static_cast<double>(meter) / sec;
        cout << "Result: " << meterPerSecond << endl;
    }
    else
    {
        cerr << "Sorry, can't divide by zero" << endl;
    }

    cout << "Bye" << endl;
}