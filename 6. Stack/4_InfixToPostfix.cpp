#include <bits/stdc++.h>

using namespace std;

int prec(char x)
{
    if (x == '^')
        return 3;
    else if (x == '/' || x == '*')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string infix)
{

    stack<char> st;
    string result;

    for (int i = 0; i < infix.length(); i++)
    {
        char x = infix[i];

        // If the scanned character is
        // an operand, add it to output string.
        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
            result = result + x;
        else if (x == '(')
            st.push('(');
        else if (x == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(infix[i]) <= prec(st.top()))
            {
                result = result + st.top();
                st.pop();
            }
            st.push(x);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << "Prefix expression: " << result << endl;
}

int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infixToPostfix(exp);
    return 0;
}