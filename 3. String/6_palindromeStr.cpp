#include <iostream>

using namespace std;

int main()
{
    char A[] = "madam";
    int i = 0, j = 0;
    char B[6];
    while (A[i] != '\0')
        i++;
    i = i - 1;
    // Reverse String
    while (i >= 0)
    {
        B[j] = A[i];
        i--;
        j++;
    }
    B[j] = '\0';

    // Compare String
    i = j = 0;
    while (A[i] != '\0' && B[j] != '\0')
    {
        if (A[i] != B[j])
        {
            cout << "Not Palindrome";
            break;
        }
        i++;
        j++;
    }
    if (A[i] == B[j])
        cout << "Palindrome";

    return 0;
}