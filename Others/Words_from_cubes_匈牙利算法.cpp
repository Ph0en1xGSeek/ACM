#include <stdio.h>
#include <iostream>
#include <string.h>
#define maxn 250

using namespace std;

char str[maxn];
int n,Link[maxn];
bool w[maxn][maxn],used[maxn];

bool match(int u)///匈牙利算法
{
    for(int i = 0; i < n; ++i)
    {
        if(!used[i] && w[u][i])///本次还没查过，并且对其有意向的
        {
            used[i] = true;
            if(Link[i] == -1 || match(Link[i]))
            {
                Link[i] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while(~scanf("%s",str))
    {
        scanf("%d",&n);
        memset(w, 0, sizeof(w));
        char tmp[20];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 6; ++j)
            {
                scanf("%s",tmp);
                for(int k = 0; str[k]; ++k)
                    if(str[k] == tmp[0]) w[k][i] = true;
            }
        }
        memset(Link,-1,sizeof Link);
        int ret = 0;
        for(int i = 0; i < 26; ++i){
            memset(used, 0, sizeof(used));
            if(match(i)) ++ret;
        }
        if(strlen(str) == ret)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
