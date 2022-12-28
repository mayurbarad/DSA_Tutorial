#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head;

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

void display(struct Node *p)
{
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
}

void displayR(struct Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << endl;
        displayR(p->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {8, 3, 9, 6, 2};
    create(A, 5);
    display(head);
    displayR(head);
    return 0;
}
