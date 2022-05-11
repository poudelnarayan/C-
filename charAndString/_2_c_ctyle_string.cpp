/*
{
    char myName[] {"Narayan"};

    myName[7] = 'Y'; // ERROR
}

{
    char myName[9]  {"Narayan"};
    myName[7] = 'Y';  // OK


}

{
    char myName[8];
    myName = "Narayan"; //Error

    strcpy(myName , "Narayan"); // okay
}


Function that work with C-style string:
    . Copying
    . Concatenation
    . Comparision
    . Searching
    . and others

*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[80];
    strcpy(str, "Hello"); // Copying
    cout << str << endl;
    strcat(str, "there"); // Concatenation
    cout << str << endl;
    cout << strlen(str) << endl; // Length
    cout << strcmp(str, "another") << endl;
    // strcmp returns 0 if both string are identical ,
    // other value if unequal

    return 0;
}

/*
C++ has another library called C standard lib (cstdlib) that contains  function that convert
string to other types.

. Include function toconvert C-style String to
    . integer
    . float
    . long
    . etc..

*/