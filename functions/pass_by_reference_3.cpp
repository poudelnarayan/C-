// Printing vector by pass by reference

#include <iostream>
#include <vector>
using namespace std;
// Pass by reference has a flaw. that is the local variable scoped to
// main function can also be changed by outer function. so we add const in front of variable to restrict it from changing
void print(const vector<int> &v);

static int value{10};
int main()
{
    vector<int> data{1, 2, 3, 4, 5};
    print(data);

    return 0;
}

void print(const vector<int> &v)
{ // v.at(0) = 200 ; throws an error
    for (auto num : v)
        cout << num << endl;
}