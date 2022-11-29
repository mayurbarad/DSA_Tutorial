// Initialisation of 2D Array

#include <iostream>

using namespace std;

// How to initialise 2D ARRAY

int main()
{
    // Method (1) --> Inside STACK Memory
    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Method (2) --> Inside HEAP Memory
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    delete[] B;

    // Method (3) --> Inside HEAP Memory
    int **C;
    C = new int *[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];
    delete[] C;
}