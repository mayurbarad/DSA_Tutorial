#include <iostream>

using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

void enqueue(struct Queue *q, int x)
{
    // Check if Full
    if (q->rear == q->size - 1)
        cout << "Queue is Full" << endl;
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x;
    // Check if Empty
    if (q->front == q->rear)
        cout << "Queue is Empty" << endl;
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 11);
    enqueue(&q, 22);
    enqueue(&q, 33);

    cout << dequeue(&q) << endl;

    display(q);

    return 0;
}