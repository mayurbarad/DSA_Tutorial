// Find Duplicates in Sorted Array

#include <iostream>

using namespace std;

int main()
{
    int size = 10;
    int A[size] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int lastD = 0; // Last Duplicate

    for (int i = 0; i < size; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastD)
        {
            cout << A[i] << endl;
            lastD = A[i];
        }
    }

    return 0;
}