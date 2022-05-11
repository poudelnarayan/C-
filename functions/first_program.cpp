#include <iostream>

using namespace std;

void param_test(int formal) // formal is a copy of actual
{
    cout << formal << endl;
    formal = 100; // only changes the local copy
    cout << formal << endl;
}

int main()
{
    int actual{50};
    cout << actual << endl;
    param_test(actual);
    cout << actual << endl;
    return 0;
}

// :: --> scope resulation operator
// >> --> extraction operator
// << --> insertion operator
