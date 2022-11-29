#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = new Node;

    if (t == NULL)
        cout << "Stack Overflow" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *p;
    int x = -1;
    if (top == NULL)
        cout << "Stack Underflow" << endl;
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        delete (p);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;

    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    push(10);
    push(20);
    Display();
    cout << pop();
    return 0;
}