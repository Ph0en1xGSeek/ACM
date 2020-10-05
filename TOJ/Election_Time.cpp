#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node
{
    int num;
    int first;
    int second;
}arr[50001];

bool cmp1(node a, node b)
{
    return a.first > b.first;
}

bool cmp2(node a, node b)
{
    return a.second > b.second;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        arr[i].num = i;
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    sort(arr+1, arr+1+n, cmp1);
    sort(arr+1, arr+1+k, cmp2);
    printf("%d\n", arr[1].num);
    return 0;
}
