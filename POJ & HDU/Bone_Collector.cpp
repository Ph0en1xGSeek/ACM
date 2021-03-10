#include <iostream>
#include <cstring>

using namespace std;
int ca, num, volum;
int w[1005];
int d[1005];
int dp[1005];


int main()
{
    cin >> ca;
    while(ca--)
    {
        cin >> num >> volum;
        for(int i = 1; i <= num; i++)
            cin >> d[i];
        for(int i = 1; i <= num; i++)
            cin >> w[i];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= num; i++)
            for(int j = volum; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
        cout << dp[volum] << endl;
    }
    return 0;
}
