#include <iostream>

using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int length(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;

    if (index < 0 || index > length(p))
        return;
    t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->prev = NULL;
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int deleteNode(struct Node *p, int index)
{
    int x = -1;
    p = first;
    if (index < 0 || index > length(p))
        return -1;

    if (index == 0)
    {
        first = first->next;
        x = p->data;
        delete p;
        if (first)
            first->prev = NULL;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

void reverse(struct Node *p)
{
    p = first;
    struct Node *temp = NULL;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

void display(struct Node *p)
{
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int A[] = {11, 22, 33, 44, 55};
    create(A, 5);
    // insert(first, 5, 0);
    // cout << "deleted data : " << deleteNode(first, 0) << endl;
    reverse(first);
    display(first);
    return 0;
}