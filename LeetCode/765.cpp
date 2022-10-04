class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
    	int size = row.size();
        vector<vector<int>> adj(size >> 1);
        vector<bool> vis(size >> 1, false);
        for(int i = 0; i < size; i += 2) {
            adj[row[i] >> 1].push_back(row[i+1] >> 1);
            adj[row[i+1] >> 1].push_back(row[i] >> 1);
        }
        int ans = 0;
        for(int i = 0; i < (size >> 1); ++i) {
            if(vis[i]) {
                continue;
            }
            int cur = i;
            int cnt = 0;
            while(vis[cur] == false) {
                ++cnt;
                vis[cur] = true;
                for(int j = 0; j < adj[cur].size(); ++j) {
                    if(vis[adj[cur][j]] == false) {
                        cur = adj[cur][j];
                        break;
                    }
                }
            }
            ans += (cnt - 1);
        }
        return ans;
    }
};
