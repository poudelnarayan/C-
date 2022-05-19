// Pure virtual functions and abstract classes

/*
Abstract class
    cannot instantiate objects
    These classes are used as base classes in inheritance hierarchies
    Often referred to as Abstract Base Classes
    contains at least one pure virtual function

Concrete Class
    Used to instantiate object from
    All their member functions are defined


*/

#include <iostream>
#include <vector>

using namespace std;

class Shape // Abstract Base Class
{
private:
    // attributes common to all shapes
public:
    virtual void draw() = 0;
    virtual void rotate() = 0;
    virtual ~Shape() {}
};

class OpenShape : public Shape // Abstract class (since it doesnot override the methods of shape)
{
public:
    virtual ~OpenShape() {}
};

class ClosedShape : public Shape
{ // Abstract class (since it doesnot override the methods of shape)
public:
    virtual ~ClosedShape(){};
};

class Circle : public ClosedShape // Concrete Class (since it overrides a methods of abstract base class )
{
public:
    virtual void draw() override
    {
        cout << "Drawing a circle" << endl;
    }
    virtual void rotate() override
    {
        cout << "Rotating a circle" << endl;
    }
    virtual ~Circle(){};
};

class Square : public ClosedShape // Concrete class
{
public:
    virtual void draw() override
    {
        cout << "Drawing a square" << endl;
    }
    virtual void rotate() override
    {
        cout << "Rotating a square " << endl;
    }
    virtual ~Square(){};
};

class Line : public OpenShape
{
public:
    virtual void draw() override
    {
        cout << "Drwing a line" << endl;
    }
    virtual void rotate() override
    {
        cout << "Rotating a line" << endl;
    }
    virtual ~Line(){};
};

void screenRefresh(const vector<Shape *> &shapes)
{
    cout << "Refreshing" << endl;
    for (const auto p : shapes)
        p->draw();
}
int main()
{
    Circle c;
    c.draw();

    Shape *ptr = new Circle();
    ptr->draw();
    ptr->rotate();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();

    vector<Shape *> shapes{s1, s2, s3};

    // for (const auto p : shapes)
    //     p->draw();
    screenRefresh(shapes);

    delete ptr;
    delete s1;
    delete s3;

    return 0;
}