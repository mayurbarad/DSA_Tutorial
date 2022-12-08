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

int isLoop(struct Node *p)
{
    struct Node *q;
    p = q = first;

    do
    {
        p = p->next;
        q = q->next;
        q = (q != NULL ? q->next : q);
    } while (p != NULL && q != NULL && p != q);

    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    int A[] = {3, 5, 8, 9, 12, 15, 18, 20};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);

    struct Node *t1, *t2;
    t1 = first->next->next;                               // t1 is poiting on 8
    t2 = first->next->next->next->next->next->next->next; // t2 is on 20
    t2->next = t1;

    cout << isLoop(first) << endl;
    return 0;
}