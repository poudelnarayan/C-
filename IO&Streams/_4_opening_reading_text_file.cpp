#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile;
    string line;
    int num;
    double total;

    inFile.open("test2.txt");

    if (!inFile)
    {
        cerr << "The file doesnot exist" << endl;
        return 1;
    }

    // while (!inFile.eof())
    // {
    //     inFile >> line >> num >> total;

    //     cout << setw(10) << left << line
    //          << setw(10) << num
    //          << setw(10) << total
    //          << endl;
    // }

    // any of these works

    while (inFile >> line >> num >> total)
    {
        cout << setw(10) << left << line
             << setw(10) << num
             << setw(10) << total
             << endl;
    }

    inFile.close();

    return 0;
}