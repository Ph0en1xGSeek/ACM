class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(n == 0 || src == dst) {
            return 0;
        }
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));
        vector<vector<pair<int, int>>> adj(n);
        int size = flights.size();
        for(int i = 0; i < size; ++i) {
            adj[flights[i][1]].push_back({flights[i][0], flights[i][2]});
        }
        dp[0][src] = 0;
        int ans = INT_MAX;
        int cur = 0;
        for(int i = 0; i < K+1; ++i) {
            cur = 1 - cur;
            for(int j = 0; j < n; ++j) {
                size = adj[j].size();
                for(int k = 0; k < size; ++k) {
                    if(dp[1-cur][adj[j][k].first] != INT_MAX) {
                        dp[cur][j] = min(dp[cur][j], dp[1-cur][adj[j][k].first] + adj[j][k].second);
                    }
                }
            }
            ans = min(ans, dp[cur][dst]);
        }
        if(ans == INT_MAX) {
            return -1;
        }else {
            return ans;
        }
    }
};