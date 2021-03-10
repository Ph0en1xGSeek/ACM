#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct node
{
    int x, y;
}arr[105];

bool cmp(node a, node b)
{
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int main()
{
    int num, x, y;
    while(~scanf("%d", &num) && num != 0)
    {
        for(int i = 0; i < num; i++)
            scanf("%d%d", &arr[i].x, &arr[i].y);
        sort(arr, arr+num, cmp);
        int tmp = -1, ans = 0;
        for(int i = 0; i < num; i++)
        {
            if(arr[i].x >= tmp)
            {
                ans++;
                tmp = arr[i].y;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
