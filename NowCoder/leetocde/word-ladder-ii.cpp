class Solution {
public:    
    void dfs(vector<string> &path,
            vector<vector<string>> &res,
            unordered_map<string, vector<string>> &pre,
            string &beginWord,
            string cur) {
        path.push_back(cur);
        if(cur == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        for(int i = 0; i < pre[cur].size(); ++i) {
            dfs(path, res, pre, beginWord, pre[cur][i]);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if(dict.find(endWord) == dict.end()) {
            return res;
        }
        int sz = beginWord.size();
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> step;
        step[beginWord] = 1;
        unordered_map<string, vector<string>> pre;
        int cur_layer = 1;
        bool found = false;
        while(!q.empty() && !found) {
            int layer_size = q.size();
            ++cur_layer;
            for(int k = 0; k < layer_size; ++k) {
                string cur = q.front();
                string cur_word = cur;
                q.pop();
                for(int i = 0; i < sz; ++i) {
                    char tmp = cur[i];
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        cur[i] = ch;
                        if(dict.find(cur) != dict.end() && 
                           (step.find(cur) == step.end() || step[cur] == cur_layer)) {
                            pre[cur].push_back(cur_word);
                            if(step.find(cur) == step.end()) {
                                step[cur] = cur_layer;
                                if(cur == endWord) {
                                    found = true;
                                }else {
                                    q.push(cur);
                                }
                            }
                        }
                    }
                    cur[i] = tmp;
                }
            }
        }
        if(!found) {
            return res;
        }else {
            vector<string> path;
            dfs(path, res, pre, beginWord, endWord);
            return res;
        }
        
    }
};