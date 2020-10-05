#include <iostream>
#include <cstring>
#define INF 10000000

using namespace std;
int v[501];
int w[501];
int dp[10005]= {0};
int main()
{
    int ca, emp, ful, num;
    cin >> ca;
    while(ca--)
    {
        cin >> emp >> ful;
        int tmp = ful - emp;
        cin >> num;
        for(int i = 1; i <= num; i++)
            cin >> v[i] >> w[i];
        //dp[1] = 0;
        for(int i = 1; i <= tmp; i++)//±ê¼Ç
            dp[i] = INF;
        for(int i = 1; i <= num; i++)
            for(int j = w[i]; j <= tmp; j++)
                dp[j] = min(dp[j], dp[j-w[i]] + v[i]);//第一步只有wi的整倍数才能被赋值 其他都是inf 之后都是硬币的w可以组合成的才会脱离inf
        if(dp[tmp] != INF)
            cout << "The minimum amount of money in the piggy-bank is " << dp[tmp] << '.' << endl;
        else
            cout << "This is impossible." << endl;
    }
    return 0;
}
