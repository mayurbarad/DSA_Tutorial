#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // creation
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    // size of stack
    cout << "Stack size is: " << st.size() << endl;

    // pop
    st.pop();

    // check empty
    if (st.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is non empty" << endl;
    }

    return 0;
}