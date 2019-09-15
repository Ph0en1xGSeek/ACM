class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> head(n);
        vector<int> f(n, -1);
        for(int i = 0; i < edges.size(); ++i) {
            head[edges[i][0]].push_back(edges[i][1]);
            head[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int, int>> q;
        q.push(make_pair(-1, 0));
        int last_node;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                pair<int, int> cur = q.front();
                q.pop();
                last_node = cur.second;
                int father = cur.first;
                for(int j = 0; j < head[last_node].size(); ++j) {
                    if(head[last_node][j] == father)
                        continue;
                    q.push(make_pair(last_node, head[last_node][j]));
                }
            }
        }
        
        int cur_node;
        q.push(make_pair(-1, last_node));
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                pair<int, int> cur = q.front();
                q.pop();
                cur_node = cur.second;
                int father = cur.first;
                f[cur_node] = father;
                for(int j = 0; j < head[cur_node].size(); ++j) {
                    if(head[cur_node][j] == father)
                        continue;
                    q.push(make_pair(cur_node, head[cur_node][j]));
                }
            }
        }
        
        vector<int> path;
        while(cur_node != last_node) {
            path.push_back(cur_node);
            cur_node = f[cur_node];
        }
        path.push_back(last_node);
        vector<int> ans;
        if(path.size() % 2 == 1) {
            ans.push_back(path[path.size() / 2]);
        } else {
            ans.push_back(path[path.size() / 2]);
            ans.push_back(path[path.size() / 2 - 1]);
        }
        return ans;
    }
};