#include <iostream>

using namespace std;

void print_array(const int number[], size_t size);

int main()
{
    int my_numbers[]{1, 2, 3, 4, 5};
    print_array(my_numbers, 5);
    return 0;
}

void print_array(const int numbers[], size_t size)
{
    // Does'nt know how many elements are in the array
    // wee need to pass in the size!!!

    for (size_t i{0}; i < size; i++)
        cout << numbers[i] << endl;
}