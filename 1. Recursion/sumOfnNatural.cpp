#include <iostream>

using namespace std;

int sum(int n)
{
    int result = 0;
    if (n > 0)
    {
        result = sum(n - 1) + n;
        return result;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << "Sum Of First " << n << " Natural Number is " << sum(n);
    return 0;
}