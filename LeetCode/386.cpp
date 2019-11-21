class Solution {
public:
    void dfs(int from, int n, vector<int> &ans) {
        if(from > n) {
            return;
        }
        if(from == 1) {
            for(int i = 1; i <= 9; ++i) {
                if(i <= n) {
                    ans.push_back(i);
                    dfs(i * 10, n, ans);
                }
            }
        } else {
            for(int i = 0; i <= 9; ++i) {
                if(from + i <= n) {
                    ans.push_back(from + i);
                    dfs((from + i) * 10, n, ans);
                }
            }
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        if(n < 1) {
            return ans;
        }
        dfs(1, n, ans);
        return ans;
    }
};