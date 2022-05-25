/*
Output files(fstream and ofstream)

fstream and ofstream are commonly used for output files

Steps:

1. #include <fstream>
2. Declare an fstream od fstream object
3. Connect it to a file on your file system(opens it for writing) (by default C++ will create a file if it doesnot exist)
4. Write data to the file via the stream
5. close the stream

*/

/*
.   Output files will be create if they don't exist
.   Output files will be overwritten by default
.   Can be opened so that new writes append
.   Can be open in text or binary modes
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // ofstream outFile("output.txt");           // opens in write mode
    ofstream outFile("output.txt", ios::app); // opens in append mode

    if (!outFile)
    {
        cerr << "ERROR CREATING FILE" << endl;
        return 1;
    }
    string line;
    cout << "Enter something: ";
    getline(cin, line);
    outFile << line << endl;
    outFile.close();

    return 0;
}
