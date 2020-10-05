#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>

using namespace std;
double dp[1005][1005];

int main()
{
    int n, s;
    while(cin >> n >> s)
    {
        memset(dp, 0, sizeof(dp));
        for(int i = n; i >= 0; i--)
        {
            for(int j = s; j >= 0; j--)
            {
                if(i == n && j == s)
                    continue;
                double a = ((double(s-j)*i)/n/s);
                double b = ((double(n-i)*j)/n/s);
                double c = ((double(n-i)*(s-j))/n/s);
                double d = 1.0-(double(i*j))/n/s;
                dp[i][j] = a*dp[i][j+1] + b*dp[i+1][j] + c*dp[i+1][j+1] + 1;
                dp[i][j] /= d;
            }
        }
        cout << setprecision(4) << fixed << dp[0][0] << endl;
    }

    return 0;
}
