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

int checkSorted(struct Node *p)
{
    int x = INT_MIN; // -32768
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
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
    cout << checkSorted(first);

    return 0;
}