#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int n, k;
	const int INT_MAX = 0x7fffffff;
	while(cin >> n >> k) {
		if(n == 0) {
			continue;
		}
		vector<int> weight(n, 0);
		for(int i = 0; i < n; ++i) {
			cin >> weight[i];
		}
		vector<int> dp(k+1, INT_MAX);
		dp[0] = 0;
		for(int i = 1; i <= k; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i >= weight[j] && dp[i - weight[j]] != INT_MAX) {
					dp[i] = min(dp[i], dp[i - weight[j]] + 1);
				}
			}
		}
		if(dp[k] == INT_MAX) {
			cout << -1 << endl;
		}else {
			cout << dp[k] << endl;
		}
	}
	return 0;
}