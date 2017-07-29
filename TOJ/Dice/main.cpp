#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double dp[101][601];

int main()
{
    int n, m;
    for(int i = 1; i <= 6; i++)
        dp[1][i] = 1.0/6.0;
    for(int i = 2; i <= 100; i++)
        for(int j = 6*i; j >= i; j--)
            for(int k = 1; k <= 6 && j-k >= 1; k++)
                dp[i][j] += dp[i-1][j-k]/6.0;

    int ca;
    cin >> ca;
    while(ca--)
    {
        cin >> n >> m;
        printf("%.2f\n", dp[n][m]);

    }

    return 0;
}
