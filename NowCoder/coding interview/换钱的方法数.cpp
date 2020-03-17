#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {
	int n, k;
	const int MOD = 1000000007;
	while(cin >> n >> k) {
		vector<int> nums(n);
		for(int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		vector<int> dp(k+1, 0);
        dp[0] = 1;
		for(int j = 0; j < n; ++j) {
		    for(int i = 1; i <= k; ++i) {
				if(i - nums[j] >= 0) {
					dp[i] = (dp[i] + dp[i - nums[j]]) % MOD;
				}
			}
		}
		cout << dp[k] << endl;
	}
	return 0;
}