
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

// Tortoise - Hare Method

struct Node *middleNode(struct Node *p)
{
    struct Node *q;
    p = q = first;
    while (p && p->next)
    {
        p = p->next->next;
        q = q->next;
    }
    return q;
}

struct Node *middleNodeCount(struct Node *p)
{
    p = first;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    for (int i = 0; i < c / 2; i++)
    {
        p = p->next;
    }
    return p;
}

int main()
{
    int A[] = {3, 5, 8, 9, 12, 15, 18, 20};
    int n = sizeof(A) / sizeof(A[0]);

    create(A, n);
    cout << endl;
    cout << middleNode(first) << endl;
    return 0;
}