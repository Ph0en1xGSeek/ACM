#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int n;
    char tmp[400], s[800];
    while(scanf("%d", &n) != EOF)
    {
        scanf("%s", tmp);
        strcpy(s, tmp);
        strcat(s, tmp);
        int left[800][2], right[800][2];//从左数第几个 右数第几个
        left[0][0] = left[0][1] = 0;//第一行记r 第二行记b
        for(int i = 1; i <= 2*n; i++)
            if(s[i-1] == 'r')//记的是左边一格的
            {
                left[i][0] = left[i-1][0] + 1;
                left[i][1] = 0;
            }
            else if(s[i-1] == 'b')
            {
                left[i][1] = left[i-1][1] + 1;
                left[i][0] = 0;
            }
            else
            {
                left[i][0] = left[i-1][0] + 1;
                left[i][1] = left[i-1][1] + 1;
            }
        right[2*n][0] = right[2*n][1] = 0;
        for(int i = 2*n-1; i >= 0; i--)
            if(s[i] == 'r')//记的是这一格的
            {
                right[i][0] = right[i+1][0] + 1;
                right[i][1] = 0;
            }
            else if(s[i] == 'b')
            {
                right[i][1] = right[i+1][1] + 1;
                right[i][0] = 0;
            }
            else
            {
                right[i][0] = right[i+1][0] + 1;
                right[i][1] = right[i+1][1] + 1;
            }
        int m = 0;
        for(int i = 0; i < 2 * n; i++)
            m = max(m, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
            m = min(n, m);
        printf("%d\n", m);
    }

    return 0;
}
