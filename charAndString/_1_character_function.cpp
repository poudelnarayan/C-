/*
isalpha(c)  --> True if c is  a letter  (return non zero value if alphabet and 0 if  not alphabet , same case for other)
isalnum(c)  --> True if c is a letter or digit
isdigit(c)  --> True of c is a digit
islower(c)  --> True of c is lowercase letter
isprint(c)  --> True if c is printable character
ispunct(c)  --> True if c is punctuation character
isupper(c)  --> True if c is an uppercase letter
isspace(c)  --> True if c is whitespace


tolower(c)  --> returns lowercase of c
toupper(c)  --> returns uppercase of c

*/

#include <iostream>
#include <cctype>

using namespace std;
int main()
{
    char c = 'd';
    cout << isalpha(c) << endl;
    cout << isalnum(c) << endl;
    cout << isdigit(c) << endl;
    cout << islower(c) << endl;
    cout << isprint(c) << endl;
    cout << ispunct(c) << endl;
    cout << isupper(c) << endl;

    return 0;
}