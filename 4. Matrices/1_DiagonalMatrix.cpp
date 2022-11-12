#include <iostream>

using namespace std;

class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Diagonal()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

int Diagonal::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}

void Diagonal::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << A[i];
            else
                cout << 0;
        }
        cout << endl;
    }
}

int main()
{
    class Diagonal d(5);

    d.Set(1, 1, 3);
    d.Set(2, 2, 7);
    d.Set(3, 3, 4);
    d.Set(4, 4, 9);
    d.Set(5, 5, 6);

    cout << d.Get(2, 2) << endl;

    d.Display();

    return 0;
}