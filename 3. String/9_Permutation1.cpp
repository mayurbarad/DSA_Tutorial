#include <iostream>

using namespace std;

void Per(char S[], int k)
{
    static int A[4] = {0};
    static char res[4];
    int i;

    if (S[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
    }
    else
    {
        for (i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                res[k] = S[i];
                A[i] = 1;
                Per(S, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    char S[] = "ABC";
    Per(S, 0);

    return 0;
}