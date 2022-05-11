#include <iostream>
#include <cstring> // for c-style string function
#include <cctype>  // for character-based functions

using namespace std;

int main()
{
    char firstName[20]{};
    char lastName[20]{};
    char fullName[50]{};
    char fullName1[50]{};
    char fullName2[50]{};
    char temp[50]{};

    // cout << lastName << endl; // Will likely display garbage if not initialized

    cout << "Please enter your first name: ";
    cin >> firstName;
    cout << "please Enter your last name: ";
    cin >> lastName;

    cout << "-------------------" << endl;
    cout << "Hello, " << firstName << " your first name has " << strlen(firstName) << " characters " << endl;
    // strlen() returns size_t . it may be signed long or unsigned long or any int depending on system . It is good to use it rather than int .
    cout << "and your last name, " << lastName << " has " << strlen(lastName) << " characters" << endl;

    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);
    cout << "Your full name is " << fullName << endl;

    // cout << "-----------------" << endl;
    // cout << "enter your full name: ";
    // cin >> fullName1;
    // cout << "Your full name is : " << fullName1 << endl; // This will display only the first name (i.e name befor space. and this is a default behavious or extraction operator)

    cout << "-----------------" << endl;
    cout << "Enter your full name:(press # to complete) ";
    cin.getline(fullName2, 50, '#'); // 50 is the maximum limit of character the fullName2 will take
    // here #  is a delimiter
    cout << "your full name is: " << fullName2 << endl;

    for (size_t i{0}; i < strlen(fullName); i++)
    {
        if (isalpha(fullName[i]))
            fullName[i] = toupper(fullName[i]); // Converts every alphabets to capital and puts back in
    }
    cout << "Your full name is " << fullName << endl;

    return 0;
}
