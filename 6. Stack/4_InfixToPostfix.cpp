#include <iostream>
#include <cstring>

using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

void Push(struct Stack *st, char x)
{
    if (st->top == st->size - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

char Pop(struct Stack *st)
{
    char flag = -1;
    if (st->top == -1)
        cout
            << "Stack Underfow" << endl;
    else
    {
        flag = st->s[st->top];
        st->top--;
    }
    return flag;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
}

char *infixToPost(char *infix)
{
    struct Stack st;
    int i = 0, j = 0;
    int l = strlen(infix);
    char *postfix;
    postfix = new char[l + 1];

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(infix[st.top]))
                Push(&st, infix[i++]);
        }
    }
    return postfix;
}

int main()
{
    struct Stack st;
    cout << "Size";
    cin >> st.size;
    st.s = new int[st.size];

    char *infix = "a+b*c";
    Push(&st, '#');
    char *postfix = infixToPost(infix);
    cout << postfix;
    return 0;
}