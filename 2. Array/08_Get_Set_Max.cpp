// Get(index), Set(index,x), Max(), Min() Operations on an Array

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

int Get(struct Array r, int index)
{
    if (index >= 0 && index < r.length)
        return r.A[index];
    return -1;
}

void Set(struct Array *r, int index, int x)
{
    if (index >= 0 && index < r->length)
        r->A[index] = x;
}

int Max(struct Array r)
{
    int max = r.A[0];
    for (int i = 1; i < r.length; i++)
    {
        if (r.A[i] > max)
            max = r.A[i];
    }
    return max;
}

int Min(struct Array r)
{
    int min = r.A[0];
    for (int i = 1; i < r.length; i++)
    {
        if (r.A[i] < min)
            min = r.A[i];
    }
    return min;
}

int main()
{
    struct Array r = {{8, 3, 7, 12, 15, 6, 9, 10, 22, 2}, 10, 10};
    // cout << Get(r, 2) << endl;
    // Set(&r, 2, 0);
    // cout << Max(r) << endl;
    // cout << Min(r) << endl;
    // Display(r);

    return 0;
}