/*
Move Assignment operator (=)


.You can choose to overload the move assignment operator
    . C++ will use the copy assignment operator if necessary


MyString s1;
s1 = MyString {"Frank"}; // move assignment

.If we have raw pointer we should overload the move assignment operator for efficiency.
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

    MyString &operator=(MyString &&rhs); //  Move assignment
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

// Move Assignment
MyString &MyString::operator=(MyString &&rhs)
{
    cout << "Move Assignment" << endl;
    if (this == &rhs)
    {
        return *this;
    }
    delete[] this->str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

int main()
{
    MyString a{"Hello"};
    a = MyString{"Hola"};
    a = "Bonjour";

    return 0;
}