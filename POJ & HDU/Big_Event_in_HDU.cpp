#include <iostream>
#include <cstring>
int dp[250100];
int v[5005];

using namespace std;

int main()
{
    int ca, a, b;
    int sum, num;
    while(cin >> ca && ca >= 0)
    {
        memset(dp, 0, sizeof(dp));
        num = 0;
        sum = 0;
        while(ca--)
        {
            cin >> a >> b;
            for(int i = 0; i < b; i++)
            {
                v[num] = a;
                num++;
            }
            sum += a * b;
        }
        for(int i = 0; i < num; i++)
            for(int j = sum/2; j >= v[i]; j--)
                dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        cout << max(dp[sum/2], sum - dp[sum/2]) << ' ' << min(dp[sum/2], sum - dp[sum/2]) << endl;
    }
    return 0;
}
