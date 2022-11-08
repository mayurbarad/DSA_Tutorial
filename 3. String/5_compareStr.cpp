#include <iostream>

using namespace std;

int main()
{
    char A[] = "Painter";
    char B[] = "Painting";
    int i = 0, j = 0;
    while (A[i] != '\0' && B[j] != '\0')
    {
        if (A[i] != B[j])
            break;
        i++;
        j++;
    }

    if (A[i] == B[j])
        cout << "Both Equal";
    else if (A[i] < B[j])
        cout << "Not Equal and A is Smaller";
    else
        cout << "Not Equal and A is Bigger";

    return 0;
}