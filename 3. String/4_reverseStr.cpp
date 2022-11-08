#include <iostream>

using namespace std;

int main()
{
    char A[] = "Python";
    int i = 0, j = 0;
    while (A[j] != '\0')
        j++; // -> j = 6 at null char

    j = j - 1; // -> j=5 at n (last char)
    while (i < j)
    {
        char temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }

    cout << A;

    return 0;
}