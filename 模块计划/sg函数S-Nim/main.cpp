#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int S[105], k;
int sg[10005] = {0};
int vis[10001];

void getSG()
{
    memset(vis, -1, sizeof(vis));
    for(int i = 1; i < 10005; i++)
    {
        for(int j = 0; S[j] <= i && j < k; j++)
        {
            vis[sg[i-S[j]]] = i;
        }
        int j = 0;
        while(vis[j] == i) j++;
        sg[i] = j;
    }
}

int main()
{
    int ca, l, tmp;
    while(~scanf("%d", &k) && k != 0)
    {
        for(int i = 0; i < k; i++)
        {
            scanf("%d", &S[i]);
        }
        sort(S, S+k);
        getSG();
        scanf("%d", &ca);
        while(ca--)
        {
            int ans = 0;
            scanf("%d", &l);
            while(l--)
            {
                scanf("%d", &tmp);
                ans ^= sg[tmp];
            }
            if(ans)
                printf("W");
            else
                printf("L");
        }
        printf("\n");
    }
    return 0;
}
