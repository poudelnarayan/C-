#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

void square(int x)
{
    cout << x * x << " ";
}

int main()
{

    vector<int> vec{1, 2, 3, 4};

    for_each(vec.begin(), vec.end(), square);
    // for_each(begin(vec) , begin(end) , square)

    return 0;
}
