#include <iostream>
#include <map>
#include <cstring>
#include <stdio.h>

using namespace std;

int main()
{
    map<string, int> m;
    char str[11];
    while(gets(str))
    {
        int len = strlen(str);
        if(len == 0)
            break;
        else
        {
            for(int i = len; i > 0; i--)
            {
                str[i] = '\0';
                m[str]++;
            }
        }
    }
    while(gets(str))
    {
            cout << m[str] << endl;
    }
    return 0;
}
