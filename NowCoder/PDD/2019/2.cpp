#include <iostream>
#include <vector>

using namespace std;

bool check(int left, vector<int> &trees) {
    int size = trees.size();
    for(int i = 0; i < size; ++i) {
        if(trees[i] > (left + 1) / 2) {
            return false;
        }
    }
    return true;
}

bool dfs(int pos, vector<int> &trees, int n, int m, vector<int> &ans) {
    if(pos == m) {
        return true;
    }
    if(!check(m - pos, trees)) {
        return false;
    }
    for(int i = 0; i < n; ++i) {
        if(pos == 0 || (trees[i] > 0 && i + 1 != ans[pos - 1])) {
            --trees[i];
            ans[pos] = i + 1;
            if(dfs(pos + 1, trees, n, m, ans))
                return true;
            ans[pos] = -1;
            ++trees[i];
        }
    }
    return false;
}

int main() {
    int n, m;
    while(cin >> n) {
        vector<int> trees(n);
        m = 0;
        for(int i = 0; i < n; ++i) {
            cin >> trees[i];
            m += trees[i];
        }
        vector<int> ans(m, -1);
        dfs(0, trees, n, m, ans);
        if(ans[0] == -1) {
            cout << "-" << endl;
        }else {
            for(int i = 0; i < m; ++i) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}