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

int deleteNode(struct Node *p, int pos)
{
    int x = -1;
    struct Node *q;

    if (pos < 1 || pos > count(p))
    {
        return x;
    }
    else
    {
        if (pos == 1)
        {
            p = first;
            first = first->next;
            x = p->data;
            delete p;
            return x;
        }
        else
        {

            p = first;
            q = NULL;
            for (int i = 0; i < pos - 1; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->data;
            delete p;
            return x;
        }
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
    cout << "Deleted Node : " << deleteNode(first, 2);
    cout << endl;
    Display(first);
    return 0;
}