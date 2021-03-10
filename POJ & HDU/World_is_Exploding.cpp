#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 51000
#define LL long long

using namespace std;

int arr[M];
int arr3[M];///树状数组
int beforeSmall[M];///左边比起小的
int nixu[M];///与其相关的逆序数
int afterBig[M];///右边比其大的

struct node
{
    int num;
    int p;
}arr2[M];

bool cmp(node a, node b)
{
    return a.num < b.num;
}

int lowbit(int x)
{
    return x&(-x);
}

int getsum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += arr3[x];
        x -= lowbit(x);
    }
    return sum;
}

void update(int x, int val)
{
    while(x <= M)
    {
        arr3[x] += val;
        x += lowbit(x);
    }
}

int main()
{
    int n, cnt;
    while(~scanf("%d", &n))
    {
        cnt = 1;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            arr2[i].num = arr[i];
            arr2[i].p = i;
        }
        sort(arr2+1, arr2+n + 1, cmp);
        int tmp = arr2[1].num;
        for(int i = 1; i <= n; i++)
        {
            if(arr2[i].num != tmp)
            {
                cnt++;
                tmp = arr2[i].num;
            }
            arr[arr2[i].p] = cnt;
        }
        memset(arr3, 0, sizeof(arr3));
        for(int i = 1; i <= n; i++)
        {
            int beforeEqual;
            beforeSmall[i] = getsum(arr[i]-1);
            beforeEqual = getsum(arr[i]) - beforeSmall[i];
            update(arr[i], 1);
            nixu[i] = (i-1) - beforeSmall[i] - beforeEqual;
        }
        memset(arr3, 0 ,sizeof(arr3));
        for(int i = n; i >= 1; i--)
        {
            int afterEqual;
            int tmp = getsum(arr[i]-1);
            nixu[i] += tmp;
            afterEqual = getsum(arr[i]) - tmp;
            update(arr[i], 1);
            afterBig[i] = (n-i) - tmp - afterEqual;
        }

        int totni = 0;
        for(int i = 1; i <= n; i++)
        {
            totni += nixu[i];
        }
        totni >>= 1;
        long long ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans += (long long)afterBig[i] *(totni - nixu[i]) - (long long)beforeSmall[i] * nixu[i];
            ///（求和）a开头的顺序对*（总逆序数-与a有关的逆序对（注意这里只减了左端点））-（求和）b结尾的顺序对*与b相关的逆序（这里减了右端点的）
        }
        cout << ans << endl;
    }
    return 0;
}
