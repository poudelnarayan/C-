// factorial of a number using a recursion

#include <iostream>

using namespace std;

unsigned long long factorial(unsigned long long num)
{
    if (num == 0)
        return 1;
    return num * factorial(num - 1);
}

int main()
{
    cout << factorial(3) << endl;
    return 0;
}