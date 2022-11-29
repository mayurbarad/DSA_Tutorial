#include <iostream>

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

//  Iterative Way

int add(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

// Recursive Way

int addR(struct Node *p)
{
    int sum = 0;
    if (p != NULL)
    {
        sum = addR(p->next);
        return sum + p->data;
    }
    return sum;
}

int main()
{
    int A[] = {3, 5, 8, 9, 12, 15, 18, 20};
    int n = sizeof(A) / sizeof(A[0]);

    create(A, n);

    cout << add(first) << endl;
    cout << addR(first) << endl;
    return 0;
}