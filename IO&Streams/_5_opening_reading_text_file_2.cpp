#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream inFile;
    string line;
    char c{};

    inFile.open("poem.txt");

    if (!inFile)
    {
        cerr << "The file doesnot exist" << endl;
        return 1;
    }
    while (std::getline(inFile, line))
    {
        cout << line << endl;
    }
    // unformatted input
    while (inFile.get(c))
    {
        cout << c;
    }

    inFile.close();

    return 0;
}