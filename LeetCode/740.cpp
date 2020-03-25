class Solution {
public:
	int deleteAndEarn(vector<int> &nums) {
		int size = nums.size();
		if(size == 0) {
			return 0;
		}
		vector<int> cnt(10001, 0);
        int mx = -1;
		for(int i = 0; i < size; ++i) {
			++cnt[nums[i]];
            mx = max(mx, nums[i]);
		}
		vector<int> dp(mx + 1, 0);
		dp[0] = 0;
		dp[1] = cnt[1];
		for(int i = 2; i <= mx; ++i) {
			dp[i] = max(dp[i-2] + cnt[i] * i, dp[i-1]);
		}
		return dp[mx];
	}
};