#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Full" << endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    Node *p;
    if (front == NULL)
        cout << " Queue is Empty" << endl;
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void display()
{
    Node *p = front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    enqueue(11);
    enqueue(22);
    enqueue(33);
    enqueue(44);
    enqueue(55);

    cout << dequeue() << endl;

    display();

    return 0;
}