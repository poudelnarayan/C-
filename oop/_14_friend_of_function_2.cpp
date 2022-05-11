#include <iostream>

using namespace std;

class ClassB; // forward declaration

class ClassA
{
    int numA;
    friend int add(ClassA, ClassB); // friend function declaration

public:
    ClassA() : numA{12} {} // constructor to initialize numA to 12
};

class ClassB
{
    int numB;
    friend int add(ClassA, ClassB); // friend function declaration

public:
    ClassB() : numB(1) {}
};

// access members of both classes
int add(ClassA objectA, ClassB objectB)
{
    return objectA.numA + objectB.numB;
}

int main()
{
    ClassA objectA;
    ClassB objectB;
    cout << "Sum: " << add(objectA, objectB);

    return 0;
}