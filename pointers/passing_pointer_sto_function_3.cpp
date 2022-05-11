#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<string> *const v) // *v is a pointer
{
    for (auto str : *v) // range based for loop, *v is dereferencing a pointer
    {
        cout << str << "";
        cout << endl;
    }
}

void display(int *array, int sentinel)
{
    while (*array != sentinel)
    {
        cout << *array++ << "";
        cout << endl;
    }
}

int main()
{

    vector<string> names{"narayan", "poudel"};
    display(&names);

    int scores[]{100, 200, 300, -1};
    display(scores, -1);

    return 0;
}