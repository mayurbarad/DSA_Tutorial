// Delete Element at any Index of an Array

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

int Delete(struct Array *r, int index)
{
    int x = r->A[index];

    if (index >= 0 && index <= r->length)
    {
        for (int i = index; i < r->length - 1; i++)
        {
            r->A[i] = r->A[i + 1];
        }
        r->length--;
        return x;
    }
    else
    {
        cout << "Invalid Index" << endl;
    }
    return 0;
}

int main()
{

    struct Array r = {{2, 3, 4, 5, 6}, 10, 5};
    // Delete(&r, 1);
    cout << "Deleted Element is : " << Delete(&r, 1) << endl;
    cout << "Remaining Elements are : " << endl;
    Display(r);

    return 0;
}