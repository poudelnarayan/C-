#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;
class Person
{
    string name;
    int age;

public:
    Person() = default;
    Person(string name, int age) : name{name}, age{age} {};
    bool operator<(const Person &rhs) const { return this->age < rhs.age; }
    bool operator==(const Person &rhs) const { return (this->name == rhs.name && this->age == rhs.age); }
};

// Find an element in a container
void findTest()
{

    cout << "==================" << endl;

    vector<int> vec{1, 2, 3, 4};
    auto loc = find(begin(vec), end(vec), 1);
    if (loc != end(vec))
        cout << "Found the number: " << *loc << endl;
    else
        cout << "Couldn't find the number" << endl;

    list<Person> players{
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21},
    };

    auto loc1 = find(players.begin(), players.end(), Person("Moe", 20));

    if (loc1 != players.end())
        cout << "Found Moe" << endl;
    else
        cout << "Moe not found" << endl;
}

// Count the number of element in a container
void countTest()
{
    cout << "==================" << endl;

    vector<int> vec{1, 2, 3, 4, 1};

    int num = count(vec.begin(), vec.end(), 1);
    cout << num << " occurences found" << endl;
}

void countIfTest()
{
    cout << "==================" << endl;

    vector<int> vec{1, 2, 4, 5, 6, 7, 8, 5, 4, 3, 6, 77, 53, 545, 25};

    // count only if the element is even
    int evenNum = count_if(vec.begin(), vec.end(),
                           [](int x)
                           { return x % 2 == 0; });

    // count only if the element is odd
    int oddNum = count_if(vec.begin(), vec.end(),
                          [](int x)
                          { return x % 2 != 0; });

    int numGreaterThan5 = count_if(vec.begin(), vec.end(),
                                   [](int x)
                                   { return x > 5; });

    cout << evenNum << " even numbers found" << endl;
    cout << oddNum << " odd numbers found" << endl;
    cout << numGreaterThan5 << " numbers are greater than 5" << endl;
}

// Replace occurances of element in a container
void replaceTest()
{
    cout << "==================" << endl;
    vector<int> vec{1, 2, 3, 4, 5, 6, 1, 2, 1, 3};
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    replace(vec.begin(), vec.end(), 1, 100);
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}

void allOfTest()
{
    cout << "==================" << endl;
    vector<int> vec{1, 2, 3, 4, 5, 6, 1, 2, 1, 3};

    if (all_of(vec.begin(), vec.end(), [](int x)
               { return x > 10; }))
    {
        cout << "All the elements are greater than 10" << endl;
    }
    else
    {
        cout << "Not all the elements are greater than 10" << endl;
    }

    if (all_of(vec.begin(), vec.end(), [](int x)
               { return x < 10; }))
    {
        cout << "All the elements are < 20" << endl;
    }
    else
    {
        cout << "Not all the elements are < 20" << endl;
    }
}

void stringTransformTest()
{
    cout << "==================" << endl;
    string str1{"This is a test"};
    cout << "Before transform: " << str1 << endl;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper); // ::toupper is a global scope
    cout << "After transform : " << str1 << endl;
}

int main()
{

    findTest();
    countTest();
    countIfTest();
    replaceTest();
    allOfTest();
    stringTransformTest();
    return 0;
}