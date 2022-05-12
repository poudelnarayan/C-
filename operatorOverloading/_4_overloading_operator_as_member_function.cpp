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

    void display() const;
    int get_length() const; // Getters
    const char *get_str() const;

    MyString operator-() const;                    // overloaded - operator(makes lowercase);
    MyString operator+(const MyString &rhs) const; // overloaded + operator(concatenate)
    bool operator==(const MyString &rhs) const;
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

void MyString::display() const
{
    cout << str << ":" << get_length() << endl;
}

// Length getter
int MyString::get_length() const { return strlen(str); }

// string getter
const char *MyString::get_str() const { return str; }

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

// Equality
bool MyString::operator==(const MyString &rhs) const
{
    return (strcmp(str, rhs.str) == 0);
}

// Make lowercase
MyString MyString::operator-() const
{
    char *buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i = 0; i < strlen(buff); i++)
    {
        buff[i] = tolower(buff[i]);
    }
    MyString temp{buff};
    delete[] buff;

    return temp;
}

// Concatenate
MyString MyString::operator+(const MyString &rhs) const
{
    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    MyString temp{buff};
    delete[] buff;
    return temp;
}

int main()
{
    cout << boolalpha << endl;

    MyString narayan{"Narayan"};
    MyString poudel{"Poudel"};

    MyString stooge = narayan;
    narayan.display();
    poudel.display();

    cout << (narayan == poudel) << endl;
    cout << (narayan == stooge) << endl;

    narayan.display();
    MyString narayan2 = -narayan;
    narayan2.display();

    MyString stooges = narayan + "Moe"; // ok with member
    // MyString stooges = "Narayan" + "Moe" // Compile error

    MyString twoStooges = poudel + " " + "Narayan";
    twoStooges.display();

    MyString threeStooges = poudel + " " + narayan + " " + "Curly";
    threeStooges.display();

    return 0;
}