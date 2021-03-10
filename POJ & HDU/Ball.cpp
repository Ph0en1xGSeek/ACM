#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node
{
    int num;
    int id;
    int pos;
}arr[2016], arr1[2016], arr2[2016], arr3[2016];

bool cmp(node a, node b)
{
    if(a.num == b.num)
        return a.id < b.id;
    return a.num < b.num;
}

bool cmp1(node a, node b)
{
    return a.pos < b.pos;
}

int main()
{
    int ca, n, m, l, r;
    bool flag = true;
    scanf("%d", &ca);
    while(ca--)
    {
        flag = true;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr3[i].num);
            arr2[i].num = arr3[i].num;
            arr2[i].id = arr3[i].id = i;
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i].num);
            arr1[i].num = arr[i].num;
            arr1[i].id = arr[i].id = i;
        }
        sort(arr1+1, arr1+n+1, cmp);
        sort(arr2+1, arr2+n+1, cmp);
        for(int i = 1; i <= n; i++)
            arr3[arr2[i].id].pos = arr1[i].id;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &l, &r);
            sort(arr3+l, arr3+r+1, cmp1);
        }
        for(int i = 1; i <= n; i++)
        {
            if(arr3[i].num != arr[i].num)
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
