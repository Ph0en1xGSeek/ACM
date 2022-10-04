class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void dfs(string& s, vector<vector<string>>& res, vector<string>& ans, int from){
        if(from == s.length()){
            res.push_back(ans);
            return;
        }
        for(int i = 0; from + i < s.length(); i++){
            if(isPalindrome(s, from, from+i)){
                ans.push_back(s.substr(from, i+1));
                dfs(s, res, ans, from+i+1);
                ans.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        dfs(s, res, ans, 0);
        return res;
    }
};