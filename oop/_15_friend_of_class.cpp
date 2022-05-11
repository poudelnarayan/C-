/*
We can also use a friend Class in C++ using the friend keyword. For example,

class ClassB;

class ClassA {
   / ClassB is a friend class of ClassA
   friend class ClassB;
   ... .. ...
}

class ClassB {
   ... .. ...
}

When a class is declared a friend class, all the member functions of the friend class become friend functions.

Since ClassB is a friend class, we can access all members of ClassA from inside ClassB.

However, we cannot access members of ClassB from inside ClassA. It is because friend relation in C++ is only granted, not taken.



*/

#include <iostream>

using namespace std;

// Forward declaration
class ClassB;

class ClassA
{
    int numA;
    // friend class declaration
    friend class ClassB;

public:
    ClassA() : numA{12} {};
};

class ClassB
{
private:
    int numB;

public:
    // constructor to initialize numB to 1
    ClassB() : numB(1) {}

    // member function to add numA
    // from ClassA and numB from ClassB
    int add()
    {
        ClassA objectA;
        return objectA.numA + numB;
    }
};

int main()
{
    ClassB objectB;
    cout << "Sum: " << objectB.add();
    return 0;
}
