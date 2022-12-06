#include <iostream>
#include <climits>

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

// Remove Duplicates in Sorted Link List

void duplicates(struct Node *p)
{
    p = first;
    Node *q = first->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{

    insertSorted(first, 11);
    insertSorted(first, 11);
    insertSorted(first, 33);
    insertSorted(first, 33);
    insertSorted(first, 55);
    insertSorted(first, 55);
    Display(first);
    cout << endl;
    duplicates(first);
    Display(first);

    return 0;
}