#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int num;
	cin >> num;
	vector<int> arr(num+1, 0);
	vector<vector<int>> dp(num, vector<int>(num, INT_MAX));
	for(int i = 1; i <= num; ++i) {
		cin >> arr[i];
	}
	for(int i = 0; i < num; ++i) {
		dp[i][i] = 0;
	}
	for(int i = 1; i <= num; ++i) {
		arr[i] = arr[i-1] + arr[i];
	}
	for(int i = 1; i < num; ++i) {
		for(int j = 0; j + i < num; ++j) {
			for(int k = j; k < j + i; ++k) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k+1][j+i] + arr[k+1] - arr[j] + arr[j+i+1] - arr[k+1]);
			}
		}
	}
	cout << dp[0][num-1] << endl;
	return 0;
}
