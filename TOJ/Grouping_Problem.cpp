#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int ca;
int arr[20];
int dp[3005];
int main()
{
    int sum;
    while(cin >> ca && ca)
    {
        sum = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= ca; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        for(int i = 1; i <= ca; i++)
            for(int j = sum/2; j >= arr[i]; j--)
                dp[j] = max(dp[j-arr[i]]+arr[i], dp[j]);
        int ans = abs(sum - 2*dp[sum/2]);
        cout << ans << endl;
    }
    return 0;
}
