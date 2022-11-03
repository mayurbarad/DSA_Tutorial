// Find Pair With Sum K Unsorted Array

#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int A[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int k = 10;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == k)
            {
                cout << A[i] << " + " << A[j] << endl;
            }
        }
    }

    return 0;
}