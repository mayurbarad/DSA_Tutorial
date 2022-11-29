// USING STRUCTURE

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

int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void insert(struct Node *p, int pos, int x)
{
    if (pos < 0 || pos > count(p))
        return;

    struct Node *t;
    t = new Node;
    t->data = x;

    if (pos == 0)
    {
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        p = first;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {3, 5, 8, 9, 12, 15, 18, 20};
    int n = sizeof(A) / sizeof(A[0]);

    create(A, n);
    Display(first);
    insert(first, 7, 1);
    cout << endl;
    Display(first);
    return 0;
}