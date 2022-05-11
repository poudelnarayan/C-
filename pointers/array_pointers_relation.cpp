#include <iostream>
using namespace std;

int main()
{
    int scores[]{100, 95, 89};
    // scores variable always stores the address of the first element of the array

    cout << scores << endl;
    cout << *scores << endl;
    // defrencing score variable gives the value of the first element of the array as it stores the address of it

    int *score_ptr{scores};
    // initialiazing the pointer to the score stores the address of the score to the pointer
    cout << score_ptr << endl; // gives same address as scores

    cout << *score_ptr << endl; // gives the same value as *scores

    // PRINTING THE VALUE OF THE ARRAYS

    cout << score_ptr[0] << endl; // --->> Subscript notation
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl;

    // PRINTING THE ADDRESS OF EACH ELEMENT OF ARRAY by pointer method
    cout << score_ptr + 0 << endl; // the pointer is incremented by 4 , as the pointer stores the int whose value is 4.
    cout << score_ptr + 1 << endl;
    cout << score_ptr + 2 << endl;

    // how the calculation formed is :
    // score_ptr[n] ====> score_ptr + n*4 -->> for integer pointer
    // or
    // scores[n] ===>> scores + n*4 --->> for integer

    // PRINTING THE ADDRESS OF EACH ELEMENT OF ARRAY by variable method
    cout << scores + 0 << endl;
    cout << scores + 1 << endl;
    cout << scores + 2 << endl;

    // DEREFERENCING THE ADDRESS OF THE MEMBERS from pointers
    cout << *(score_ptr + 0) << endl;
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr + 2) << endl;

    // DEREFERENCING THE ADDRESS OF THE MEMBERS from arrya varibale
    cout << *(scores + 0) << endl; // ---->> offset notation
    cout << *(scores + 1) << endl;
    cout << *(scores + 2) << endl;

    return 0;
}