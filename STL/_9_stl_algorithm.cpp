/*
Algorithms

.STL algorithms work on sequences of container elements provided to them by an iterator.
.STL has many common and useful algorithms
.https://en.cppreference.com/w/cpp/algorithm
.Many algorithm require extra information in order to do their work
    Functors(function objects)
    Function pointers
    Lambda expressions(C++11)

*/

/*
Example algorithm- find with primitive types

.The find algorithm tries to locate the first occurance of an element in a container.
.Lots of variations
.Returns an iterator pointing to the located element or wnd()

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> vec{1, 2, 3};
    auto loc = find(vec.begin(), vec.end(), 3);
    if (loc != vec.end())
        cout << *loc << endl;

    return 0;
}

/*
Remember  find needs to be able to compare two elements in order to see if they're the same. In order to do this it will
use the equality operator. For primitive types like ints we dont have to do a thing since the compiler knows how to compare
primitive types.
But if we're using our own user defined objects in containers then we must provide the overloaded equality operator for our objects
since that's what the algorithm will call.
*/
