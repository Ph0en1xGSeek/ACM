class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) {
            return vector<int>(0);
        }
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> from(sz), dp(sz, 0), result;
        for(int i = 0; i < sz; ++i) {
            from[i] = i;
        }
        int curMax = 0, curPos = 0;
        for(int i = 1; i < sz; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] % nums[i] != 0) {
                    continue;
                }
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    from[i] = j;
                    if(dp[i] > curMax) {
                        curMax = dp[i];
                        curPos = i;
                    }
                }
            }
        }
        while(from[curPos] != curPos) {
            result.push_back(nums[curPos]);
            curPos = from[curPos];
        }
        result.push_back(nums[curPos]);
        return result;
    }
};