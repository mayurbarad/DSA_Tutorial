// Increase Size Of an Array

#include <iostream>

using namespace std;

int main()
{
    int *p, *q;
    p = new int[5];
    p[0] = 2;
    p[1] = 4;
    p[2] = 6;
    p[3] = 8;
    p[4] = 10;

    q = new int[10];
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << q[i] << "\t";
    // }
    delete[] p;
    p = q;
    q = NULL;

    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << "\t";
    }

    return 0;
}