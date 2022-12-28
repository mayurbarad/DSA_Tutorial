#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void display(struct Node *p)
{
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
}

void create(int A[], int n)
{
    struct Node *t, *last;
    head = new Node();
    head->data = A[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

int length(struct Node *p)
{
    int l = 0;
    do
    {
        l++;
        p = p->next;
    } while (p != head);
    return l;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > length(p))
    {
        cout << "Invalid Index" << endl;
        return;
    }

    if (index == 0)
    {
        t = new Node;
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int delNode(struct Node *p, int index)
{
    int x;
    struct Node *q;
    if (index < 0 || index > length(p))
        return -1;

    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (p == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main()
{
    int A[] = {11, 22, 33, 44};
    create(A, 4);
    // insert(head, 2, 10);
    cout << delNode(head, 3) << endl;
    display(head);

    return 0;
}
