class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n == 1 || t == 0) {
            if(target == 1) {
                return 1.0;
            }else {
                return 0.0;
            }
        }
        vector<vector<int>> arr(n+1);
        for(auto edge: edges) {
            arr[edge[0]].push_back(edge[1]);
            arr[edge[1]].push_back(edge[0]);
        }
        double ans = 0.0;
        vector<bool> visit(n+1, false);
        visit[1] = true;
        dfs(arr, visit, t, 1, target, 1.0, ans);
        return ans;
    }
    
    void dfs(vector<vector<int>> &arr, vector<bool> &visit, int t, int cur, int target, double pro, double &ans) {
        if(t == 0) {
            if(cur == target) {
                ans += pro;
            }
            return;
        }
        int size = arr[cur].size();
        int cnt = 0;
        for(int i = 0; i < size; ++i) {
            if(!visit[arr[cur][i]]) {
                ++cnt;
            }
        }
        if(cnt == 0) {
            if(cur == target) {
                ans += pro;
            }
            return;
        }
        for(int i = 0; i < size; ++i) {
            if(!visit[arr[cur][i]]) {
                visit[arr[cur][i]] = true;
                dfs(arr, visit, t-1, arr[cur][i], target, pro / cnt, ans);
                visit[arr[cur][i]] = false;
            }
        }
    }
};