#include <stdio.h>
#include <cstring>
using namespace std;

int s[1000005],t[1000005];
int nex[1000005];

int n,m, p;

void getnext()
{
    int i = 0;
    int j = -1;
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
    int ans = 0;
    getnext();
    for(int k = 0; k < p; k++)
    {
        int i = k;
        int j = 0;
        while(i < n)
        {
            while(j != -1 && s[i] != t[j])
                j = nex[j];
            i+=p;
            j++;
            if(j >= m)
            {
                ans++;
                j = nex[j];
            }
        }
    }
    return ans;
}

int main()
{
    int ca, cc = 1;
    int ans = 0;
    scanf("%d", &ca);
    while(ca--)
    {
        ans = 0;
        scanf("%d%d%d", &n, &m, &p);
        for(int i = 0; i < n; i++)
            scanf("%d", &s[i]);
        for(int i = 0; i < m; i++)
            scanf("%d", &t[i]);
        if((m-1)*p + 1 >= n)
            ans = 0;
        else
        {
            getnext();
            ans = kmp();
        }
        printf("Case #%d: %d\n", cc++, ans);
    }
    return 0;
}
