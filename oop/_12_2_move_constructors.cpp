#include <iostream>
#include <vector>

using namespace std;

void func(int &num) // it wants an l-value
{
    cout << num << endl;
}
void func2(int &&num) // it wants an R-value
{
    cout << num << endl;
}
void func(int &&num) // Function overloading
{
    cout << num << endl;
}

void rValueLvalue()
{
    int x{100};
    cout << &x << endl;
    int &l_ref = x; // l-value refrence
    cout << l_ref << endl;

    cout << &l_ref << endl;
    cout << &x << endl;
    cout << x << endl;

    l_ref = 10; // change x to 10

    int &&r_ref = 200; // r-value ref
    r_ref = 300;       // change r_ref to 300

    // int &&x_ref = x;   // ERROR

    {
        int y{100}; // y is a L-value

        func(y);
        // func(200);  // ERROR
        func2(200);
        // func2(y); // ERROR
    }
}

class Move
{
private:
    int *data; // raw  pointer

public:
    void setDataValue(int d) { *data = d; }
    int getDataValue() { return *data; };
    Move(int);                // constructor
    Move(const Move &source); // copy constructor
    Move(Move &&source);      // Move Constructor (it doesnot contains const qualifier and it used R-value)
    ~Move();
};

Move::Move(int d)
{
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

Move::Move(const Move &source)
    : Move(*source.data)
{
    cout << "Copy constructor -deep copy for: " << *data << endl;
}

Move::Move(Move &&source)
    : data{source.data}
{
    source.data = nullptr;
    cout << "Move constructor -Moving resource: " << *data << endl;
}

Move::~Move()
{
    if (data != nullptr)
    {
        cout << "Destructor freeing data for : " << *data << endl;
    }
    else
    {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

int main()
{
    // rValueLvalue();

    vector<Move> vec;
    vec.push_back(Move{10});
    vec.push_back(Move{20});
}

/*
MOVE CONSTRUCTORS

sometimes when we execute code the compiler creates unnamed temporary values

int total{0};
total = 100+200;

. 100+200 is evaluated and 300 is stored in an unnamed temp value(not addressable so R-value)
. the 300 is then stored in the variable total
. then the temp value is discarded
. total is addressable so it is L value

.The same happens with objects as well

However with objects that can be great amount of overhead of copy constructors are called over and over again.
Making copies of this temporary objects.
Then when we have raw pointers and we have to do deep copied the overhead is even greater.
This is where move semantics and move constructor comed into the picture.

R-value objects are the objects that move semantics addresses.

*/

/*
When is it useful?

. Sometimes copy constructors are called many times automatically due to the copy semantics of C++
. Copy constructors doing deep copying can have a significant performance bottleneck.
. C++11 introduced move semantics and move constructors.
. Move constructor moves an object rather than copy it.
. Optional but recommended when you have a raw pointer(when you do deep copy)

*/

/*
we know that copy constructors are called whenever the compiler needs to make a copy of an object .
We also know that if our class contains a raw pointer then we must implement deep copy.
However this can be computationally expensive since we have to allocate space for the copy and then
copy the data over. THe C++ move constructor moves the object rather than copies it .
This cana be extremely efficient.

Move constructors are optional . If you dont provide them then the copy constructor will be called. But
it's a good idea to use move constructors for efficiency.

*/