/*
where C-style string cannot grow and shrink  with our requirement easily
C++ style string can grow and shrink easily.

unlike C-style string C++ string are always initialized to empty value by default.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // The ways of assigning a value to string
    string s1;               // Empty
    string s2{"Narayan"};    // Narayan
    string s3{s2};           // Narayan
    string s4{"Narayan", 3}; // Nar
    string s5{s3, 2, 4};     // raya
    // here 2 is the index and 4 is the no. of character
    string s6(3, 'X'); // XXX
    string s7;

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;

    // Assignment
    s1 = "C++ Rocks";
    s7 = s1;
    cout << s1 << endl;
    cout << s7 << endl;

    // Concatenation
    string part1{"C++"};
    string part2{"is a powerful"};
    string sentence;

    sentence = part1 + " " + part2 + " language";

    // sentence = "c++"+" is powerful"; //Illegal
    /*
        it is illegal beacause we have two c-style literals and
        we can't concatenate C-style literals.
        It only workd with C++ strings.

        But the combination of c++ string and c-style string is okay as in line 42.

    */
    cout << "------" << endl;
    cout << s2 << endl;
    cout << s2[0] << endl;
    cout << s2.at(0) << endl;
    s2[0] = 'f';
    cout << s2 << endl;
    s2.at(0) = 'd';
    cout << s2 << endl;

    cout << "------" << endl;

    for (char c : s2)
        cout << c << endl;

    cout << "------" << endl;
    for (int c : s2)
        cout << c << endl;

    cout << "------" << endl;

    // Comparing
    string str1{"Apple"};
    string str2{"Banana"};
    string str3{"Kiwi"};
    string str4{"apple"};
    string str5{str1};

    cout << boolalpha;
    cout << (str1 == str5) << endl;
    cout << (str1 == str2) << endl;
    cout << (str1 != str2) << endl;
    cout << (str1 < str2) << endl;
    cout << (str1 > str2) << endl;
    cout << (str1 == "Apple") << endl; // In this case "Apple" is a c-style string literal

    // Substring method
    // it doesnot  change the string but returns the substring of the given string

    string test{"This is a test"};

    cout << test.substr(0, 4) << endl;
    cout << test.substr(3, 5) << endl;
    cout << test.substr(10, 4) << endl;

    // Substring - find()

    cout << test.find("This") << endl;
    cout << test.find("is") << endl;
    cout << test.find("test") << endl;
    cout << test.find('e') << endl;
    cout << test.find("is", 4) << endl;
    // here 4 is the index from where search should be done
    cout << test.find("xxx"); // garbege or error

    // Removing character - erase() and clear()
    // removes a substring of character from a std:: string

    cout << test.erase(0, 5) << endl;

    cout << test.erase(5, 4) << endl;
    cout << test << endl;
    test.clear();
    cout << test << endl;

    return 0;
}