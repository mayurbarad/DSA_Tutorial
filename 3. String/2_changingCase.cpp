#include <iostream>

using namespace std;

void UpperToLower(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] += 32;
        i++;
    }
    cout << s << endl;
}

void Toggle(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        else if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
        i++;
    }
    cout << s << endl;
}

int main()
{
    char s[] = "WELCOME";
    // char s[] = "WeLCOMe";
    UpperToLower(s);
    // Toggle(s);

    return 0;
}