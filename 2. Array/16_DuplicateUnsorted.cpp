// Find Duplicate in Unsorted Array

#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int A[n] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int count;

    for (int i = 0; i < n - 1; i++)
    {
        count = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
            if (count > 1)
            {
                cout << A[i] << " " << count << " times" << endl;
            }
        }
    }

    return 0;
}