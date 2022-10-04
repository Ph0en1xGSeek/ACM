class Solution {
public:
    int countArrangement(int N) {
        vector<int> dp((1 << N), 0);
        dp[0] = 1;
        for(int i = 0; i < (1 << N); ++i) {
            int cnt = 0;
            for(int j = 0; j < N; ++j) {
                if(((1 << j) & i) != 0) {
                    ++cnt;
                }
            }
            ++cnt;
            for(int j = 0; j < N; ++j) {
                if(((1 << j) & i) == 0 && ((j+1) % cnt == 0 || cnt % (j+1) == 0)) {
                    dp[i | (1 << j)] += dp[i];
                }
            }
        }
        return dp[(1 << N) - 1];
    }
};