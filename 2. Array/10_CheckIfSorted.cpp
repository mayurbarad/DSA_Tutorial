// Insert Element in Sorted Array
// Check if an Array is Sorted or Not
// Negative Elements on Left side of an Array

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

// Insert Element in Sorted Array

void Insert(struct Array *r, int x)
{
    int i = r->length - 1;
    while (r->A[i] > x && i >= 0)
    {
        r->A[i + 1] = r->A[i];
        i--;
    }
    r->A[i + 1] = x;
    r->length++;
}

// Check if an Array is Sorted or Not

int Sort(struct Array r)
{
    for (int i = 0; i < r.length - 1; i++)
    {
        if (r.A[i] > r.A[i + 1])
            return false;
    }
    return true;
}

// Negative Elements on Left side of an Array

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Reaarange()
{
    int length = 10;
    int B[10] = {-6, 3, -8, 10, 5, -7, -9, 12, -4, 2};
    int i = 0, j = length - 1;
    while (i < j)
    {
        while (B[i] < 0)
            i++;
        while (B[j] >= 0)
            j--;
        if (i < j)
            Swap(&B[i], &B[j]);
    }

    for (int i = 0; i < length - 1; i++)
    {
        cout << B[i] << "\t";
    }
}

int main()
{
    struct Array r = {{4, 8, 12, 16, 20, 28, 35, 43, 49}, 10, 9};
    // Insert(&r, 10);
    // cout << Sort(r) << endl;
    // Display(r);
    Reaarange();

    return 0;
}