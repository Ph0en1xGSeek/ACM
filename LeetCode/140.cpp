class Solution {
public:
    unordered_map<string, vector<string>> memory;
    vector<string> dfs(string s, unordered_set<string>& wordDict){
        if(memory.count(s) != 0){
            return memory[s];
        }
        vector<string> res;
        if(wordDict.count(s) != 0){
            res.push_back(s);
        }
        for(int i = 1; i < s.length(); i++){
            string word = s.substr(i);
            if(wordDict.count(word) != 0){
                vector<string> pre = dfs(s.substr(0, i), wordDict);
                for(int j = 0; j < pre.size(); j++){
                    res.push_back(pre[j] + " " + word);
                }
            }
        }
        memory[s] = res;
        return res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> res = dfs(s, wordSet);
        return res;
    }
};