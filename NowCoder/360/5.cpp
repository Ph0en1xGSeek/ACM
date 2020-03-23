#include <iostream>
#include <vector>
 
using namespace std;
 
const int mod = 772235;
 
int main() {
    int n, k;
    cin >> n >> k;
    if(n < k) {
        cout << 0 << endl;
    }else if(n == k) {
        int ans = 1;
        for(int i = 2; i <= k; ++i) {
            ans = ans * i % mod;
        }
        cout << ans << endl;
    }else {
        vector<int> dp(k, 0);
        dp[0] = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = min(i,k-1); j > 0; --j) {
                dp[j] = (dp[j] + dp[j-1]) % mod * (j+1) % mod;
            }
        }
        cout << dp[k-1] << endl;
    }
    return 0;
}