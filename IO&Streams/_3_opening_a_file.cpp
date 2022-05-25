/*
Input files (fstream and ifstream)

fstream and ifstream are commonly used for input files
fstream allows read only and ifstream allows read and write both

Steps:

1. #include <fstream>
2. Declare an fstream or ifstream object
3. Connect it to a fiole on your file system (opens it for reading)
4. Read data from the file via the stream
5. Close the stream


*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream inFile;
    string line;
    int num;
    double total;

    inFile.open("test.txt");

    if (!inFile) // if(!inFile.is_open())
    {
        cerr << "The file doesnot exist" << endl;
        return 1;
    }
    inFile >> line >> num >> total; // analogy to cin >> line;

    cout << line << endl;
    cout << num << endl;
    cout << total << endl;

    inFile.close();

    return 0;
}