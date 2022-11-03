#include <iostream>

using namespace std;

double e(int x, int n)
{

    double p = 1, f = 1, result;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        result = e(x, n - 1);

        p = p * x;
        f = f * n;

        return result + p / f;
    }
}

int main()
{
    int n, x;
    cout << "Enter n : ";
    cin >> x >> n;
    cout << e(x, n);
}