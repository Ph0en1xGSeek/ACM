class Solution {
public:
    double bfs(int from, int to) {
        vector<bool> vis(cnt, false);
        queue<pair<int, double>> q;
        q.push({from, 1.0});
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(cur.first == to) {
                return cur.second;
            }
            for(int i = 0; i < adj[cur.first].size(); ++i) {
                if(!vis[adj[cur.first][i].first]) {
                    vis[adj[cur.first][i].first] = true;
                    q.push({adj[cur.first][i].first, cur.second * adj[cur.first][i].second});
                }
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        for(int i = 0; i < equations.size(); ++i) {
            if(mp.find(equations[i][0]) == mp.end()) {
                mp[equations[i][0]] = cnt++;
                adj.push_back(vector<pair<int, double>>(0));
            }
            if(mp.find(equations[i][1]) == mp.end()) {
                mp[equations[i][1]] = cnt++;
                adj.push_back(vector<pair<int , double>>(0));
            }
            adj[mp[equations[i][0]]].push_back({mp[equations[i][1]], values[i]});
            adj[mp[equations[i][1]]].push_back({mp[equations[i][0]], 1.0 / values[i]});
        }
        for(int i = 0; i < queries.size(); ++i) {
            auto iter_from = mp.find(queries[i][0]);
            auto iter_to = mp.find(queries[i][1]);
            if(iter_from == mp.end() || iter_to == mp.end()) {
                ans.push_back(-1.0);
            }else {
                ans.push_back(bfs(iter_from->second, iter_to->second));
            }
        }
        return ans;
    }
private:
    int cnt;
    unordered_map<string, int> mp;
    vector<vector<pair<int, double>>> adj;
};