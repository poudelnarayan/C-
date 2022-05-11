#include <iostream>

using namespace std;

int main()
{

    int high_score{100};
    int low_score{65};

    // POINTERS TO CONSTANT
    const int *score_ptr{&high_score}; // Pointers to constants
    cout << score_ptr << endl;
    cout << *score_ptr << endl;

    // for pointers to constants
    // The data pointed to by the pointer is constant and cannot be changed.
    // The pointer itself can change and point somewhere else

    // *score_ptr = 500;  Throws an error .Thw constant pointer pointing to any address cannot be changed.
    score_ptr = &low_score; // can be done in constant pointer .  Its address can be changed
    cout << score_ptr << endl;
    cout << *score_ptr << endl;

    // CONSTANT POINTERS
              
    int *const score_ptr2{&high_score}; // constant pointers
    *score_ptr2 = 86;
    // score_ptr2 = &low_score throws an error

    // for constant pointers
    // the data pointed to by the pointers can be changed.
    // the pointer itself cannot change and point somewhere else.

    // CONSTANT POINTERS TO CONSTANTS
    // the data pointed to by the pointer is constant and cannot be changed.
    // the pointer itself cannot change and point somewhere else

    const int *const score_ptr3{&high_score}; // CONSTANT POINTERS TO CONSTANTS
    // *score_ptr3  = 86;  throws an error
    // score_ptr3 = &low_score ; throws an error

    return 0;
}