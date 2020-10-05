#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <vector>
#define mod 1000000007

using namespace std;

char s[100005],t[100005];
int nex[100005];
int arr[100005], dp[100005];
int n,m;

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


void kmp()
{
    getnext();
    int i = 0, j = 0;
    while(i < n)
    {
        while(j != -1 && s[i] != t[j])
            j = nex[j];
        i++;
        j++;
        if(j >= m)
        {
            arr[i-1] =1;
            j = nex[j];
        }
    }
}

int dps(int i)
{
    if(i < 0) return 1;
    return dp[i] % mod;
}

int main()
{
    int ca, ans, cnt;
    int cc = 1;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(dp, 0, sizeof(dp));
        memset(arr, -1, sizeof(arr));
        scanf("%s", &s);
        scanf("%s", &t);
        n = strlen(s);
        m = strlen(t);
        kmp();
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == -1) dp[i] = dps(i-1);
            else
            {
                dp[i] = dps(i-1);
                dp[i] = (dp[i] + dps(i-m)) % mod;
            }
        }
        printf("Case #%d: %d\n", cc++, dp[n-1]);
    }
    return 0;
}
