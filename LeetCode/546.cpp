class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int size = boxes.size();
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(size + 1, vector<int>(size + 1, -1)));
        return dfs(boxes, dp, 0, size - 1, 0);
    }
    int dfs(vector<int> &boxes, vector<vector<vector<int>>> &dp, int l, int r, int k) {
        if(l > r) {
            return 0;
        }
        while(l < r && boxes[r-1] == boxes[r]) {
            --r;
            ++k;
        }
        if(dp[l][r][k] >= 0) {
            return dp[l][r][k];
        }
        dp[l][r][k] = dfs(boxes, dp, l, r-1, 0) + (k + 1) * (k + 1);
        for(int i = l; i < r; ++i) {
            if(boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k], dfs(boxes, dp, l, i, k + 1) + dfs(boxes, dp, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
};