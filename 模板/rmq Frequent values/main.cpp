#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
int a[100002];
int b[100002];
int dp[100002][20];

void make(int n, int* arr)
{
    for(int i = 0; i < n; i++)
        dp[i][0] = arr[i];
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            dp[i][j] = max(dp[i][j-1], dp[i + (1 << (j-1))][j-1]);
}

int bi_search(int l, int r)
{
    int tmp = a[r];
    int mid;
    int left = l;
    int right = r;
    while(left < right)
    {
        mid = ((left + right) >> 1);
        if(a[mid] >= tmp)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}

int rmq(int l, int r)
{
    int k = (int)(log(r - l + 1.0)/log(2.0));//k为满足2^k<=r-l+1的最大的数 log2(r-l+1)
    return max(dp[l][k], dp[r - (1 << k)+1][k]);
}

int main()
{
    int n, m;
    int l, r;
    while(scanf("%d", &n) && n != 0)
    {
        scanf("%d", &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int tmp;
        for(int i = n - 1; i >= 0; i--)
        {
            if(i == n - 1)
                tmp = 1;
            else
            {
                if(a[i] == a[i+1])
                    tmp++;
                else
                    tmp = 1;
            }
            b[i] = tmp;
        }
        make(n, b);
        while(m--)
        {
            scanf("%d%d", &l, &r);
            l--;
            r--;
            int t = bi_search(l, r);//找和右端点一样的数最左边的一个，防止连续的数是被切断的 b[i]记录的数据不准确
            int ans = r - t + 1;
            r = t - 1;
            if(l > r)
                printf("%d\n", ans);
            else
                printf("%d\n", max(ans, rmq(l, r)));
        }
    }
    return 0;
}
