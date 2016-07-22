#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int i, j;
    int pointer;
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        pointer = -1;
        if(s1.length() > s2.length())
            printf("No\n");
        else
        {
            for(i = 0; i < s1.length(); i++)
            {
                for(j = pointer + 1; j < s2.length(); j++)
                {
                    if(s1[i] == s2[j])
                    {
                        pointer = j;
                        break;
                    }
                }
                if(j == s2.length())
                {
                    printf("No\n");
                    break;
                }

            }
            if(i == s1.length())
                printf("Yes\n");
        }
    }
    return 0;
}
