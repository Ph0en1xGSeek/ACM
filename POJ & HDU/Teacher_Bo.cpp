#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>


using namespace std;

int abs(int a)
{
    if(a >= 0) return a;
    else return -a;
}

struct node
{
    int x, y, m;
}nodes[100010];

int arr[200010];

int main()
{
    int ca, flag;
    int n, m;
    scanf("%d", &ca);
    while(ca--)
    {
        memset(arr, 0, sizeof(arr));
        flag = 0;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &nodes[i].x, &nodes[i].y);
            nodes[i].m = nodes[i].x + nodes[i].y;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                int tmp = abs(nodes[i].x-nodes[j].x) + abs(nodes[i].y - nodes[j].y);
                if(arr[tmp] == 0)
                    arr[tmp] = 1;
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
