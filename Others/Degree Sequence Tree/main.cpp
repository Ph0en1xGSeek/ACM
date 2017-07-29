/**先判断不可能组成树的情况，然后维护一个队列，度数为1的可以作为叶子节点
和一个父亲节点连接后父亲节点度-1**/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct node
{
    int e;
    int id;
}arr[200010];

bool cmp(node a, node b)
{
    return a.e < b.e;
}

int main()
{
    int num, p;
    int tot, flag;
    while(scanf("%d", &num) != EOF)
    {
        tot = 0, flag = 1;
        for(int i = 1; i <= num; i++)
        {
            scanf("%d", &(arr[i].e));
            arr[i].id = i;
            tot += arr[i].e;
            if(arr[i].e > num-1 || arr[i].e <= 0)
                flag = 0;
        }
        if(tot != 2 * (num-1) || flag == 0)
        {
            printf("-1\n");
            return 0;
        }
        sort(arr + 1, arr + 1+ num, cmp);
        if(arr[1].e != 1)
        {
            printf("-1\n");
            return 0;
        }
        for(p = 1; p <= num && arr[p].e == 1; p++);///第一个非叶子节点
        for(int i = 1; i < num; i++)
        {
            printf("%d %d\n", arr[i].id, arr[p].id);
            arr[p].e--;
            if(arr[p].e == 1 && p != num)
                p++;
        }
    }
    return 0;
}
