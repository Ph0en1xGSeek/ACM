#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		if(n == 0) {
			cout << 0 << endl;
            continue;
		}
		vector<int> arr(n + 2, 1);
		for(int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		n += 2;
		vector<vector<int> > dp(n, vector<int>(n, 0));
		for(int i = n - 3; i >= 0; --i) {
			for(int j = i + 2; j < n; ++j) {
				for(int k = i + 1; k < j; ++k) {
					dp[i][j] = max(dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j], dp[i][j]);
				}
			}
		}
		cout << dp[0][n-1];
	}
	return 0;
}