#include <iostream>

using namespace std;

class Deep
{
private:
    int *data;

public:
    void setDataValue(int d) { *data = d; }
    int getDataValue() { return *data; }
    // Constructor
    Deep(int d);
    // Copy COnstructor
    Deep(const Deep &source);
    // Destructor
    ~Deep();
};
Deep::Deep(int d)
{
    data = new int;
    *data = d;
}

Deep::Deep(const Deep &source)
// : data(source.data)
{
    data = new int;
    *data = *source.data;
    cout << "Copy Constructor - Deep copy" << endl;
}
// or
//  DELEGATING:::

Deep::Deep(const Deep &source)
    : Deep{*source.data} // -->> delegating
{

    cout << "Copy Constructor - Deep copy" << endl;
}

Deep::~Deep()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void displayDeep(Deep s)
{
    cout << s.getDataValue() << endl;
}

int main()
{
    Deep obj1{100};
    displayDeep(obj1);

    Deep obj2{obj1};
    displayDeep(obj2);

    return 0;
}