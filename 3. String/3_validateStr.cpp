#include <iostream>

using namespace std;

int Valid(string name);

int Valid(string name)
{
    int i = 0;
    while (name[i] != '\0')
    {
        if (!(name[i] >= 65 && name[i] <= 90) &&
            !(name[i] >= 97 && name[i] <= 122) &&
            !(name[i] >= 48 && name[i] <= 57))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main()
{
    string name = "Ma?u3";
    if (Valid(name))
    {
        cout << "Valid String";
    }
    else
    {
        cout << "Invalid String";
    }

    return 0;
}