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
    // Initially front and rear should be at 0
    q->front = q->rear = 0;
    q->Q = new int[q->size];
}

void enqueue(struct Queue *q, int x)
{
    // Check if Full
    if ((q->rear + 1) % q->size == q->front)
        cout << "Queue is Full" << endl;
    else
    {
        q->rear = (q->rear + 1) % q->size;
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
        //
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        //
        cout << q.Q[i] << " ";
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

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