// Find Missing Element

#include <iostream>

using namespace std;

int main()
{
    int l = 1, h = 12; // lowest and highgest value
    int A[10] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int H[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        H[A[i]]++;
    }

    for (int i = l; i <= h; i++)
    {
        if (H[i] == 0)
        {
            cout << i << endl;
        }
    }

    return 0;
}