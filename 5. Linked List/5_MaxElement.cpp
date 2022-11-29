#include <iostream>
#include <climits>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Iterative Way

int max(struct Node *p)
{
    int m = INT_MIN;
    while (p != NULL)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// Recursive Way

int maxR(struct Node *p)
{
    int x = 0;

    if (p == NULL)
        return INT_MIN;
    x = maxR(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

int main()
{
    int A[] = {3, 5, 8, 9, 12, 15, 18, 20};
    int n = sizeof(A) / sizeof(A[0]);

    create(A, n);

    cout << max(first) << endl;
    cout << maxR(first) << endl;

    return 0;
}