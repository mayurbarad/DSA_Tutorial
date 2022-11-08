#include <iostream>

using namespace std;

int main()
{
    char s[] = "welcome";
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    cout << "length is " << i;

    return 0;
}