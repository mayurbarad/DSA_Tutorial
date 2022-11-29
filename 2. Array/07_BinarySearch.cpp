// / Search element in an array through Binary Search

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

// using Iterative function

int BinSearch(struct Array r, int key)
{
    int l, h, mid;
    l = 0;
    h = r.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == r.A[mid])
            return mid;
        else if (key < r.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// Using Recursive function

int BinSearchR(struct Array r, int l, int h, int key)
{
    int mid;

    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == r.A[mid])
            return mid;
        else if (key < r.A[mid])
            return BinSearchR(r, l, mid - 1, key);
        else
            return BinSearchR(r, mid + 1, h, key);
    }
    return -1;
}

int main()
{

    struct Array r = {{2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, 10, 10};
    cout << "Found at Index " << BinSearch(r, 8) << endl;
    // cout << "Found at index " << BinSearchR(r, 0, r.length, 8) << endl;
    Display(r);

    return 0;
}