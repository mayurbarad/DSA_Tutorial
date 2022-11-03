// Count Duplicates in Sorted Array

#include <iostream>

using namespace std;

int main()
{
    int size = 10;
    int A[size] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};

    for (int i = 0; i < size; i++)
    {
        if (A[i] == A[i + 1])
        {
            int j = i + 1;
            while (A[i] == A[j])
            {
                j++;
            }
            cout << A[i] << " appearing " << j - i << " times" << endl;
            i = j - 1;
        }
    }

    return 0;
}