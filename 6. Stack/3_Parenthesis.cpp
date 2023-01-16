#include <bits/stdc++.h>

using namespace std;

int isBalanced(string exp)
{
    int length = exp.length();
    stack<char> st;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            st.push(exp[i]);
        else
        {
            if (st.empty())
                return false;
            if (exp[i] == ')' && st.top() == '(' ||
                exp[i] == ']' && st.top() == '[' ||
                exp[i] == '}' && st.top() == '{')
                st.pop();
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string s = "(()())";

    if (isBalanced(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}