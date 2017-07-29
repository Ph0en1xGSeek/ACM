#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int s[1000111],t[10011];
int nex[10011];

int n,m;

int getnext()
{
    int i = 0;
    int j = -1;
    //memset(nex,0, sizeof(nex));
    nex[0] = -1;
    while(i < m )
    {
        if(j == -1 || t[i] == t[j])
        {
            i++;
            j++;
            nex[i] = j;
        }
        else
            j = nex[j];
    }
}

int kmp()
{

    int i=0,j=0;
    for(i = 0;i<n;)
    {
        if(s[i]==t[j])
        {
            if(j==m-1)
                return i-(m-1)+1;
            i++;
            j++;
        }
        else
        {
            j = nex[j];
            if(j==-1)
            {
                i++;
                j=0;
            }
        }
    }
    return -1;
}

int main()
{
    int ca;
    int ans;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d", &s[i]);
        for(int i = 0; i < m; i++)
            scanf("%d", &t[i]);
        if(n<m)
        {
            printf("-1\n");
            continue;
        }
        getnext();
        ans = kmp();
        printf("%d\n", ans);
    }
    return 0;
}
