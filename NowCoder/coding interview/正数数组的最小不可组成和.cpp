#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n;
	const int MAX_INT = 0x7fffffff;
	while(cin >> n) {
		vector<int> num(n);
		int mi = MAX_INT;
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			cin >> num[i];
			mi = min(mi, num[i]);
			sum += num[i];
		}
		vector<bool> dp(sum, false);
		dp[0] = true;
		for(int i = 0; i < n; ++i) {
			for(int j = sum; j >= num[i]; --j) {
				if(dp[j] || dp[j - num[i]]) {
					dp[j] = true;
				}
			}
		}
		int i;
		for(i = mi; i <= sum; ++i) {
			if(dp[i] == false) {
				break;
			}
		}
		cout << i << endl;
	}
	return 0;
}