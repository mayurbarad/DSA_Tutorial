// Using Class

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void create(int A[], int n);
    void Display(Node *p);
} *first = NULL;

void Node::create(int A[], int n)
{
    int i;
    Node *t, *last;
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

void Node::Display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    int A[8] = {2, 3, 4, 5, 6, 7, 8, 9};
    int n = 8;

    Node r;
    r.create(A, n);
    r.Display(first);

    return 0;
}