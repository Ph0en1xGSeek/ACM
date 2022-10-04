class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int size = rods.size();
        if(size < 2) {
            return 0;
        }
        int tot = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(size, vector<int>(tot+1, 0));
        dp[0][rods[0]] = rods[0];
        int preSum = rods[0];
        for(int i = 1; i < size; ++i) {
            for(int j = 0; j <= preSum + 1; ++j) {
                if(dp[i-1][j] < j) {
                    continue;
                }
                dp[i][j] = max(dp[i-1][j], dp[i][j]);

                int k = j + rods[i];
                dp[i][k] = max(dp[i][k], dp[i-1][j] + rods[i]);

                k = abs(j - rods[i]);
                dp[i][k] = max(dp[i][k], dp[i-1][j] + rods[i]);
            }
            preSum += rods[i];
        }
        return dp[size-1][0] / 2;
    }
};