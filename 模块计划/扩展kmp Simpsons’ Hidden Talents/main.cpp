#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str1[50010], str2[50010];

void exkmp(char s1[], char s2[], int nex[], int ex[])
{
    ///nex[i]为s2[i] s2[0]最长公共后缀
    ///ex[i]为s1[i] s2[0]最长公共后缀
    int i, j, p;
    for(i = 0, j = 0, p = -1; s1[i] != '\0'; i++, j++, p--)
    {
        if(p == -1)
        {
            j = 0;
            do
                p++;
            while(s1[i+p] != '\0' && s1[i+p] == s2[j+p]);
            ex[i] = p;
        }
        else if(nex[j] < p)
            ex[i] = nex[j];
        else if(nex[j] > p)
            ex[i] = p;
        else
        {
            j = 0;
            while(s1[i+p] != '\0' && s1[i+p] == s2[j+p])
                p++;
            ex[i] = p;
        }
    }
    ex[i] = 0;
}

int main()
{
    while(~scanf("%s\n%s", str1, str2))
    {
        int nex[50010], ex[50010];
        nex[0] = 0;
        exkmp(str1+1, str1, nex, nex+1);
        exkmp(str2, str1, nex, ex);
        int len = strlen(str2);
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            if(i + ex[i] == len)
            {
                ans  = ex[i];
                break;
            }
        }
        if(ans)
        {
            for(int i = 0; i < ans; i++)
                printf("%c", str1[i]);
            printf(" %d\n", ans);
        }
        else
            printf("0\n");
    }
    return 0;
}
