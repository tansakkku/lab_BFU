#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[100];
    int n;
    cout << "dlina: ";
    cin >> n;

    cout << "stroka: ";
    for (int i = 0; i < n; i++)
    {

        cin >> str[i];

    }

    char glas[13] = { 'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y', '\0' };
    char alf[100];
    char fin[100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (str[i] == glas[j])
                cout << str[i];


        }

    }


}