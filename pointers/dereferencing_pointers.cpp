#include <iostream>

using namespace std;

int main()
{
    int score{100};
    int *score_ptr{&score};

    cout << *score_ptr << endl; // deferencing a pointer

    *score_ptr = 200;
    cout << *score_ptr << endl;
    cout << score << endl;
}

// during initializing and deferencing a point we use "*" ; yeah its quite confusing but it is what it  is .