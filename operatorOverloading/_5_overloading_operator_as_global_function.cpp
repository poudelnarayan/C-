#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend MyString operator-(const MyString &obj);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);

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

// Equality
bool operator==(const MyString &lhs, const MyString &rhs)
{
    return (strcmp(lhs.str, rhs.str) == 0);
}

// Make lowercase
MyString operator-(const MyString &obj)
{
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i = 0; i < strlen(buff); i++)
    {
        buff[i] = tolower(buff[i]);
    }
    MyString temp{buff};
    delete[] buff;
    return temp;
}

// Concatenation

MyString operator+(const MyString &lhs, const MyString &rhs)
{
    char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);

    MyString temp{buff};
    delete[] buff;
    return temp;
}

int main()
{
    MyString narayan{"Narayan"};
    narayan.display();

    narayan = -narayan;
    narayan.display();

    cout << boolalpha << endl;
    MyString poudel{"Poudel"};
    MyString stooge = narayan;

    cout << (narayan == poudel) << endl;
    cout << (narayan == stooge) << endl;

    MyString stooges = "Narayan" + poudel;
    stooges.display();

    MyString twoStooges = poudel + " " + "poudel";

    return 0;
}