#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int cnta[2016], cntb[2016];//n,m之内余数为i的数的个数

void init(int arr[], int n)
{
    int tmp = n / 2016;
    int cnt = n % 2016;
    arr[0] = tmp;
    for(int i = 1; i <= cnt; i++)
        arr[i] = tmp + 1;
    for(int i = cnt + 1; i < 2016; i++)
        arr[i] = tmp;
}

int main()
{
    int n, m;
    while(~scanf("%d %d", &n, &m))
    {
        long long ans = 0;
        init(cnta, n);
        init(cntb, m);
        for(int i = 0; i < 2016; i++)
            for(int j = 0; j < 2016; j++)
                if((i*j) % 2016 == 0)
                    ans += (long long)((long long)cnta[i]*(long long)cntb[j]);
        printf("%lld\n", ans);
    }
    return 0;
}
