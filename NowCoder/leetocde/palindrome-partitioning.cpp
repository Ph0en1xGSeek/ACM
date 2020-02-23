class Solution {
public:
    
    void dfs(string &s, vector<vector<string>> &ans, vector<string> &tmp, int start, vector<vector<bool>> &isPalindrome) {
        if(start == sz) {
            ans.push_back(tmp);
            return;
        }
        for(int i = start; i < sz; ++i) {
            if(isPalindrome[start][i]) {
                tmp.push_back(s.substr(start, i - start + 1));
                dfs(s, ans, tmp, i+1, isPalindrome);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        sz = s.size();
        vector<vector<string>> ans;
        if(sz == 0) {
            return ans;
        }
        vector<vector<bool>> isPalindrome(sz, vector<bool>(sz, false));
        for(int i = 0; i < sz; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(s[i] == s[j] && (i - j <= 1 || isPalindrome[j+1][i-1])) {
                    isPalindrome[j][i] = true;
                }
            }
        }
        vector<string> tmp;
        dfs(s, ans, tmp, 0, isPalindrome);
        return ans;
    }
private:
    int sz;
};