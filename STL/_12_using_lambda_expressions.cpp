#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

int main()
{

    vector<int> vec{1, 2, 3, 4};

    for_each(vec.begin(), vec.end(),
             [](int x)
             { cout << x * x << " "; });

    return 0;
}

/*
In this example we use the lambda expression directly in the function call .
Lambda expressions were introduced in C++ 11 and widely used in modern C++. analogous to anonymous functions.

*/