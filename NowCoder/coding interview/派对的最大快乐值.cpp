#include <iostream>
#include <vector>

using namespace std;

int dfs(int root, int go, vector<vector<int>> &children, vector<int> &score, vector<vector<int>> &memo) {
    if(memo[root][go] >= 0) {
        return memo[root][go];
    }
    int tot = 0;
    if(go == 1) {
        tot = score[root];
    }
    int ch_size = children[root].size();
    for(int i = 0; i < ch_size; ++i) {
        if(go == 1) {
            tot += dfs(children[root][i], 0, children, score, memo);
        }else {
            tot += max(dfs(children[root][i], 0, children, score, memo),
                      dfs(children[root][i], 1, children, score, memo));
        }
    }
    return memo[root][go] = tot;
}

int main() {
    int n, root;
    cin >> n >> root;
    vector<int> score(n+1);
    score[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> score[i];
    }
    vector<vector<int>> children(n+1, vector<int>());
    int u, v;
    for(int i = 1; i <= n-1; ++i) {
        cin >> u >> v;
        children[u].push_back(v);
    }
    vector<vector<int>> memo(n+1, vector<int>(2, -1));
    cout << max(dfs(root, 0, children, score, memo), dfs(root, 1, children, score, memo)) << endl;
    return 0;
}