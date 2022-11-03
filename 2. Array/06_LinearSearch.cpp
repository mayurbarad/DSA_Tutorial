// Search element in an array through Linear Search

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

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *r, int x)
{
    for (int i = 0; i < r->length; i++)
    {
        if (x == r->A[i])
        {
            //  1. Transposition Method
            Swap(&r->A[i], &r->A[i - 1]);

            // 2. Moving to front/Head Method
            // Swap(&r->A[i], &r->A[0]);
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array r = {{2, 3, 4, 5, 6}, 10, 5};
    cout << "at index " << LinearSearch(&r, 4) << endl;
    Display(r);

    return 0;
}