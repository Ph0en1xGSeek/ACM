#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int ca;
    char s[100010], p[5005];
    int record[100010];
    scanf("%d", &ca);
    while(ca--)
    {
        int n, m;
        int flag;
        memset(record, 0, sizeof(record));
        scanf("%d%d", &n, &m);
        scanf("%s", s);
        getchar();
        scanf("%s", p);
        int i = 0, j = 0, point;
        for(i = 0; i <= n-m; i++)
        {
            point = i, j = 0;
            flag = 1;
            while(j < m && point < n)
            {
                if(s[point] == p[j])
                {
                    point++;
                    j++;
                }
                else
                {
                    if(j == m-1)
                    {
                        flag = 0;
                        break;
                    }
                    else if(s[point + 1] != p[j] || s[point] != p[j+1])
                    {
                        flag = 0;
                        break;
                    }
                    else
                        j+= 2, point += 2;
                }
            }
            if(flag)
                record[i] = 1;
        }
        for(i = 0; i < n; i++)
            printf("%d", record[i]);
        printf("\n");
    }
    return 0;
}
