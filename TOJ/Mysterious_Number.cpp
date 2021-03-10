#include <iostream>
#include <cstdio>
#define M 1000011

using namespace std;
int a[M];
int dp[M] = {0};
int main()
{
    fill(a+2, a + M, 2);
    a[1] = 1;
    for(int i = 2; i < (M >> 1); i++)
        for(int j = 2; i*j < M; j++)
            a[i*j]++;
    for(int i = 1; i < M; i++)
        dp[i] = dp[i-1] + (i%a[i] == 0? 1:0);
    int low, high;
    while(scanf("%d%d", &low, &high) != EOF)
        printf("%d\n", dp[high] - dp[low-1]);
    return 0;
}
