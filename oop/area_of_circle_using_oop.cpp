// Area of circle using OOP

#include <iostream>

using namespace std;

class Circle
{
private:
    double radius;

public:
    Circle(double r) : radius{r} {}
    void setRadius(double r)
    {
        radius = r;
    }
    double getRadius()
    {
        return radius;
    }
};

class Utility
{
public:
    double calculateArea(Circle c)
    {
        double radius = c.getRadius();
        return 3.14 * radius * radius;
    }
};

int main()
{
    double radius = 0.0;
    cout << "Enter the radius (in cm)" << endl;
    cin >> radius;

    Circle obj(radius);
    Utility u;
    double area = u.calculateArea(obj);
    cout << "The area is : " << area << " cm square" << endl;

    return 0;
}