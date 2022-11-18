#include <iostream>
#include <cstring>

using namespace std;

class Stack
{
private:
    int size;
    int top;
    char *s;

public:
    Stack(int size);
    ~Stack();
    void Push(char x);
    int Pop();
    int isEmpty();
    int isFull();
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    s = new char[size];
}

Stack::~Stack()
{
    delete[] s;
}

void Stack::Push(char x)
{

    if (isFull())
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        s[top] = x;
    }
}

int Stack::Pop()
{
    char x = 1;
    if (isEmpty())
        cout << "Stack Empty" << endl;
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

int Stack::isEmpty()
{
    if (top == -1) // if top != NULL --> return 0
        return 1;
    return 0;
}

int Stack::isFull()
{

    if (top == size - 1) // new null not created i.e stack is full
        return 1;
    return 0;
}

bool isBalanced(char *exp)
{
    // Create Stack
    int l = strlen(exp);
    Stack st(l);
    for (int i = 0; i < l; i++)
    {
        if (exp[i] == '(')
            st.Push(exp[i]);
        else if (exp[i] == ')')
        {
            if (st.isEmpty())
                return false;
            else
                st.Pop();
        }
    }

    if (st.isEmpty())
        return true;
    return false;
}

int main()
{
    char a[] = "((a+b)*(b-c))";
    cout << isBalanced(a) << endl;

    char b[] = "(((a+b)*(b-c))";
    cout << isBalanced(b) << endl;

    char c[] = "((a+b)*(b-c)))";
    cout << isBalanced(c) << endl;

    return 0;
}