#include <iostream>
#include <cstring>

using namespace std;
double p[130][130];
double dp[130][130];
int main()
{
    int num;
    while(cin >> num && num != -1)
    {
        for(int i = 0; i < (1 << num); i++)
            for(int j = 0; j < (1 << num); j++)
                cin >> p[i][j];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < (1 << num); i++)
            dp[0][i] = 1;
        for(int i = 1; i <= num; i++)
            for(int j = 0; j < (1 << num); j++)
                for(int k = 0; k < (1 << num); k++)
                    if((k >> (i-1)^1) == (j >> (i - 1)))
                        dp[i][j] += dp[i-1][j]*dp[i-1][k]*p[j][k];
        int ans = 0;
        for(int i = 0; i < (1 << num); i++)
            if(dp[num][i] > dp[num][ans])
                ans = i;
        cout << ans+1 << endl;
    }

    return 0;
}
