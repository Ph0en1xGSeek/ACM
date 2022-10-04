class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }
        vector<int> dp(matrix[0].size(), 0);
        int tmp1 = 0, tmp2 = 0;
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    if(j == 0){
                        tmp1 = dp[j];
                        dp[j] = 1;
                    }else{
                        tmp2 = min(tmp1, dp[j]);
                        tmp2 = min(tmp2, dp[j-1]);
                        tmp1 = dp[j];
                        dp[j] = tmp2 + 1;
                    }
                }else{
                    tmp1 = dp[j];
                    dp[j] = 0;
                }
                if(dp[j] >= ans)
                    ans = dp[j];
            }
        }
        return ans * ans;
    }
};