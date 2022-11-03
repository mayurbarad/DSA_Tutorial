// Find Pair With Sum K Sorted Array

#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int k = 10;
    int A[n] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};

    int i = 0, j = n - 1;
    while (i < j)
    {
        if (A[i] + A[j] == k)
        {
            cout << A[i] << " + " << A[j] << endl;
            i++;
            j--;
        }
        else if (A[i] + A[j] < k)
            i++;
        else
            j--;
    }

    return 0;
}