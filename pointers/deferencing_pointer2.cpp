#include <iostream>

using namespace std;

int main()
{
    string name{"Narayan"};

    string *string_ptr{&name};

    cout << *string_ptr << endl;
    name = "poudel";
    cout << *string_ptr << endl;
}