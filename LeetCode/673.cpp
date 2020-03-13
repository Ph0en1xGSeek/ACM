class Solution {
public:
	int findNumberOfLIS(vector<int> &nums) {
		int size = nums.size();
		if(size <= 1) {
			return size;
		}
		vector<int> dp(size, 1);
		vector<int> cnt(size, 1);
		int mx = 1;
		for(int i = 0; i < size; ++i) {
			for(int j = 0; j < i; ++j) {
				if(nums[j] < nums[i]) {
					if(dp[j] + 1 == dp[i]) {
						cnt[i] += cnt[j];
					}else if(dp[j] + 1 >= dp[i]) {
						cnt[i] = cnt[j];
						dp[i] = dp[j] + 1;
					}
				}
			}
			if(dp[i] > mx) {
				mx = dp[i];
			}
		}
		int ans = 0;
		for(int i = 0; i < size; ++i) {
			if(dp[i] == mx) {
				ans += cnt[i];
			}
		}
		return ans;
	}
};