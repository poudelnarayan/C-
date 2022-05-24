// Fibonacci number using recursive
// Fib(0) = 1
// Fib(1) = 1
// Fib(n) = Fib(n-1) + Fib(n-2)

// Base Case
// Fib(0) = 0
// Fib(1) = 1

// Recursive Case
// Fib(n) = Fib(n-1)+ Fib(n-2)

#include <iostream>

using namespace std;

unsigned long long fibonacci(unsigned long long number)
{
    if (number <= 1)
        return number;
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main()
{
    int i = 0;
    while (i < 5)
    {
        cout << fibonacci(i) << " ";
        i++;
    }
    return 0;
}
