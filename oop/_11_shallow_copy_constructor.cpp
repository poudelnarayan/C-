/*
Default Copy Constructor

.member wise copy
.Each data member is copied from the source object
.The pointer is copied NOT what it points to (shallow copy)


PROBLEM:
    when we release the storage in the destructor, the other object
    still refers to the released storage!

*/
#include <iostream>

using namespace std;

class Shallow
{
private:
    int *data;

public:
    void setDataValue(int d) { *data = d; }
    int getDataValue() { return *data; }
    // Constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    // Destructor
    ~Shallow();
};

Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source)
    : data(source.data)
{
    cout << "Copy Constructor - Shallow copy" << endl;
}

Shallow::~Shallow()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void displayShallow(Shallow s)
{
    cout << s.getDataValue() << endl;
}

int main()
{
    Shallow obj1{100};
    displayShallow(obj1);

    Shallow obj2{obj1};
    displayShallow(obj2);

    return 0;
}