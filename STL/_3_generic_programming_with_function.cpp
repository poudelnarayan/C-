#include <iostream>
#include <string>

using namespace std;

template <typename T>
T min_(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}

struct Person
{
    string name;
    int age;
    bool operator<(const Person &rhs) const // overloading
    {
        return this->age < rhs.age;
    }
};

ostream &operator<<(ostream &os, const Person &p)
{
    os << p.name;
    return os;
}

template <typename T>
void swap_(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x{100};
    int y{200};
    swap_(x, y);

    cout << x << " ," << y << endl;

    Person p1{"Narayan", 80};
    Person p2{"Poudel", 30};

    Person p3 = min(p1, p2);
    cout << p3.name << " is yonger" << endl;

    cout << min_<int>(2, 3) << endl;
    cout << min_(2, 3) << endl;
    cout << min_('A', 'B') << endl;
    cout << min_(2.4, 3.6) << endl;
    cout << min_(2 + 2 * 3, 3 + 4 * 9) << endl;

    func(p1, p2);

    func<int, int>(10, 20);
    func(10, 20);
    func<char, double>('A', 12.4);
    func(100, "testing");
    func(2000, string{"Narayan"});

    return 0;
}