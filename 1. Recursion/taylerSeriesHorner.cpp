#include <iostream>

using namespace std;

int e(int x, int n)
{
    static int s = 1;
    if (n == 0)
        return s;
    else
    {
        s = 1 + x / n * s;
        return e(x, n - 1);
    }
}

int main()
{
    int x, n;
    cout << e(2, 3);
}