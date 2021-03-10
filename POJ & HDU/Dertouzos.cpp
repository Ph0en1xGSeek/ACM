#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN  500000

using namespace std;

int arrp[MAXN];//用来存质数的
int vis[MAXN];//标记
int k;
void get_prime()
{
	k = 0;
	vis[2] = 0;
	for(int i = 2; i < MAXN; i++)
	{
		if(!vis[i])
		{
			arrp[k++] = i;
			for(int j = i; j < MAXN; j += i)
                vis[j]=1;
		}
	}
}

int main()
{
    get_prime();
    int ca, n, d;
    scanf("%d", &ca);
    while(ca--)
    {
        int ans = 0;
        scanf("%d%d", &n, &d);
        int j;
        for(j = 0; d%arrp[j] != 0 && j < MAXN; j++)
        {
            if(arrp[j] * d < n)
                ans++;
            else
                break;
        }
        if(d%arrp[j] == 0 && arrp[j] * d < n) ans++;
        printf("%d\n", ans);
    }

    return 0;
}
