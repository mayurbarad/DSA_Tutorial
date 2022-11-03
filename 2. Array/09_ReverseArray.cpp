// Reverse an Array

#include <iostream>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array r)
{
    for (int i = 0; i < r.length; i++)
    {
        cout << r.A[i] << endl;
    }
}

void Reverse1(struct Array *r)
{
    int *B;
    B = new int[10];
    for (int i = r->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = r->A[i];
    }

    for (int i = 0; i < r->length; i++)
    {
        r->A[i] = B[i];
    }
}

void Reverse2(struct Array *r)
{
    for (int i = 0, j = r->length - 1; i < j; i++, j--)
    {
        int temp = r->A[i];
        r->A[i] = r->A[j];
        r->A[j] = temp;
    }
}

int main()
{
    struct Array r = {{8, 3, 7, 12, 15, 6, 9, 10, 22, 2}, 10, 10};
    Reverse1(&r);
    // Reverse2(&r);
    Display(r);
    return 0;
}