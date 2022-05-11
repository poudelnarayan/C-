#include <iostream>

using namespace std;

void double_data(int *int_ptr)
{
    *int_ptr *= 2;
}

int main()
{
    int value{10};
    int *int_ptr{nullptr};
    cout << "value: " << value << endl;
    double_data(&value);
    cout << "value: " << value << endl;

    cout << "----------------" << endl;
    int_ptr = &value;
    double_data(int_ptr);
    cout << "value: " << value << endl;

    return 0;
}