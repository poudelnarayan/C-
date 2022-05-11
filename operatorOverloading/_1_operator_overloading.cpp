/*
The following operators cannot be overloaded
::
:?
.*
.
sizeof
*/

#include <iostream>

using namespace std;

class MyString
{
    char *str;

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    ~MyString();
    void display() const;
    int get_length() const;
    const char *get_str() const;
};