// WAP to add complex number using operator overloading

#include <iostream>
#include <iomanip>

using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    Complex()
    {
        real = imag = 0.0;
    }
    Complex(float x, float y)
    {
        real = x;
        imag = y;
    }

    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    bool operator==(Complex);

    void getData()
    {
        cout << "(" << fixed << setprecision(2) << real << " + " << imag << "j )" << endl;
    }
};

Complex Complex::operator+(Complex c2)
{
    Complex temp;
    temp.real = real + c2.real;
    temp.imag = imag + c2.imag;
    return temp;
}

Complex Complex::operator-(Complex c2)
{
    Complex temp;
    temp.real = real - c2.real;
    temp.imag = imag - c2.imag;
}

Complex Complex::operator*(Complex c2)
{
    Complex temp;
    temp.real = (this->real * c2.real) - (this->imag * c2.imag);
    temp.imag = (this->real * c2.imag) + (this->imag * c2.real);
    return temp;
}

bool Complex::operator==(Complex c2)
{
    return (this->real == c2.real && this->imag == c2.imag) ? true : false;
}

int main()
{
    Complex c1(9.0, 6.0), c2(9.0, 6.0), c3, c4, c5;
    c1.getData();
    c2.getData();
    c3 = c1 + c2;
    c3.getData();
    c4 = c1 - c2;
    c4.getData();
    c5 = c1 * c2;
    c5.getData();
    cout << boolalpha;
    cout << (c1 == c2) << endl;

    return 0;
}