#include <iostream>

using namespace std;

class LTMatrix
{
private:
    int n;
    int *A;

public:
    LTMatrix()
    {
        int n = 2;
        A = new int[(2 * (2 - 1)) / 2];
    }
    LTMatrix(int n)
    {
        this->n = n;
        A = new int[(n * (n - 1)) / 2];
    }
    ~LTMatrix()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void LTMatrix::Set(int i, int j, int x)
{
    if (i >= j)
    {
        int index = (i * (i - 1) / 2) + (j - 1);
        A[index] = x;
    }
}

int LTMatrix::Get(int i, int j)
{
    if (i == j)
        return A[(i * (i - 1)) / 2 + (j - 1)];
    else
        return 0;
}

void LTMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[(i * (i - 1)) / 2 + (j - 1)];
            else
                cout << 0;
        }
        cout << endl;
    }
}

int main()
{
    int n; // -> dimension of matrix
    cout << "Enter Dimension : ";
    cin >> n;
    class LTMatrix d(n);

    int x;
    cout << "Enter Elements : " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            d.Set(i, j, x);
        }
    }

    d.Display();

    return 0;
}