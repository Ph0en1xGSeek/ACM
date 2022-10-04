//DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        unordered_set word_set(wordDict.begin(), wordDict.end());
        vector<int> dp(len+1, false);
        dp[0] = true;
        for(int i = 1; i <= len; i++){
            for(int j = 0; j <= i; j++){
                if(dp[j] && word_set.count(s.substr(j, i-j)) != 0){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

// memmorized search
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        sz = s.size();
        bool res = dfs(s, dict, 0);
        return res;
    }
    
    bool dfs(string &s, unordered_set<string> &dict, int start) {
        if(mem.find(start) != mem.end()) {
            return false;
        }
        if(start == sz) {
            return true;
        }
        for(int i = start+1; i <= sz; ++i) {
            if(dict.find(s.substr(start, i - start)) != dict.end() && dfs(s, dict, i)) {
                return true;
            }
        }
        mem.insert(start);
        return false;
    }
private:
    int sz;
    unordered_set<int> mem;
};