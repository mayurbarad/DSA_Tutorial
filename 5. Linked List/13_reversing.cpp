#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void insertSorted(struct Node *p, int x)
{
    struct Node *t, *q;
    t = new Node;
    q = NULL;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p != NULL && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first) // when x is smaller than data of first node --> insert at begining
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Using Sliding Pointer Method

void reverse(struct Node *p)
{
    p = first;
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Using Recursion

void reverseR(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        reverseR(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    insertSorted(first, 11);
    insertSorted(first, 22);
    insertSorted(first, 33);
    insertSorted(first, 44);
    insertSorted(first, 55);
    Display(first);
    cout << endl;
    reverse(first);
    // reverseR(NULL, first);
    Display(first);

    return 0;
}