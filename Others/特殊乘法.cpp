#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char str1[15];
char str2[15];

int main()
{
    while(~scanf("%s %s", str1, str2))
    {
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int ans = 0;
        for(int i = 0; i < len1; i++)
        {
            for(int j = 0; j < len2; j++)
            {
                ans += (str1[i] - '0') * (str2[j] - '0');
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
