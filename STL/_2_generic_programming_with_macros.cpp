/*
Generic Programming:
    "Writing code that works with variety of types as arguments, as long as those argument types meet specific
    syntactic and semantic requirements", Bjarne Stroustrup (createor fo C++)"

. Macros -> be very careful while using it

. Function templates
. Class templates

*/

/*
Macros(#define)

. C++ preprocessor directive
. No type information
. Simple substitution

*/

#include <iostream>

#define MAX(a, b) ((a > b) ? a : b) // Macro

using namespace std;

int main()
{
    cout << MAX(10, 20) << endl;
    cout << MAX(2.4, 5.6) << endl;
    cout << MAX('A', 'C') << endl;

    return 0;
}