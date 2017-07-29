#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int ca, num;
    long long ans, mx;
    int cnt, cc = 1;
    long long c;
    char str[100010];
    long long len[100010];
    scanf("%d", &ca);
    while(ca--)
    {
        cnt = 1;
        ans = 0;
        scanf("%s", str);
        c = 1;
        for(int i = 1; str[i] != '\0'; i++)
        {
            if(str[i] != str[i-1])
            {
                len[cnt++] = c;
                ans += c * c;
                c = 1;
            }
            else
                c++;
        }
        len[cnt++] = c;
        ans += c*c;
        mx = ans;
        len[cnt++] = len[0] = 0;
        for(int i = 1; i < cnt-2; i++)
        {
            if(len[i+1] == 1)
                mx = max(mx, ans - len[i]*len[i] - len[i+1]*len[i+1] - len[i+2]*len[i+2] + (len[i]+len[i+1]+len[i+2])*(len[i]+len[i+1]+len[i+2]));
            else
                mx = max(mx, ans - len[i]*len[i] - len[i+1]*len[i+1] + (len[i]+1)*(len[i]+1) + (len[i+1]-1)*(len[i+1]-1));

            if(len[i] == 1)
                mx = max(mx, ans - len[i]*len[i] - len[i+1]*len[i+1] - len[i-1]*len[i-1] + (len[i]+len[i+1]+len[i-1])*(len[i]+len[i+1]+len[i-1]));
            else
                mx = max(mx, ans - len[i]*len[i] - len[i+1]*len[i+1] + (len[i]-1)*(len[i]-1) + (len[i+1]+1)*(len[i+1]+1));
        }
        printf("Case #%d: %I64d\n", cc++, mx);
    }
    return 0;
}
