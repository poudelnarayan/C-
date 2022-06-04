// Program to transpose a 3x3 square matrix
#include <iostream>

using namespace std;

class Matrix
{
    int mat[3][3];
    int tMat[3][3];

public:
    Matrix(){};
    void setMatrix();
    void displayMatrix();
    void transpose();
    void displayTranspose();
};

void Matrix::setMatrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void Matrix::transpose()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tMat[i][j] = mat[j][i];
        }
    }
}

void Matrix::displayTranspose()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << tMat[i][j];
            cout << "\t";
        }
        cout << "\n";
    }
}

void Matrix::displayMatrix()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j];
            cout << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    Matrix a;

    cout << "Enter the element of (3x3) matrix : " << endl;
    a.setMatrix();
    cout << "your matrix is" << endl
         << endl;

    a.displayMatrix();
    cout << endl
         << "transposing your matrix..." << endl
         << endl;

    a.transpose();
    cout << "Transpose of a matrix" << endl
         << endl;

    a.displayTranspose();

    return 0;
}
