// Find Max and Min in Single Scan

#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int A[n] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    int min, max;

    min = max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
        else if (A[i] > max)
        {
            max = A[i];
        }
    }

    cout << "min an max are : " << min << " and " << max << endl;

    return 0;
}