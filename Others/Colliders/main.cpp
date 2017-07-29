#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#define MAXN 100010

using namespace std;

int arrp[MAXN];///质因数被谁占用
bool vis[MAXN];//标记
bool on[MAXN];
vector<int> ps[MAXN];///质因子打表

void get_prime()
{
    memset(vis, false, sizeof(vis));
	for(int i = 2; i < MAXN; i++)
	{
		if(!vis[i])
		{
			for(int j = i; j < MAXN; j += i)
            {
                ps[j].push_back(i);
                vis[j] = true;
            }
		}
	}
}

int check(int tmp)
{
    for(int i = 0; i < ps[tmp].size(); i++)
        if(arrp[ps[tmp][i]] != -1)
            return arrp[ps[tmp][i]];
    return -1;
}

int main()
{
    int n, m, tmp;
    char op;
    get_prime();
    while(~scanf("%d%d", &n, &m))
    {
        memset(arrp, -1, sizeof(arrp));
        memset(on, false, sizeof(on));
        for(int i = 0; i < m; i++)
        {
            getchar();
            op = getchar();
            scanf("%d", &tmp);
            if(op == '-')
            {
                if(on[tmp])
                {
                    on[tmp] = false;
                    for(int i = 0; i < ps[tmp].size(); i++)
                    {
                        arrp[ps[tmp][i]] = -1;
                    }
                    printf("Success\n");
                }
                else
                    printf("Already off\n");

            }
            else
            {
                if(on[tmp])
                    printf("Already on\n");
                else
                {
                    int c = check(tmp);
                    if(c == -1)
                    {
                        on[tmp] = true;
                        for(int i = 0; i < ps[tmp].size(); i++)
                            arrp[ps[tmp][i]] = tmp;
                        printf("Success\n");
                    }
                    else
                    {
                        printf("Conflict with %d\n", c);
                    }
                }
            }
        }
    }
    return 0;
}
