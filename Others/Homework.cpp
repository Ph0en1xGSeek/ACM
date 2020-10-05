#include <iostream>
#define MAXN 10000000
#include <stdio.h>
#include <string.h>

using namespace std;

int arrp[MAXN];//用来存质数的
int vis[MAXN];//标记
int k;
void get_prime()
{
	k = 0;
	vis[0] = vis[1] = 0;
	vis[2] = 0;
	for(int i = 2; i < MAXN; i++)
	{
		if(!vis[i])
		{
			arrp[k++] = i;
			for(int j = i; j < MAXN; j += i)
                vis[j]++;
		}
	}
}

int main()
{
    get_prime();
    int ca, a, b, c;
    int cnt;
    cin >> ca;
    for(int j = 1; j <= ca; j++)
    {
        cnt = 0;
        scanf("%d%d%d", &a, &b, &c);
        for(int i = a; i <= b; i++)
        {
            if(vis[i] == c)
                cnt++;
        }
        printf("Case #%d: %d\n", j, cnt);

    }
    return 0;
}
