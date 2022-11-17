#include <iostream>

using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *s;
    void Create();
    void Display();
    void Push(int x);
    int Pop();
    int Peek(int pos);
    int isEmpty();
    int isFull();
    int StackTop();
};

void Stack::Create()
{
    cout << "Enter Size : ";
    cin >> size;
    top = -1;
    s = new int[size];
}

void Stack::Display()
{
    int i;
    for (i = top; i >= 0; i--)
        cout << s[i] << endl;
}

void Stack::Push(int x)
{
    if (top == size - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        s[top] = x;
    }
}

int Stack::Pop()
{
    int flag = -1;
    if (top == -1)
        cout
            << "Stack Underfow" << endl;
    else
    {
        flag = s[top];
        top--;
    }
    return flag;
}
int Stack::Peek(int pos)
{
    int flag = -1;
    int index = top - pos + 1;
    if (index < 0)
        cout << "Invalid Postion";
    else
        flag = s[index];

    return flag;
}

int Stack::isEmpty()
{
    return top == -1; // if true --> return 1
}

int Stack::isFull()
{
    return top == size - 1;
}

int Stack::StackTop()
{
    if (!isEmpty())
        return s[top];

    return -1;
}

int main()
{
    class Stack st;

    st.Create();

    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);

    // cout << st.Pop() << endl;
    // cout << st.Pop() << endl;
    // cout << st.Pop() << endl;
    // cout << "After Pop : " << endl;

    cout << st.Peek(3) << endl;

    cout << st.isEmpty() << endl;

    cout << st.isFull() << endl;

    cout << st.StackTop() << endl;

    st.Display();
    return 0;
}