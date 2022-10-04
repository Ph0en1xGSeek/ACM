class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();
        vector<long long> sum(sz+1, 0);
        vector<vector<long long>> dp(m+1, vector<long long>(sz+1, INT_MAX));
        for(int i = 1; i <= sz; ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        dp[0][0] = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= sz; ++j) {
                for(int k = i-1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[i-1][k], sum[j] - sum[k]));
                }
            }
        }
        return dp[m][sz];
    }
};