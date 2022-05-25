// STACK UNWINDING AND HOW IT WORKS

/*
If an exception is thrown but not caught in the current scope C++ tries to find a handler for the
exception by unwinding the stack

.Function in which the exception was not caught terminates and is removed from the call stack
.If a try block was used , then catch blocks are checked for match
.If no try block was used or the catch handler doesn't match stack unwinding occurs again
.If the stack is unwound , program flows back to main and no catch handler handles the exception , the program then terminates

*/

// Uncomment the exceptions and play around

#include <iostream>
using namespace std;

void funcB();
void funcC();

void funcA()
{
    cout << "Starting funcA" << endl;
    funcB();
    cout << "Ending funcA" << endl;
}

void funcB()
{
    cout << "Starting funcB" << endl;
    // try
    // {
    funcC();
    // }
    // catch (int &ex)
    // {
    //     cout << "error" << endl;
    // }
    cout << "Ending funcB" << endl;
}

void funcC()
{
    cout << "Starting funcC" << endl;
    throw 0;
    cout << "Ending funcC" << endl;
}
int main()
{
    cout << "Starting main" << endl;
    try
    {
        funcA();
    }
    catch (int &ex)
    {
        cout << "error" << endl;
    }
    cout << "Finishing main" << endl;

    return 0;
}