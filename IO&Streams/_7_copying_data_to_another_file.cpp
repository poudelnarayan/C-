#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inFile("poem.txt");
    ofstream outFile{"poem_out.txt"};
    string line;

    if (!inFile)
    {
        cerr << "Error opening input file" << endl;
        return 1;
    }
    if (!outFile)
    {
        cerr << "Error opening output file" << endl;
        return 1;
    }
    while (getline(inFile, line))
    {
        outFile << line << endl;
    }

    cout << "File copied" << endl;
    inFile.close();
    outFile.close();

    return 0;
}