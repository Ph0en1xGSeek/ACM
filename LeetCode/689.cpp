class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
		int size = nums.size();
		vector<int> ans(3, 0);
		if(size < k * 3) {
			return ans;
		}
		vector<vector<int>> dp(3, vector<int>(size, 0));
		vector<vector<int>> pre(2, vector<int>(size, -1));
		int mx = 0;
		int sum = 0;
		int mx_pos;
		for(int j = size-1; j > size-k; --j) {
			sum += nums[j];
		}
		for(int j = size - k; j >= 0; --j) {
			sum += nums[j];
			dp[0][j] = sum;
			sum -= nums[j+k-1];
		}
		for(int i = 1; i < 3; ++i) {
			mx = 0;
			mx_pos = 0;
			for(int j = i * k; j < size-k+1; ++j) {
				if(dp[i - 1][j - k] > mx) {
					mx = dp[i - 1][j - k];
					mx_pos = j - k;
				}
				dp[i][j] = dp[0][j] + mx;
				pre[i-1][j] = mx_pos;
			}
		}
		mx_pos = 0;
		mx = dp[2][0];
		for(int i = 2 * k; i < size - k + 1; ++i) {
			if(dp[2][i] > mx) {
				mx_pos = i;
				mx = dp[2][i];
			}
		}
		for(int i = 2; i >= 0; --i) {
			ans[i] = mx_pos;
			if(i > 0)
				mx_pos = pre[i-1][mx_pos];
		}
		return ans;
	}
};