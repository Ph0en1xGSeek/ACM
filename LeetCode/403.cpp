class Solution {
public:
    bool canCross(vector<int>& stones) {
        int sz = stones.size();
        vector<int> dp(sz, 0);
        vector<unordered_set<int>> jump(sz);
        jump[0].insert(0);
        int k = 0;
        for(int i = 1; i < sz; ++i) {
            while(dp[k] + 1 < stones[i] - stones[k])
                ++k;
            for(int j = k; j < i; ++j) {
                int dis = stones[i] - stones[j];
                if(jump[j].find(dis - 1) != jump[j].end() || jump[j].find(dis) != jump[j].end() || jump[j].find(dis + 1) != jump[j].end()) {
                    jump[i].insert(dis);
                    dp[i] = max(dp[i], dis);
                }
            }
        }
        return dp[sz-1] > 0;
    }
};