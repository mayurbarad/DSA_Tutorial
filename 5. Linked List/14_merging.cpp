// USING STRUCTURE

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create1(int A[], int n1)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n1; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int B[], int n2)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n2; i++)
    {
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void merging(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p != NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
}

int main()
{
    int A[] = {2, 8, 10, 20};
    int n1 = sizeof(A) / sizeof(A[0]);

    int B[] = {3, 7, 12, 14};
    int n2 = sizeof(B) / sizeof(B[0]);

    create1(A, n1);
    create2(B, n2);
    merging(first, second);
    Display(third);

    return 0;
}