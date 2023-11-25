class Solution {
private:
    vector<vector<bool> > dp;
    vector<vector<string> > ret;
    vector<string> ans;

    int n;

public:
    void dfs(string &s, int pos) {
        if (pos == n) {
            ret.push_back(ans);
            return;
        }
        for (int j = pos; j < n; ++j) {
            if (dp[pos][j]) {
                ans.push_back(s.substr(pos, j - pos + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string &s) {
        n = s.length();
        dp.assign(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        dfs(s, 0);
        return ret;
    }
};