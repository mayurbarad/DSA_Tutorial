#include <iostream>

using namespace std;

int main()
{
    // --> Using Hash
    // char A[] = "finding";
    // int H[26] = {0}, i;
    // for (i = 0; A[i] != '\0'; i++)
    //     H[A[i] - 97]++;
    // for (i = 0; i < 26; i++)
    // {
    //     if (H[i] > 1)
    //         cout << i + 97 << " " << H[i] << " times" << endl;
    // }

    char A[] = "finding";
    int H = 0, x = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97);
        if ((x & H) > 0)
            cout << A[i] << endl;
        else
            H = x | H;
    }

    return 0;
}