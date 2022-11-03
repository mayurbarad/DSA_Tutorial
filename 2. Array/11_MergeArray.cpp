#include <iostream>

using namespace std;

struct Array
{
    int arr[10];
    int size;
    int length;
};

void Merge(struct Array *a, struct Array *b, struct Array *c)
{
    int i = 0, j = 0, k = 0;
    while (i < a->length && j < b->length)
    {
        if (a->arr[i] < b->arr[j])
        {
            c->arr[k] = a->arr[i];
            i++;
            k++;
        }
        else
        {
            c->arr[k] = b->arr[j];
            j++;
            k++;
        }
    }

    for (; i < a->length; i++)
    {
        c->arr[k] = a->arr[i];
        k++;
    }

    for (; j < b->length; j++)
    {
        c->arr[k] = b->arr[j];
        k++;
    }

    for (int i = 0; i < (a->length + b->length); i++)
    {
        cout << c->arr[i] << "\t";
    }
}

int main()
{
    struct Array a = {{3, 8, 16, 20, 25}, 10, 5};
    struct Array b = {{4, 10, 12, 22, 23}, 10, 5};
    struct Array c;
    Merge(&a, &b, &c);

    return 0;
}