#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

struct node
{
    int num;
    int p;
}arr[1010];

bool cmp(node a, node b)
{
    return a.num < b.num;
}

int ans[1000010][2];
int cnt;

int main()
{
    int num;
    int ca;
    bool flag;
    scanf("%d", &ca);
    for(int i = 1; i <= ca; i++)
    {
        cnt = 0;
        flag = true;
        scanf("%d", &num);
        for(int j = 0; j < num; j++)
        {
            scanf("%d", &arr[j].num);
            arr[j].p = j+1;
        }
        sort(arr, arr+num, cmp);
        for(int j = 0; j < num && flag; j++)
        {
            if(arr[j].num > j)
            {
                flag = false;
                break;
            }
            for(int k = 0; k < arr[j].num; k++)
            {
                ans[cnt][0] = arr[j].p;
                ans[cnt++][1] = arr[k].p;
            }
        }
        if(flag)
        {
            printf("Case #%d: Yes\n", i);
            printf("%d\n", cnt);
            for(int j = 0; j < cnt; j++)
                printf("%d %d\n", ans[j][0], ans[j][1]);
        }
        else
            printf("Case #%d: No\n", i);
    }
    return 0;
}
