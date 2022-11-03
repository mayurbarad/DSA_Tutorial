#include <iostream>

using namespace std;

int pow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return m * pow(m, n - 1);
    }
}

// Multiplication Process Reduced By half

/* int pow(int m, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return pow(m * m, n / 2);
    else
        return m * pow(m * m, (n - 1) / 2);
}

*/

int main()
{
    int m, n;
    cout << "Enter m and n : " << endl;
    cin >> m >> n;
    cout << m << " to the Power " << n << " is " << pow(m, n);
    return 0;
}