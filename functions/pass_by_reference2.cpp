// Swap two number using pass by reference

#include <iostream>

using namespace std;

void swap(int &a, int &b);

int main()
{
    int x{0}, y{0};
    cout << "enter the value of x: " << endl;
    cin >> x;
    cout << "enter the value of y: " << endl;
    cin >> y;
    cout << "Value before swapping : " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    swap(x, y);
    cout << "value after swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
