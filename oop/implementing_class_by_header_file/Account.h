#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
class Account
{
private:
    double balance;

public:
    void set_balance(double bal);
    double get_balance();
};

#endif

/*
key to understand:

if this file is included by more than one cpp files
then the compiler will see the declaration for the
account class more than once and give us an error
about duplicate declaration.
In order to solve this we can use what's called include
guard that enesures that the compiler will process this file
only once no matter how many times it is included.
include guard is a series of preprocessor directives that gurantees
the file will only be included once.
The way it works is it wrap up our entireclass declaration in the include
guard.
the first lise is:
#(if not defined) _Account_H_
this checks to see if the preprocessor has a symbol named _ACCOUNT_H_
the symbol name can be anything. but this is the best practice.
If the preprocessor has that name defined then it skips the entire file and goes to the #endif.
In other words it doesnot process the file since it's already seen it because
the symbol has been defined.
If the symbol has not been defined then the symbol is set and the file is processes as usual.

*/