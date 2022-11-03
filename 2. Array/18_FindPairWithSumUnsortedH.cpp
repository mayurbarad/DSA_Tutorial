// Find Pair With Sum K Unsorted Array using Hash

#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int A[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int H[17] = {0};
    int k = 10;

    for (int i = 0; i < n; i++)
    {
        if (H[k - A[i]] != 0)
        {
            cout << A[i] << " + " << k - A[i] << endl;
        }
        H[A[i]]++;
    }

    return 0;
}