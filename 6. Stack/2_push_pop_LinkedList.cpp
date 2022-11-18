#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    void Push(int x);
    int Pop();
    int Peek(int pos);
    int StackTop();
    int isEmpty();
    int isFull();
    void Display();
} *top = NULL;

void Node::Push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Node::Pop()
{
    Node *p;
    int x = -1;
    if (top == NULL)
        cout << "Stack Empty" << endl;
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}

int Node::Peek(int pos)
{
    Node *p = top;
    for (int i = 0; (p != NULL) && (i < pos - 1); i++)
    {
        p = p->next;
    }

    if (p != NULL)
        return pos - 1;
    else
        return -1;
}

int Node::StackTop()
{
    if (top) // --> if top != NULL --> return top->data
        return top->data;
    return -1;
}

int Node::isEmpty()
{
    if (top) // if top != NULL --> return 0
        return 0;
    return 1;
}

int Node::isFull()
{
    Node *t = new Node;
    if (t == NULL) // new null not created i.e stack is full
        return 1;
    return 0;
}

void Node::Display()
{
    Node *p;
    p = top;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{

    Node n;

    n.Push(10);
    n.Push(20);
    n.Push(30);

    n.Display();

    cout << n.Pop() << endl;

    n.Display();
    return 0;
}