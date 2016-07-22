#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int p[220005];
    int bonder, id ;
    int longest;
    char str[110002];
    char s[220005];
    int i, n;
    while(scanf("%s", &str[1]) != EOF)
    {
        bonder = 0;
        id = 0;
        longest = 0;
        for(i = 1; str[i] != '\0'; i++)
        {
            s[i << 1] = str[i];
            s[(i << 1) + 1] = '#';
        }
        s[1] = '#';
        s[0] = '$';
        n = (i << 1) + 2;
        s[n] = '\0';


        for(i = 1; i < n; i++)///Manacher
        {
            if(i < bonder)
            {
                p[i] = min(p[2*id - i], bonder - i);//相对id对称的位置 2id - 1
            }
            else
            {
                p[i] = 1;
            }

 /**--------------------------------------------------------------------------------------------**/

            while(s[i + p[i]] == s[i - p[i]])
            {
                p[i]++;
            }
            if(p[i] + i > bonder)
            {
                bonder = i + p[i];
                id = i;
            }
            if(p[i] > longest)
                longest = p[i];
        }
        printf("%d\n", longest-1);//最长长度为新生成串半长减1
    }


    return 0;
}
