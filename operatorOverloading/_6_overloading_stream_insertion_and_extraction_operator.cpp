#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
    friend ostream &operator<<(ostream &os, const MyString &rhs);
    friend istream &operator>>(istream &in, MyString &rhs);

private:
    char *str; // pointer to a char[] that holds C-style string

public:
    MyString();                       // No-args constructor
    MyString(const char *s);          // Overloaded constructor
    MyString(const MyString &source); // Copy Constructor
    ~MyString();                      // Destructor

    MyString &operator=(MyString &&rhs);
    MyString &operator=(const MyString &rhs);

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

// Copy Assignment
MyString &MyString::operator=(const MyString &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    delete[] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
}
// Move Assignment
MyString &MyString::operator=(MyString &&rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    delete[] this->str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
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

// overloaded insertion operator
ostream &operator<<(ostream &os, const MyString &rhs)
{
    os << rhs.str;
    return os;
}

// overload extraction operator
istream &operator>>(istream &in, MyString &rhs)
{
    char *buff = new char[1000];
    in >> buff;
    rhs = MyString{buff};
    delete[] buff;
    return in;
}

int main()
{
    MyString narayan{"Narayan"};
    MyString poudel{"Poudel"};
    MyString curly;

    cout << "Enter the third stooge's first name: ";
    cin >> curly;
    cout << "The three stooges are " << narayan << ", " << poudel << ",  and " << curly << endl;

    cout << "\n Enter the three stooges names seperated by a space: ";
    cin >> narayan >> poudel >> curly;

    cout << "The three stooges are: " << narayan << ", " << poudel << ", and " << curly << endl;
    return 0;
}