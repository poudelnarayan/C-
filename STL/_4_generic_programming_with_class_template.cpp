/*
Similar to function template , but at the class level
Allows plugging-in any type
Compiler generates the appropriate class from the blueprint

*/
/*
why to use this?
    We'd like our Item class to be able to hold any type of data in addition to the string
    We can't overload class names
    We dont want to use dynamic polymorphism

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Template classes are typically completely contained in header files

template <typename T>
class Item
{
private:
    string name;
    T value;

public:
    Item(string name, T value) : name{name}, value{value} {}
    string getName() const { return name; }
    T getValue() const { return value; }
};

template <typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
};

int main()
{
    Item<int> item1{"Narayan", 100};
    cout << item1.getName() << " " << item1.getValue() << endl;

    Item<string> item2{"Poudel", "Engineer"};
    cout << item2.getName() << " " << item2.getValue() << endl;

    Item<Item<string>> item3{"Narayan", {"C++", "Programmer"}};
    cout << item3.getName() << " " << item3.getValue().getName() << " " << item3.getValue().getValue() << endl;

    cout << " ================" << endl;
    vector<Item<double>> vec{};
    vec.push_back(Item<double>("Narayan", 100.0));
    vec.push_back(Item<double>("Poudel", 200.0));
    vec.push_back(Item<double>("Moe", 300));

    for (const auto &item : vec)
    {
        cout << item.getName() << " " << item.getValue() << endl;
    }

    MyPair<string, int> p1{"Frank", 100};
    MyPair<int, double> p2{124, 6.56};
    cout << p1.first << " , " << p1.second << endl;
    cout << p2.first << " , " << p2.second << endl;

    return 0;
}