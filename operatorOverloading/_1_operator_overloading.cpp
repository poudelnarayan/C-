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
    void display() const;
    int get_length() const; // Getters
    const char *get_str() const;
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
        *str = '/0';
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

// Display method
void MyString::display() const
{
    cout << str << ":" << get_length() << endl;
}

// Length getter
int MyString::get_length() const { return strlen(str); }

// string getter
const char *MyString::get_str() const { return str; }

int main()
{
    MyString empty;              // no-args constructor
    MyString narayan("Narayan"); // overloaded constructor
    MyString poudel{narayan};    // copy constructor

    empty.display();
    narayan.display();
    poudel.display();

    return 0;
}

/*
The following operators cannot be overloaded
::
:?
.*
.
sizeof
*/

/*
SOME BASIC RULES

. Precedence and Associativity cannot be changed
. 'arity' cannot be changes (i.e. can't make the division operator unary)
. Can't overload operators for primitive type(e.g int,double,etc.)
. Can't create new operator
. [],(),-> and the assignment operator(=) must be declared as member methods.
. Other operators can be declared as member methods or global functions.



*/