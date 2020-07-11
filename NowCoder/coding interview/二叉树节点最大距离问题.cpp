#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, root;
    cin >> n >> root;
    vector<vector<int>> adj(n + 1);
    vector<bool> visit(n + 1, false);
    int a, b, c;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        if(b != 0) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(c != 0) {
            adj[a].push_back(c);
            adj[c].push_back(a);
        }
    }
    int dis = 0;
    int cur = root;
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();
            int adj_size = adj[cur].size();
            for(int j = 0; j < adj_size; ++j) {
                if(!visit[adj[cur][j]]) {
                    visit[adj[cur][j]] = true;
                    q.push(adj[cur][j]);
                }
            }
        }
    }
    
    q.push(cur);
    visit.assign(n+1, false);
    while(!q.empty()) {
        int size = q.size();
        ++dis;
        for(int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();
            int adj_size = adj[cur].size();
            for(int j = 0; j < adj_size; ++j) {
                if(!visit[adj[cur][j]]) {
                    visit[adj[cur][j]] = true;
                    q.push(adj[cur][j]);
                }
            }
        }
    }
    cout << dis << endl;
    
    return 0;
}