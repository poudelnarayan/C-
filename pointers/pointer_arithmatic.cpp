#include <iostream>

using namespace std;

int main()
{

    int scores[]{100, 95, 89, 68, -1};
    int *score_ptr{scores};

    // printing the array using sentinel value
    while (*score_ptr != -1) // here -1 is a sentinel value
    {
        cout << *score_ptr << endl;
        score_ptr++;
    }

    // COMPARING THE POINTERS
    string s1{"Narayan"};
    string s2{"Narayan"};
    string s3{"Poudel"};

    string *p1{&s1};
    string *p2{&s2};
    string *p3{&s1};

    cout << boolalpha; // makes the output true or flase instead of 0 or 1
    cout << p1 << " == " << p2 << ": " << (p1 == p2) << endl;
    cout << p1 << " == " << p3 << ": " << (p1 == p3) << endl;

    cout << *p1 << " == " << *p2 << ": " << (*p1 == *p2) << endl;
    cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl;

    p3 = &s3;
    cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl;

    // Subtracting the pointers

    char name[]{"abcdef"};

    char *char_ptr1{nullptr};
    char *char_ptr2{nullptr};

    char_ptr1 = &name[0];
    char_ptr2 = &name[3];

    cout << "In the string " << name << " , " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1) << " characters away from " << *char_ptr1 << endl;

    return 0;
}

/*

(++) increments a pointer to point to the next array element
int_ptr++;

(--) decrements a pointer to point to the previous array element
int_ptr--;

(+) increment pointer by n* sizeof(type)
int_ptr += n ; or int+ptr = int_ptr + n;

(-) decrement pointer by n* sizeof(type)
int_ptr -= n; or int_ptr = int_ptr -n;

also we can subtract the pointer and check for the equality of pointer


*/