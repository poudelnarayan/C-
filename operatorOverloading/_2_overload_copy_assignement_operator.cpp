/*
Copy assignment operator (=)

. C++ provides a default assignment operator used for assigning one project to another

{
    Mystring s1 {"narayan"};
    Mystring s2 = s1;    // NOT assignment (since the pbject is just created) same as Mystring{s2};

    s2 = s1  // assignment since the object is created now.
}

. Default is memberwise assignment (shallow copy)
   . if we have raw pointer data member we must deep copy

*/

#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
    char *str; // pointer to a char[] that holds C-style string

public:
    MyString();                       // No-args constructor
    MyString(const char *s);          // Overloaded constructor
    MyString(const MyString &source); // Copy Constructor
    ~MyString();                      // Destructor

    MyString &operator=(const MyString &rhs); //  copy assignment
};

// No-args constructor
MyString::MyString()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
MyString::MyString(const char *s)
    : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Copy constructor
MyString::MyString(const MyString &source)
    : str(nullptr)
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

// Destructor
MyString::~MyString()
{
    delete[] str;
}

// Copy Assignment
MyString &MyString::operator=(const MyString &rhs)
{
    cout << "Copy Assignment" << endl;
    if (this == &rhs)
    {
        return *this;
    }
    delete[] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
}

int main()
{
    MyString a{"Hello"};
    MyString b;
    b = a;
    b = "This is a test";

    return 0;
}
