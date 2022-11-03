// Find Duplicates in Sorted Array using Hash
// it is also for unsorted Array

#include <iostream>

using namespace std;

int main()
{
    int max = 20;
    int size = 10;
    int A[size] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int H[21] = {0};

    for (int i = 0; i < size; i++)
    {
        H[A[i]]++;
    }

    for (int i = 0; i <= max; i++)
    {
        if (H[i] > 1)
        {
            cout << i << " " << H[i] << " times" << endl;
        }
    }

    return 0;
}