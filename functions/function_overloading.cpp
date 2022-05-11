#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(int);
void print(double);
void print(string);  
void print(string, string);
void print(vector<string>);

void print(int num)
{
    cout << "Printing int: " << num << endl;
}

void print(double num)
{
    cout << "Printing  double: " << num << endl;
}

void print(string name)
{
    cout << "Printing string: " << name << endl;
}

void print(string name, string cast)
{
    cout << "Printing string,string : " << name + " " << cast << endl;
}

void print(vector<string> myVector)
{
    cout << "printing vector of strings: ";
    for (string S : myVector)
        cout << S + "";
    cout << endl;
}

int main()
{
    string myName = "Narayan";
    print(100);
    print('A'); // character is always promoted to int and should print 65 ASCII('A')
    print(123.3);
    print(123.4F); // Float is promoted to double
    print(" Hello ");
}