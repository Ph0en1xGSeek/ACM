class Solution {
public:
    void dfs(string s, char mode, int last, int pos) {
        for(int i = pos, cnt = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == ')') {
                if(s[i] == mode) {
                    ++cnt;
                }else {
                    --cnt;
                }
            }
            if(cnt <= 0) {
                continue;
            } 
            for(int j = last; j <= i; ++j) {
                if(s[j] == mode && (j == last || s[j-1] != mode)) {
                    dfs(s.substr(0, j) + s.substr(j+1), mode, j, i);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if(mode == ')') {
            dfs(s, '(', 0, 0);
            return;
        }
        ret.push_back(s);
    }
    
    vector<string> removeInvalidParentheses(string s) {
        dfs(s, ')', 0, 0);
        return ret;
    }
private:
    vector<string> ret;
};