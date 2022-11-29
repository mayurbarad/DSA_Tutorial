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

// Iterative Way

struct Node *LSearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// Recursive Way

struct Node *LSearchR(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;

    if (key == p->data)
        return p;
    return LSearchR(p->next, key);
}

// Improvin Linear Search

struct Node *ImpLSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
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

int main()
{
    int A[] = {3, 5, 8, 9, 12, 15, 18, 20};
    int n = sizeof(A) / sizeof(A[0]);

    create(A, n);

    // Storing Node Return by LSearch in temp Node
    struct Node *temp;
    temp = ImpLSearch(first, 12);

    if (temp != NULL)
        cout << "Key Found : " << temp->data << endl;
    else
        cout << "Key Not Found" << endl;

    Display(first);
    return 0;
}