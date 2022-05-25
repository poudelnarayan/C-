/*
Using string streams

. Allow us to read or write from strings in memory such as we would read and write to files
. very powerful
. very useful for data validation

*/

/*
stringstream , istringstream and ostringstream

1. #include <sstream>
2. Declare an stringstream , istringstream or ostreamstring object
3. Connect it to a string
4. Read/Write/ data from/to the string stream using formatted I/O

*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    int num{};
    double total{};
    string name{};

    string info{"Narayan  100 23.43"};
    istringstream iss{info};

    iss >> name >> num >> total;

    cout << setw(10) << left << name
         << setw(5) << num
         << setw(10) << total << endl;

    cout << "\n -------------------" << endl;

    ostringstream oss{};

    oss << setw(10) << left << name
        << setw(5) << num
        << setw(10) << total << endl;

    cout << oss.str() << endl;

    cout << "\n ---------DATA VALIDATION----------" << endl;

    int value{};
    string entry{};
    bool done = false;

    do
    {
        cout << "Please enter an integer: ";
        cin >> entry;
        istringstream validator{entry};
        if (validator >> value)
            done = true;
        else
            cout << "Sorry , that's not an integer" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!done);

    cout << "You entered the integer " << value << endl;
    cout << endl;

    return 0;
}
