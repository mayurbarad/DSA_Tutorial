#include <iostream>

using namespace std;

int fact(int n)
{
    int result = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        result = fact(n - 1) * n;
        return result;
    }
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << "Factorial Of " << n << " is " << fact(n);
    return 0;
}