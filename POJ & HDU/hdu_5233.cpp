#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <vector>
#include <set>
#define M 100005

using namespace std;


int arr;
map<int, int> mp;
set<int> num[M];

int main()
{
    int n, m;
    int tmp;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i <= n; i++)
            num[i].clear();
        mp.clear();
        int cnt = 1;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr);
            if(!mp[arr])
                mp[arr] = cnt++;
            num[mp[arr]].insert(i);
        }

        for(int i = 0; i < m; i++)
        {
            scanf("%d", &tmp);
            if(mp[tmp] != 0)
                if(num[mp[tmp]].size() > 0)
                {
                    printf("%d\n", *(num[mp[tmp]].begin()));
                    num[mp[tmp]].erase(num[mp[tmp]].begin());
                }
                else
                    printf("-1\n");
            else
                printf("-1\n");
        }

    }
    return 0;
}
