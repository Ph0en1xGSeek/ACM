class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        int sz = words.size();
        if(sz <= 1) {
            return res;
        }
        for(int i = 0; i < sz; ++i) {
            int word_sz = words[i].size();
            vector<bool> dp(word_sz + 1, false);
            dp[0] = true;
            for(int j = 0; j < word_sz; ++j) {
                if(!dp[j]) {
                    continue;
                }
                for(int k = j+1; k <= word_sz; ++k) {
                    if(k - j != word_sz && dict.find(words[i].substr(j, k-j)) != dict.end()) {
                        dp[k] = true;
                    }
                }
                if(dp[word_sz] == true) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};