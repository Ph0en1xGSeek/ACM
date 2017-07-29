#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[6][7] = {{0}};
int ca;
int ans[7] = {0};

void add(int a[7], int b[7], int c[7])
{
    for(int i = 0; i < 7; i++)  c[i] = 0;
    for(int j = 6; j > 0; j--)
    {
        c[j] += a[j] + b[j];
        c[j-1] += (c[j] / 10);
        c[j] %= 10;
    }
    c[0] += a[0] + b[0];
}

int cmp(int a[7], int b[7])//比较a与b 大于返回1 小于返回-1
{
    for(int i = 0; i < 7; i++)
    {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    }
    return 0;
}

void make(int n, int a[7])
{
    for(int i = 6; i >= 0; i--)
    {
        a[i] = n % 10;
        n /= 10;
    }
}

void dfs(int dep, int a[7])
{
    if(dep == ca + 1)//更新最大值
    {
        if(cmp(a, ans) == 1)
            for(int i = 0; i < 7; i++)
                ans[i] = a[i];
        return;
    }
    int current[7], tmp[7] = {0};
    for(int i = 0; i < 7; i++)
        current[i] = a[i];
    int p;
    for(p=0; !current[p]; p++);
    sort(current+p, current+7);//要从升序开始排才能得到全部排列
    do
    {
        add(current, arr[dep], tmp);
        dfs(dep + 1, tmp);
    }while(next_permutation(current+p, current+7));
}

int main()
{
    memset(arr, 0, sizeof(arr));
    int num;
    scanf("%d", &ca);
    for(int i = 0; i < ca; i++)
    {
        scanf("%d", &num);
        make(num, arr[i]);
    }
    dfs(1, arr[0]);
    int i;
    for(i = 0; ans[i] == 0; i++);
    for(; i < 7; i++)
        printf("%d", ans[i]);
    printf("\n");
    return 0;
}
