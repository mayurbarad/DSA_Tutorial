#include <iostream>

using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

void display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << endl;
    }
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        cout << "Stack Underflow" << endl;
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if ((st.top - index + 1) < 0)
        cout << "Invalid Position" << endl;
    else
        x = st.s[st.top - index + 1];
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    return 0;
}

int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.s[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    cout << "Enter Size : ";
    cin >> st.size;
    st.s = new int[st.size];
    st.top = -1;

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    display(st);

    cout << isFull(st);

    cout << pop(&st);

    return 0;
}