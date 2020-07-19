class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        int size = box.size();
        sort(box.begin(), box.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        vector<int> dp(size, 0);
        dp[0] = box[0][2];
        int mx = 0;
        int res = dp[0];
        for(int i = 1; i < size; ++i) {
            mx = 0;
            for(int j = 0; j < i; ++j) {
                if(box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2]) {
                    mx = max(mx, dp[j]);
                }
            }
            dp[i] = mx + box[i][2];
            res = max(res, dp[i]);
        }
        return res;
    }
};