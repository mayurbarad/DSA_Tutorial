#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else
        {
            top--;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    int getSize()
    {
        return top + 1;
    }

    void print()
    {
        cout << "Top : " << top << endl;
        cout << "Stack : ";
        for (int i = 0; i < getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
    }
};

int main()
{

    Stack st(8); // dynamic st
    st.push(10);
    st.push(20);
    st.push(30);
    st.print();

    st.pop();
    st.print();

    cout << "Top element :" << st.getTop() << endl;
    cout << "Size of Stack : " << st.getSize() << endl;
    cout << "Empty or Not " << st.isEmpty() << endl;

    return 0;
}