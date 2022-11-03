// Insert element at any Index of an Array

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

void Insert(struct Array *r, int index, int x)
{
    if (index >= 0 && index <= r->length)
    {
        for (int i = r->length; i > index; i--)
        {
            r->A[i] = r->A[i - 1];
        }
        r->A[index] = x;
        r->length++;
    }
    else
    {
        cout << "Invalid Index" << endl;
    }
}

int main()
{
    struct Array r = {{2, 3, 4, 5, 6}, 10, 5};
    Insert(&r, 1, 2);
    Display(r);

    return 0;
}