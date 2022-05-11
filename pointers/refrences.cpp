// Using refrences in range-based for loop
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Without using refrences
    vector<string> names{"Narayan", "Android", "Laptop"};
    for (auto str : names)
        str = "funny"; // changes the copy

    /*
    we didnt change the vector at all even though we assigned funny to each element in the loop.
    We're setting the copy to funny but we're never changing the actual element in the vector.
    */

    for (auto str : names)
        cout << str << endl; // same as names

    // With refrences
    vector<string> casts{"Poudel", "kharel", "sharma"};

    for (auto &str : casts)
        str = "Funny";

    for (auto const str : casts)
        cout << str << endl;

    return 0;
}