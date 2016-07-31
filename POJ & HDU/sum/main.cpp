#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int arr[100010], tmp;
    int ca, n, m;
    int flag;
    scanf("%d", &ca);
    while(ca--)
    {
        flag = 0;
        scanf("%d%d", &n, &m);
        arr[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &tmp);
            arr[i] = tmp + arr[i-1];
        }
        for(int i = 0; i < n && !flag; i++)
            for(int j = i+1; j <= n; j++)
                if((arr[j]-arr[i]) % m == 0)
                {
                    flag = 1;
                    break;
                }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
