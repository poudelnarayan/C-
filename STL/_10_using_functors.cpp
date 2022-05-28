/*
Example algorithm - for_each

*/

#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

struct SquareFunctor
{
    void operator()(int x)
    {
        cout << x * x << " ";
    }
};

int main()
{

    SquareFunctor square;

    vector<int> vec{1, 2, 3, 4};

    for_each(vec.begin(), vec.end(), square);

    return 0;
}
