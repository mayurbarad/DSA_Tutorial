// Append()/Add() Element to an Array -> at end of an array

#include <iostream>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Append(struct Array *r, int x)
{
    if (r->length < r->size)
    {
        r->A[r->length] = x;
        r->length++;
    }
}

void Display(struct Array r)
{
    for (int i = 0; i < r.length; i++)
    {
        cout << r.A[i] << endl;
    }
}

int main()
{
    int sz = 10;
    struct Array r = {{2, 3, 4, 5, 6, 7, 8, 9}, 10, 8};
    Append(&r, 10);
    Display(r);

    return 0;
}